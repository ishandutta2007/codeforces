#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int q,n;
int f[1<<19][19];
ll g[1<<19][19];
int f2[1<<19][19];
ll w[1<<19][19];


int main(){
	mset(f[0],-1);mset(g[0],-1);
	mset(f2[0],-1);
	fore(i,1,19)f[0][i]=f2[0][i]=-2;
	n=1;int last=0;
	scanf("%d",&q);
	while(q--){
		int t;ll pp,qq;
		scanf("%d%lld%lld",&t,&pp,&qq);
		int x=(pp^last)-1;ll v=qq^last;
		if(t==1){
			//printf("add %d %d\n",x,v);
			f[n][0]=x;
			g[n][0]=v;
			w[n][0]=v;
			fore(k,1,19){
				if(f[n][k-1]<0)f[n][k]=-2,g[n][k]=g[n][k-1];
				else {
					f[n][k]=f[f[n][k-1]][k-1];
					g[n][k]=max(g[n][k-1],g[f[n][k-1]][k-1]);
				}
			}
			if(w[x][0]>=w[n][0]){
				f2[n][0]=x;
			}
			else {
				int y=x;
				for(int k=18;k>=0;k--){
					if(y<0)break;
					if(g[y][k]<w[n][0])y=f[y][k];
				}
				if(y<0||w[y][0]<w[n][0])f2[n][0]=-1;
				else f2[n][0]=y;
			}
			fore(k,1,19){
				if(f2[n][k-1]<0)f2[n][k]=-2,w[n][k]=w[n][k-1];
				else {
					f2[n][k]=f2[f2[n][k-1]][k-1];
					w[n][k]=w[n][k-1]+w[f2[n][k-1]][k-1];
				}
			}
			n++;
		}
		else {
			int r=0;
			if(x==0)r=1;
			else {
				//printf(" %d %d  %d\n",x,v,w[x][0]);
				for(int k=18;k>=0;--k){
					if(x<0)break;
					if(f2[x][k]==-2)continue;
					if(w[x][k]<=v){
						v-=w[x][k];
						x=f2[x][k];
						r+=(1<<k);
					}
				}
			}
			printf("%d\n",r);
			last=r;
		}
	}
	return 0;
}