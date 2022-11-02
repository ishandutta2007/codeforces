#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int a[202020];
int b[202020];
int can[1010][1010];
int v[202020];
vector<pair<pair<int, int>, pair<int, int> > > qs[202020];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m,q;
	cin>>n>>m>>q;
	for (int i=1;i<=m;i++){
		cin>>a[i]>>b[i];
	}
	for (int qq=0;qq<q;qq++){
		int l,r,s,t;
		cin>>l>>r>>s>>t;
		qs[l].push_back({{s, t}, {qq, r}});
	}
	for (int i=1;i<=n;i++){
		for (int ii=1;ii<=n;ii++){
			can[i][ii]=m+1;
		}
		can[i][i]=0;
	}
	for (int i=m;i>=1;i--){
		for (int j=1;j<=n;j++){
			can[a[i]][j]=min(can[a[i]][j], max(i, can[b[i]][j]));
			can[b[i]][j]=min(can[b[i]][j], max(i, can[a[i]][j]));
		}
		for (auto qq:qs[i]){
			if (can[qq.F.F][qq.F.S]<=qq.S.S){
				v[qq.S.F]=1;
			}
		}
	}
	for (int i=0;i<q;i++){
		if (v[i]){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
}