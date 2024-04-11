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

int n,a[128],p[128];pair<int,int> ap[128];
long double C,T;double _C,_T;
long double f[1024][128],f2[1024][128];
long double pw[128];

int main(){
	pw[0]=1;
	fore(i,1,128)pw[i]=pw[i-1]*10/9;
	int tn;
	scanf("%d",&tn);
	while(tn--){
		scanf("%d%lf%lf",&n,&_C,&_T);C=_C;T=_T;
		fore(i,0,n)scanf("%d%d",a+i,p+i),ap[i]=mp(a[i],p[i]);
		sort(ap,ap+n);reverse(ap,ap+n);
		fore(i,0,n)a[i]=ap[i].fst,p[i]=ap[i].snd;
		int s=0;
		f[0][0]=0;
		fore(k,0,n){
			fore(z,0,s+p[k]+1)fore(q,0,k+2)f2[z][q]=1e200;
			fore(z,0,s+1)fore(q,0,k+1){
				f2[z][q]=min(f2[z][q],f[z][q]);
				long double r=f[z][q]+pw[q+1]*a[k];
				int nz=z+p[k];int nq=q+1;
				f2[nz][nq]=min(f2[nz][nq],r);
			}
			fore(z,0,s+p[k]+1)fore(q,0,k+2)f[z][q]=f2[z][q];
			s+=p[k];
		}
		int r=0;
		for(int i=s;i;--i){
			bool can=false;
			fore(k,1,n+1){
				if(f[i][k]>1e100)continue;
				long double s=f[i][k];
				long double t=T-k*10;
				if(t<0)continue;
				long double x=max((sqrt(s*C)-1)/C,0.l);
				//long double x=max((t-1)/(2*C),0.l);
				if(s/(1+C*x)+x<t){
					//printf(" %.12lf %.12lf\n",(double)x,(double)(s/(1+C*x)+x+k*10));
					can=true;break;
				}
			}
			if(can){r=i;break;}
		}
		printf("%d\n",r);
	}
	return 0;
}