#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, x;

ll a[5050];
ll b[5050];

ll dp[2][10101];
ll p[5050][2];

ll inf=1e16;

int main() {
	cin >> n >> x;
	set<ll> cset;
	cset.insert(x);
	for (int i = 0; i < n; i++) {
		cin >> p[i][0] >> p[i][1];
		cset.insert(p[i][0]);
		cset.insert(p[i][1]);
	}
	vector<ll> cs;
	for (ll xx:cset){
		cs.push_back(xx);
	}
	for (int i=0;i<2;i++){
		for (int ii=0;ii<10101;ii++){
			dp[i][ii]=inf;
		}
	}
	for (int i=0;i<(int)cs.size();i++){
		if (cs[i]==x){
			dp[0][i]=0;
		}
	}
	for (int i=0;i<n;i++){
		for (int ii=0;ii<(int)cs.size();ii++){
			//cout<<i<<" "<<ii<<" "<<dp[i%2][ii]<<" "<<cs[ii]<<endl;
			dp[(i+1)%2][ii]=inf;
		}
		
		for (int ii=0;ii<(int)cs.size();ii++){
			dp[i%2][ii+1]=min(dp[i%2][ii+1], dp[i%2][ii]+abs(cs[ii]-cs[ii+1]));
		}
		for (int ii=(int)cs.size()-1;ii>0;ii--){
			dp[i%2][ii-1]=min(dp[i%2][ii-1], dp[i%2][ii]+abs(cs[ii]-cs[ii-1]));
		}
		for (int ii=0;ii<(int)cs.size();ii++){
			ll co=0;
			if (cs[ii]>=p[i][0]&&cs[ii]<=p[i][1]){
				co=0;
			}
			else{
				co=min(abs(cs[ii]-p[i][0]), abs(cs[ii]-p[i][1]));
			}
			dp[(i+1)%2][ii]=min(dp[(i+1)%2][ii], dp[i%2][ii]+co);
		}
	}
	ll v=inf;
	for (int i=0;i<(int)cs.size();i++){
		v=min(v, dp[n%2][i]);
	}
	cout<<v<<endl;
}