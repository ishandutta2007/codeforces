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

int n,r;
int x[1024];double y[1024];


int main(){
	scanf("%d%d",&n,&r);
	fore(i,0,n)scanf("%d",x+i);
	fore(i,0,n){
		y[i]=r;
		fore(j,0,i){
			if(abs(x[i]-x[j])>2*r)continue;
			if(abs(x[i]-x[j])==2*r){y[i]=max(y[i],y[j]);continue;}
			y[i]=max(y[i],y[j]+sqrt(4*r*r-(x[i]-x[j])*(x[i]-x[j])));
		}
	}
	fore(i,0,n){
		if(i)putchar(' ');
		printf("%.12lf",y[i]);
	}
	puts("");
	return 0;
}