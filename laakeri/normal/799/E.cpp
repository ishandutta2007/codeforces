#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const ll inf=1e18;

int al[202020];
int bl[202020];
ll c[202020];

const int N=1<<18;
int st1[2*N];
ll st2[2*N];

vector<ll> cc;

void add(int i, int a, ll b){
	for (i+=N;i;i/=2){
		st1[i]+=a;
		st2[i]+=b;
	}
}

ll bs(int i, int k){
	if (k>st1[i]) return inf;
	if (k<=0) return 0;
	if (i>=N){
		return (ll)k*cc[i-N];
	}
	if (st1[i*2]>=k){
		return bs(i*2, k);
	}
	else{
		return st2[i*2]+bs(i*2+1, k-st1[i*2]);
	}
}

void av(ll v){
	int id=lower_bound(cc.begin(), cc.end(), v)-cc.begin();
	add(id, 1, v);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,k;
	cin>>n>>m>>k;
	for (int i=1;i<=n;i++){
		cin>>c[i];
		cc.push_back(c[i]);
	}
	sort(cc.begin(), cc.end());
	cc.erase(unique(cc.begin(), cc.end()), cc.end());
	int aaa;
	cin>>aaa;
	for (int i=0;i<aaa;i++){
		int x;
		cin>>x;
		al[x]=1;
	}
	int bbb;
	cin>>bbb;
	for (int i=0;i<bbb;i++){
		int x;
		cin>>x;
		bl[x]=1;
	}
	vector<ll> bo;
	vector<ll> a;
	vector<ll> b;
	for (int i=1;i<=n;i++){
		if (al[i]&&bl[i]) bo.push_back(c[i]);
		else if(al[i]) a.push_back(c[i]);
		else if(bl[i]) b.push_back(c[i]);
		else av(c[i]);
	}
	ll ans=inf;
	sort(bo.begin(), bo.end());
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	vector<ll> pas,pbs;
	for (int i=0;i<(int)a.size();i++){
		if (i==0) pas.push_back(a[i]);
		else pas.push_back(pas.back()+a[i]);
	}
	for (int i=0;i<(int)b.size();i++){
		if (i==0) pbs.push_back(b[i]);
		else pbs.push_back(pbs.back()+b[i]);
	}
	
	ll boc=0;
	for (int i=0;i<=(int)bo.size();i++){
		if (i>0) boc+=bo[i-1];
		if (i>m) break;
		int t=k-i;
		if (t<0) t=0;
		
		if (t*2+i>m) continue;
		if (t>(int)a.size()) continue;
		if (t>(int)b.size()) continue;
		
		while ((int)a.size()>t){
			av(a.back());
			pas.pop_back();
			a.pop_back();
		}
		while ((int)b.size()>t){
			av(b.back());
			pbs.pop_back();
			b.pop_back();
		}
		
		ll p1=0;
		ll p2=0;
		
		if (t>0) p1=pas.back();
		if (t>0) p2=pbs.back();
		
		int ex=m-i-t*2;
		
		ans=min(ans, boc+p1+p2+bs(1, ex));
	}
	
	if (ans>=inf){
		cout<<-1<<endl;
	}
	else{
		cout<<ans<<endl;
	}
}