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
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int a[16][2048];
int n,m;
pair<int,int> w[2048];
int b[12][12];
int f[1<<12];
int f2[1<<12];
int p[12][1<<12]; // col mascara

int main(){
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d%d",&n,&m);
		mset(a,0);
		fore(i,0,n)fore(j,0,m)scanf("%d",&a[i][j]);
		m=max(m,n);
		fore(j,0,m){
			int mx=-1;
			fore(i,0,n)mx=max(mx,a[i][j]);
			w[j]=mp(mx,j);
		}
		sort(w,w+m);
		reverse(w,w+m);
		fore(i,0,n)fore(j,0,n)b[i][j]=a[i][w[j].snd];
		mset(f,0);
		fore(j,0,n)fore(s,0,(1<<n)){
			int r=0;
			fore(o,0,n){
				int x=0;
				fore(i,0,n)if(s&(1<<i))x+=b[(i+o)%n][j];
				r=max(r,x);
			}
			p[j][s]=r;
		}
		fore(j,0,n){
			mset(f2,0);
			fore(m,0,(1<<n)){ // cuales use
				int w=((1<<n)-1)^m;
				for(int s=w;;s=((s-1)&w)){
					f2[m|s]=max(f2[m|s],f[m]+p[j][s]);
					if(!s)break;
				}
			}
			mcpy(f,f2);
		}
		printf("%d\n",f[(1<<n)-1]);
	}
	return 0;
}