
#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll m;
int u[202020];

int gs(ll x){
	memset(u, 0, sizeof(u));
	int s=0;
	ll xx=x;
	while (u[xx]==0){
		u[xx]=1;
		xx*=x;
		xx%=m;
		s++;
	}
	return s;
}

int used[202020];
int fb[202020];

int asd[202020];

int sz[202020];
int dp[202020];
int fr[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	cin>>m;
	for (int i=0;i<n;i++){
		int x;
		cin>>x;
		fb[x]=1;
	}
	if (m==1){
		if (fb[0]){
			cout<<0<<endl;
		}
		else{
			cout<<1<<endl<<0<<endl;
		}
		return 0;
	}
	vector<ll> divs;
	for (ll i=1;i<=m;i++){
		if (m%i==0&&i>1) divs.push_back(i);
		if (!fb[i]&&i<m) sz[__gcd(i, m)]++;
	}
	for (int i=1;i<=m;i++){
		fr[i]=i;
	}
	for (ll i=1;i<=m;i++){
		dp[i]+=sz[i];
		for (ll d:divs){
// 			cout<<i<<" "<<dp[i]<<" "<<d<<" "<<i*d<<endl;
			if (i*d<=m&&m%(i*d)==0){
				if (dp[i]>dp[i*d]) {
					dp[i*d]=dp[i];
					fr[i*d]=d;
				}
			}
			if (i*d>m) break;
		}
	}
	if (!fb[0]) dp[m]++;
	vector<ll> divadd;
	int st=m;
// 	cout<<sz[1]<<" "<<sz[2]<<" "<<dp[1]<<" "<<dp[2]<<endl;
	while (st>1){
// 		cout<<st<<" "<<dp[st]<<endl;
		divadd.push_back(st);
		st/=fr[st];
	}
	reverse(divadd.begin(), divadd.end());
	int nadd=0;
	vector<ll> ans;
	int cop=1;
	ll num=1;
	ll spg=1;
	while (1){
		ll f=0;
		if (cop){
			for (ll i=2;i<m;i++){
				if (__gcd(i, m)==1&&!used[(num*i)%m]&&(num*i)%m>0){
					f=i;
					break;
				}
			}
		}
		if (!f){
			cop=0;
			while (nadd<(int)divadd.size()){
				spg=divadd[nadd];
// 				cout<<"add "<<divadd[nadd]<<endl;
				for (ll i=2;i<m;i++){
					if (__gcd((num*i)%m, m)==spg&&!used[(num*i)%m]&&(num*i)%m>0){
						f=i;
						break;
					}
				}
				if (!f) nadd++;
				else break;
			}
		}
		if (!f) break;
		while (!used[(num*f)%m]&&(num*f)%m>0&&__gcd((num*f)%m, m)==spg){
// 			cout<<f<<" "<<(num*f)%m<<endl;
			used[(num*f)%m]=1;
			ans.push_back(f);
			num=(num*f)%m;
		}
	}
	vector<ll> rans;
	if (!used[1]&&!fb[1]){
		rans.push_back(1);
	}
	num=1;
	ll mul=1;
	for (ll t:ans){
		num=(num*t)%m;
		mul=(mul*t)%m;
		if (fb[num]) {
			continue;
		}
		rans.push_back(mul);
		mul=1;
	}
	if (!fb[0]) rans.push_back(0);
	assert((int)rans.size()==dp[m]);
	cout<<rans.size()<<endl;
	ll pp=1;
	for (ll x:rans){
		cout<<x<<" ";
		pp*=x;
		pp%=m;
// 		cout<<"pp "<<pp<<endl;
		assert(asd[pp]==0);
		assert(fb[pp]==0);
	}
	cout<<endl;
}