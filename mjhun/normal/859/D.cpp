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

int n,m;
double p[64][64];
double f[8][64]; // prob que llegue a tal nivel
double dp[8][64][128]; // nivel, base, elegi
bool vis[8][64][128];

double g(int k, int b, int x){
	double& r=dp[k][b][x];
	if(vis[k][b][x])return r;
	//printf("%d %d %d\n",k,b,x);
	vis[k][b][x]=true;
	r=0;
	if(k==0)return r;
	if(x==100){
		fore(i,b,b+(1<<(k-1))){
			r=max(r,f[k][i]*(1<<(k-1))+g(k-1,b,i)+g(k-1,b+(1<<(k-1)),100));
		}
		fore(i,b+(1<<(k-1)),b+(1<<k)){
			r=max(r,f[k][i]*(1<<(k-1))+g(k-1,b+(1<<(k-1)),i)+g(k-1,b,100));
		}
	}
	else {
		assert(x>=b&&x<b+(1<<k));
		if(x<b+(1<<(k-1))){
			r=f[k][x]*(1<<(k-1))+g(k-1,b+(1<<(k-1)),100)+g(k-1,b,x);
		}
		else {
			r=f[k][x]*(1<<(k-1))+g(k-1,b,100)+g(k-1,b+(1<<(k-1)),x);
		}
	}
	return r;
}

int main(){
	scanf("%d",&m);n=1<<m;
	fore(i,0,n)fore(j,0,n){
		int t;
		scanf("%d",&t);
		p[i][j]=t/100.;
	}
	fore(i,0,n)f[0][i]=1;
	fore(k,1,m+1){
		double s=0;
		fore(i,0,n){
			int t=(i/(1<<k)*(1<<k));
			if(i<t+(1<<(k-1)))t+=(1<<(k-1));
			fore(j,t,t+(1<<(k-1))){
				f[k][i]+=f[k-1][j]*p[i][j];
			}
			f[k][i]*=f[k-1][i];
			//printf(" %d %d %.12lf\n",k,i,f[k][i]);
			s+=f[k][i];
		}
		//printf(" %.12lf\n",s);
	}
	printf("%.12lf\n",g(m,0,100));
	return 0;
}