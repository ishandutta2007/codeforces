#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long double ld;

vector<int> g[101010];

int apd[101010];
int c[101010];

vector<pair<int, ld> > dd[101010];

void dfs1(int x, int p, int co){
	c[x]=co;
	for (int nx:g[x]){
		if (nx!=p){
			dfs1(nx, x, co);
			apd[x]=max(apd[x], apd[nx]+1);
		}
	}
}

void dfs2(int x, int p, int co, int ud){
	dd[co].push_back({max(ud, apd[x]), 0});
	int mau=ud;
	int mav=0;
	int mau2=0;
	for (int nx:g[x]){
		if (nx!=p){
			if (apd[nx]+1>mau){
				mau2=mau;
				mau=apd[nx]+1;
				mav=nx;
			}
			else if(apd[nx]+1>mau2){
				mau2=apd[nx]+1;
			}
		}
	}
	
	for (int nx:g[x]){
		if (nx!=p){
			if (nx==mav){
				dfs2(nx, x, co, mau2+1);
			}
			else{
				dfs2(nx, x, co, mau+1);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for (int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i=1;i<=n;i++){
		if (c[i]==0){
			dfs1(i, 0, i);
			dfs2(i, 0, i, 0);
			sort(dd[i].begin(), dd[i].end());
			ld su=0;
			for (int j=(int)dd[i].size()-1;j>=0;j--){
				su+=(ld)dd[i][j].F;
				dd[i][j].S=su;
			}
		}
	}
	map<pair<int, int>, ld> qs;
	cout<<setprecision(15);
	for (int qq=0;qq<q;qq++){
		int a,b;
		cin>>a>>b;
		a=c[a];
		b=c[b];
		if (a==b){
			cout<<"-1\n";
		}
		else{
			if (qs.count(minmax(a, b))){
				cout<<qs[minmax(a, b)]<<'\n';
			}
			else{
				if (dd[a].size()>dd[b].size()) swap(a, b);
				ld su=0;
				int mdi=max(dd[a].back().F, dd[b].back().F);
				for (auto t:dd[a]){
					int mi=0;
					int ma=dd[b].size()-1;
					int f=dd[b].size();
					while (mi<=ma){
						int mid=(mi+ma)/2;
						if (dd[b][mid].F>mdi-t.F-1){
							f=mid;
							ma=mid-1;
						}
						else{
							mi=mid+1;
						}
					}
					su+=(ld)f*mdi;
					if (f<(int)dd[b].size()){
						su+=dd[b][f].S;
						su+=(ld)((int)dd[b].size()-f)*(ld)(1+t.F);
					}
				}
				ld ans=su/((ld)dd[a].size()*(ld)dd[b].size());
				qs[minmax(a, b)]=ans;
				cout<<ans<<'\n';
			}
		}
	}
}