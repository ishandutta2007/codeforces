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

#define INF 1e12
#define EPS 1e-8

int n;double tt,t;
set<pair<double,int> > q;
pair<pair<double,double>,pair<int,int> > xx[16];
double x[16],v[16];int m[16];
double ct[16];
double rr[16];

void doit(int i){
	if(i<0||i>=n-1)return;
	q.erase(mp(ct[i],i));
	if(v[i]<v[i+1]+EPS)ct[i]=INF;
	else ct[i]=t+(x[i+1]-x[i])/(v[i]-v[i+1]);
	q.insert(mp(ct[i],i));
}

int main(){
	scanf("%d%lf",&n,&tt);
	fore(i,0,n)scanf("%lf%lf%d",x+i,v+i,m+i),xx[i]=mp(mp(x[i],v[i]),mp(m[i],i));
	sort(xx,xx+n);
	fore(i,0,n)x[i]=xx[i].fst.fst,v[i]=xx[i].fst.snd,m[i]=xx[i].snd.fst;
	fore(i,0,n-1)doit(i);
	while(q.begin()->fst<tt){
		auto p=*q.begin();q.erase(q.begin());
		fore(i,0,n)x[i]+=v[i]*(p.fst-t);
		t=p.fst;
		int k=p.snd;
		double v0=((m[k]-m[k+1])*v[k]+2*m[k+1]*v[k+1])/(m[k]+m[k+1]);
		double v1=((m[k+1]-m[k])*v[k+1]+2*m[k]*v[k])/(m[k]+m[k+1]);
		v[k]=v0;v[k+1]=v1;
		doit(k-1);doit(k);doit(k+1);
	}
	fore(i,0,n)rr[xx[i].snd.snd]=x[i]+v[i]*(tt-t);
	fore(i,0,n)printf("%.12lf\n",rr[i]);
	return 0;
}