#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int g[202020];
int u[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>g[i];
	}
	vector<vector<int> > cyc;
	vector<int> c1;
	for (int i=1;i<=n;i++){
		if (u[i]==0){
			int x=i;
			int f=0;
			while (1){
				if (u[x]==i){
					f=x;
					break;
				}
				if (u[x]>0) break;
				u[x]=i;
				x=g[x];
			}
			if (f){
				vector<int> c;
				while (u[x]==i){
					c.push_back(x);
					u[x]=n+1;
					x=g[x];
				}
				if (c.size()==1) c1.push_back(c[0]);
				else cyc.push_back(c);
			}
		}
	}
	int v=0;
	if (c1.size()>0){
		int r=c1[0];
		for (int i=1;i<(int)c1.size();i++){
			g[c1[i]]=r;
			v++;
		}
		for (int i=0;i<(int)cyc.size();i++){
			g[cyc[i][0]]=r;
			v++;
		}
	}
	else if(cyc.size()>0){
		int r=cyc[0][0];
		g[cyc[0][0]]=cyc[0][0];
		v++;
		for (int i=1;i<(int)cyc.size();i++){
			g[cyc[i][0]]=r;
			v++;
		}
	}
	cout<<v<<'\n';
	for (int i=1;i<=n;i++){
		cout<<g[i]<<" ";
	}
}