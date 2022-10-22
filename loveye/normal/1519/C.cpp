#include<bits/stdc++.h>
using namespace std;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define LL long long
#define I inline void
const int N = 2e5 + 5;
int n,t,a[N],c[N],u[N];
vector<int> v;
vector<LL> val[N],sum[N];
bool vis[N];
int main() {
	cin >> t;
	while(t--) {
		cin >> n;
		v.clear();
		fr(i,1,n) {
			c[i] = 0,vis[i] = 0;
			val[i].clear();
			sum[i].clear();
		}
		fr(i,1,n) {
			cin >> u[i];
			++c[u[i]];
		}
		fr(i,1,n) if(c[i] && !vis[c[i]]) v.push_back(c[i]),vis[c[i]] = 1;
		
		LL ans = 0;
		fr(i,1,n) {
			cin >> a[i];
			ans += a[i];
			val[u[i]].push_back(a[i]);
		}
		fr(i,1,n) sort(val[i].begin(),val[i].end());
		fr(i,1,n) if(c[i]) {
			if(!sum[c[i]].size()) sum[c[i]].resize(c[i]+1);
			fr(j,1,c[i]) sum[c[i]][j] += val[i][j-1];
		}
		//cout << sum[3][1] << ' ' << sum[3][2] << ' ' << sum[3][3] <<endl;
		//cout << sum[4][1] << ' ' << sum[4][2] << ' ' << sum[4][3] <<endl;
		fo(i,0,v.size()) fr(j,1,v[i]) sum[v[i]][j] += sum[v[i]][j-1];
		//cout << sum[3][1] << ' ' << sum[3][2] << ' ' << sum[3][3] <<endl;
		//cout << sum[4][1] << ' ' << sum[4][2] << ' ' << sum[4][3] <<endl;
		//cout <<v.size() <<endl;
		fr(k,1,n) {
			LL res = ans;
			fo(i,0,v.size())
				res -= sum[v[i]][v[i] % k];
			cout << res << ' ';
		}
		cout << endl;
	}
	return 0;
}