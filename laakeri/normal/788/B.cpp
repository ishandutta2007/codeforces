#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> g[1010101];
int u[1010101];

int hl[1010101];

int dfs1(int x){
	if (u[x]) return 0;
	u[x]=1;
	int r=hl[x];
	for (int nx:g[x]){
		r+=dfs1(nx);
		if (nx>x) r++;
	}
	return r;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if (m<=1){
		cout<<0<<endl;
		return 0;
	}
	ll loops=0;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		if (a==b){
			hl[a]++;
			loops++;
		}
		else{
			g[a].push_back(b);
			g[b].push_back(a);
		}
	}
	int r=0;
	for (int i=1;i<=n;i++){
		if ((int)g[i].size()>0||hl[i]){
			r=i;
			int mm=dfs1(i);
			if (mm!=m){
				cout<<0<<endl;
				return 0;
			}
			break;
		}
	}
	ll nloop=m-loops;
	ll v=loops*(loops-1ll)/2;
	v+=loops*nloop;
	
	ll touch=0;
	for (int i=1;i<=n;i++){
		touch+=(ll)g[i].size()*((ll)g[i].size()-1)/2ll;
	}
	ll ntouch=nloop*(nloop-1ll)/2-touch;
	
	v+=touch;
	cout<<v<<endl;
}