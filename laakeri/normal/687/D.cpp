#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int u[1010][1010];
int c[1010][1010];
int l[1010];
int r[1010];
int v[1010];

int ne[1010][1010];
int f[1010][1010];

int us[1010][1010];

void add(int q, int a, int b){
	int s=0;
	if (c[q][a] == c[q][b]) s=1;
	a=u[q][a];
	b=u[q][b];
	if (us[a]<us[b]) {
		int x=f[q][a];
		int lx=0;
		while (x!=0){
			u[q][x]=b;
			if (s) c[q][x]=1-c[q][x];
			lx=x;
			x=ne[q][x];
		}
		ne[q][lx]=f[q][b];
		f[q][b]=f[q][a];
		us[q][b]+=us[q][a];
	}
	else {
		int x=f[q][b];
		int lx=0;
		while (x!=0){
			u[q][x]=a;
			if (s) c[q][x]=1-c[q][x];
			lx=x;
			x=ne[q][x];
		}
		ne[q][lx]=f[q][a];
		f[q][a]=f[q][b];
		us[q][a]+=us[q][b];
	}
}

int main(){
	int n,m,q;
	scanf("%d %d %d", &n, &m, &q);
	for (int i=1;i<=q;i++){
		for (int j=1;j<=n;j++){
			u[i][j]=j;
			us[i][j]=1;
			f[i][j]=j;
		}
	}
	vector<pair<pair<int, int>, pair<int, int> > > es;
	for (int i=1;i<=m;i++){
		int a,b,w;
		scanf("%d %d %d", &a, &b, &w);
		es.push_back({{w, i}, {a, b}});
	}
	sort(es.rbegin(), es.rend());
	for (int i=1;i<=q;i++){
		scanf("%d %d", &l[i], &r[i]);
		v[i]=-1;
	}
	for (int qq=1;qq<=q;qq++){
		for (auto eee:es){
			pair<pair<int, int>, pair<int, int> > e=eee;
			int ei=e.F.S;
			if (l[qq]<=ei&&r[qq]>=ei&&v[qq]==-1){
				if (u[qq][e.S.F]==u[qq][e.S.S]){
					if (c[qq][e.S.F]==c[qq][e.S.S]) {
						v[qq]=e.F.F;
					}
				}
				else{
					add(qq, e.S.F, e.S.S);
				}
			}
		}
	}
	for (int i=1;i<=q;i++){
		printf("%d\n", v[i]);
	}
}