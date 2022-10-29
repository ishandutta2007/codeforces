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

int gcd(int a, int b){
	while(b){
		int c=a%b;
		a=b;b=c;
	}
	return a;
}

int st[1<<21];
void st_init(int k, int s, int e, int* a){
	if(s+1==e)st[k]=a[s];
	else {
		int m=(s+e)/2;
		st_init(2*k,s,m,a);
		st_init(2*k+1,m,e,a);
		st[k]=gcd(st[2*k],st[2*k+1]);
	}
}
void st_upd(int k, int s, int e, int p, int v){
	if(s+1==e)st[k]=v;
	else {
		int m=(s+e)/2;
		if(p<m)st_upd(2*k,s,m,p,v);
		else st_upd(2*k+1,m,e,p,v);
		st[k]=gcd(st[2*k],st[2*k+1]);
	}
}
int st_query(int k, int s, int e, int a, int x){ // mayor b tal que x\gcd([a,b))
	if(e<=a)return e;
	if(st[k]%x==0)return e;
	if(s+1==e)return s;
	int m=(s+e)/2,r;
	if(a<m){
		r=st_query(2*k,s,m,a,x);
		if(r==m)r=st_query(2*k+1,m,e,a,x);
	}
	else r=st_query(2*k+1,m,e,a,x);
	return r;
}

int a[1<<20],n;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i);
	st_init(1,0,n,a);
	int q;
	scanf("%d",&q);
	while(q--){
		int t;
		scanf("%d",&t);
		if(t==1){
			int s,e,x;
			scanf("%d%d%d",&s,&e,&x);s--;
			if(s+1==e){puts("YES");continue;}
			int b=st_query(1,0,n,s,x);
			//printf(" %d\n",b);
			if(b>=e)puts("YES");
			else {
				st_upd(1,0,n,b,x);
				if(st_query(1,0,n,s,x)>=e)puts("YES");
				else puts("NO");
				st_upd(1,0,n,b,a[b]);
			}
		}
		else {
			int k,y;
			scanf("%d%d",&k,&y);k--;
			a[k]=y;
			st_upd(1,0,n,k,y);
		}
	}
	return 0;
}