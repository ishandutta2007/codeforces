#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;
typedef long long ll;

int n;
int a[200005];
vector<int> g[200005];
int f[18][200005];
ll s[18][200005];
int r[200005];
int w[200005];

void dfs(int x){
	r[x]=w[x];
	fore(i,0,g[x].size()){
		int y=g[x][i];
		dfs(y);
		r[x]+=r[y];
	}
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	memset(f,-1,sizeof(f));
	memset(s,0,sizeof(s));
	fore(i,1,n){
		scanf("%d%lld",&f[0][i],&s[0][i]);
		f[0][i]--;
		g[f[0][i]].pb(i);
	}
	fore(k,1,18){
		fore(i,0,n){
			if(f[k-1][i]<0){
				f[k][i]=-1;
				s[k][i]=s[k-1][i];
			}
			else {
				f[k][i]=f[k-1][f[k-1][i]];
				s[k][i]=s[k-1][i]+s[k-1][f[k-1][i]];
			}
		}
	}
	fore(x,0,n){
		int y=x;
		ll d=0;
		for(int k=17;k>=0;--k){
			if(f[k][y]>=0&&d+s[k][y]<=a[x]){
				d+=s[k][y];
				y=f[k][y];
			}
		}
		w[x]++;
		w[y]--;
	}
	dfs(0);
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%d",r[i]-w[i]);
	}
	puts("");
	return 0;
}