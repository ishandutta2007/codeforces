#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

double f[1<<20];
double p[32];
int n,k,z;

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n){scanf("%lf",p+i);if(!p[i])z++;}
	if(n-z<k){
		fore(i,0,n){
			if(i)putchar(' ');
			printf("%.10lf",p[i]?1.:0.);
		}
		puts("");
		return 0;
	}
	f[0]=1;
	fore(m,1,1<<n){
		double s=0.;
		fore(i,0,n)if(!(m&(1<<i)))s+=p[i];
		f[m]=0.;
		fore(i,0,n)if(m&(1<<i))f[m]+=f[m^(1<<i)]*p[i]/(s+p[i]);
	}
	fore(i,0,n){
		if(i)putchar(' ');
		double r=0.;
		fore(m,0,1<<n)if(__builtin_popcount(m)==k&&(m&(1<<i)))r+=f[m];
		printf("%.10lf",r);
	}
	puts("");
	return 0;
}