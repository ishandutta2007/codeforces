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

int h,m,a,b,d;double c;

double doit(int a, int d, double c){
	return ((a+d-1)/d)*c;
}

int main(){
	scanf("%d%d%d%d%lf%d",&h,&m,&a,&b,&c,&d);
	double r;
	if(h>=20)r=doit(a,d,c*.8);
	else {
		r=doit(a,d,c);
		int t=20*60-(h*60+m);
		r=min(r,doit(a+b*t,d,c*.8));
	}
	printf("%.12lf\n",r);
	return 0;
}