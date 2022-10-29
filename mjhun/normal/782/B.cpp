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

int n,x[60005],v[60005];

bool can(double t){
	double a=-1e100,b=1e100;
	fore(i,0,n)a=max(a,x[i]-v[i]*t),b=min(b,x[i]+v[i]*t);
	return a<b;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",x+i);
	fore(i,0,n)scanf("%d",v+i);
	double s=0,e=1e10;
	fore(_,0,100){
		double m=(s+e)/2;
		if(can(m))e=m;
		else s=m;
	}
	printf("%.12lf\n",s);
	return 0;
}