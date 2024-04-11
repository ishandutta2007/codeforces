#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[202020];

int k;

ll v=0;

vector<pair<ll, ll> > dfs(int x, int p){
	vector<pair<ll, ll> > t(k);
	t[0]={1, 0};
	for (int nx:g[x]){
		if (nx!=p){
			auto a=dfs(nx, x);
			for (int i=0;i<k;i++){
			for (int ii=0;ii<k;ii++){
				ll prs=t[i].F*a[ii].F;
				ll dsu=t[i].S*a[ii].F+t[i].F*a[ii].S;
				v+=dsu;
				ll dmo=(i+ii)%k;
				if (dmo!=0) v+=((ll)k-dmo)*prs;
			}
			}
			for (int i=0;i<k;i++){
				t[i].F+=a[i].F;
				t[i].S+=a[i].S;
			}
		}
	}
		
	vector<pair<ll, ll> > nt(k);
	for (int i=0;i<k;i++){
		nt[(i+1)%k]={t[i].F, t[i].S+t[i].F};
	}
	return nt;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>k;
	for (int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(1, 0);
	cout<<v/(ll)k<<endl;
}