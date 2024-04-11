#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
#define MOD 1000000007
using namespace std;
typedef long long ll;

int add(int x, int y){return (x+y)%MOD;}
int mul(int x, int y){return (1LL*x*y)%MOD;}
int pm(int x, int e){
	int r=1;
	while(e){
		if(e&1)r=mul(r,x);
		e>>=1;
		x=mul(x,x);
	}
	return r;
}
int inv(int x){return pm(x,MOD-2);}

int fact[200005];
int ifact[200005];

int comb(int n, int k){
	return mul(fact[n],mul(ifact[k],ifact[n-k]));
}

int cnt(int x0, int y0, int x1, int y1){
	if(y1<y0||x1<x0)return 0;
	return comb(x1-x0+y1-y0,x1-x0);
}

int nx,ny,n;
pair<int,int> p[2048];
int f[2048];

int main(){
	fact[0]=ifact[0]=1;
	fore(i,1,200005){
		fact[i]=mul(fact[i-1],i);
		ifact[i]=inv(fact[i]);
	}
	scanf("%d%d%d",&nx,&ny,&n);
	fore(i,0,n){
		int x,y;
		scanf("%d%d",&x,&y);
		p[i]=mp(x,y);
	}
	sort(p,p+n);
	p[n++]=mp(nx,ny);
	fore(i,0,n){
		f[i]=add(f[i],cnt(1,1,p[i].fst,p[i].snd));
		fore(j,i+1,n){
			f[j]=add(f[j],MOD-mul(f[i],cnt(p[i].fst,p[i].snd,p[j].fst,p[j].snd)));
		}
	}
	printf("%d\n",f[n-1]);
	return 0;
}