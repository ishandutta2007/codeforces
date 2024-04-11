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

int n;
int x[100005];
double f[100005][105],f2[105],r;

double c(int n, int k){
	double d=1;
	fore(i,0,k)d*=1.*(n-i)/(i+1);
	return d;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i),f[i][x[i]]=1.;
	fore(i,0,n)r+=f[i][0];
	int q;
	scanf("%d",&q);
	while(q--){
		int a,b,k;
		scanf("%d%d%d",&a,&b,&k);a--;b--;
		r-=f[a][0];
		fill(f2,f2+105,0.);
		double d=c(x[a],k);
		fore(j,0,k+1){
			double c0=1.,c1=c(x[a]-j,k-j);
			fore(i,j,min(100,x[a])+1){
				f2[i-j]+=f[a][i]*c0*c1/d;
				c0*=1.*(i+1)/(i+1-j);
				c1*=1.*(x[a]-i-(k-j))/(x[a]-i);
			}
		}
		mcpy(f[a],f2);
		r+=f[a][0];
		printf("%.12lf\n",r);
		x[a]-=k;x[b]+=k;
	}
	return 0;
}