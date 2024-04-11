#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

double st[400005][2];
double p[100005];
int n,q;

void merge(double *r, double *a, double *b){
	if(a[0]<-0.5){
		r[0]=b[0];
		r[1]=b[1];
	}
	else {
		double t[2],t0,t1;
		t0=b[0]/(1-(1-b[0])*a[1]);
		t[0]=a[0]*t0;
		t1=a[1]*t0;
		t[1]=b[1]+(1-b[1])*t1;
		r[0]=t[0];
		r[1]=t[1];
	}
}

void st_init(int k, int s, int e){
	if(s+1==e){
		st[k][0]=st[k][1]=p[s];
	}
	else {
		int m=(s+e)/2;
		st_init(2*k,s,m);
		st_init(2*k+1,m,e);
		merge(st[k],st[2*k],st[2*k+1]);
	}
}

void st_upd(int k, int s, int e, int p, double v){
	if(s+1==e){
		st[k][0]=st[k][1]=v;
	}
	else {
		int m=(s+e)/2;
		if(p<m)st_upd(2*k,s,m,p,v);
		else st_upd(2*k+1,m,e,p,v);
		merge(st[k],st[2*k],st[2*k+1]);
	}
}

void st_query(int k, int s, int e, int a, int b, double *r){
	if(e<=a||s>=b)return;
	if(s>=a&&e<=b)merge(r,r,st[k]);
	else {
		int m=(s+e)/2;
		st_query(2*k,s,m,a,b,r);
		st_query(2*k+1,m,e,a,b,r);
	}
}


int main(){
	scanf("%d%d",&n,&q);
	fore(i,0,n){
		int a,b;
		scanf("%d%d",&a,&b);
		p[i]=1.*a/b;
	}
	st_init(1,0,n);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int i,a,b;
			scanf("%d%d%d",&i,&a,&b);
			st_upd(1,0,n,i-1,1.*a/b);
		}
		else {
			int a,b;
			scanf("%d%d",&a,&b);
			double r[2];r[0]=r[1]=-1.;
			st_query(1,0,n,a-1,b,r);
			printf("%.10lf\n",r[0]);
		}
	}
	return 0;
}