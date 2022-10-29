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
using namespace std;
typedef long long ll;

int n,l;
int x[1024],b[1024];
double a[1024][1024];
double c[1024];
double d[1024];
int o[1024];
vector<int> r;

bool can(double k){
	d[n-1]=0.;
	for(int i=n-2;i>=0;--i){
		d[i]=1e10;
		fore(j,i+1,n){
			double z=a[i][j]-k*b[j]+d[j];
			if(z<d[i])d[i]=z,o[i]=j;
		}
	}
	double rr=1e10;int y;
	fore(i,0,n){
		double z=c[i]-k*b[i]+d[i];
		if(z<rr)rr=z,y=i;
	}
	if(rr>0)return false;
	r.clear();
	r.pb(y);
	while(y!=n-1){
		y=o[y];
		r.pb(y);
	}
	return true;
}

int main(){
	scanf("%d%d",&n,&l);
	fore(i,0,n)scanf("%d%d",x+i,b+i);
	fore(i,0,n)fore(j,i+1,n)a[i][j]=sqrt(abs(x[j]-x[i]-l));
	fore(i,0,n)c[i]=sqrt(abs(x[i]-l));
	if(n==1){puts("1");return 0;}
	double s=0.,e=1e6;
	fore(_,0,60){
		double m=(s+e)/2;
		if(can(m))e=m;
		else s=m;
	}
	assert(can(e));
	fore(i,0,SZ(r)){
		if(i)putchar(' ');
		printf("%d",r[i]+1);
	}
	puts("");
	return 0;
}