#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,to=b;i<to;++i)
using namespace std;

typedef long long ll;

int a[303],b[303],t[303];
int n,m,d;
int f[1<<18];
int st[18][1<<18];

void st_init(){
	fore(i,0,n)st[0][i]=f[i];
	fore(k,1,18){
		fore(i,0,n-(1<<k)+1){
			st[k][i]=min(st[k-1][i],st[k-1][i+(1<<(k-1))]);
		}
	}
}

int st_query(int s, int e){
	int k=31-__builtin_clz(e-s);
	return min(st[k][s],st[k][e-(1<<k)]);
}

int main(){
	ll r=0;
	scanf("%d%d%d",&n,&m,&d);
	fore(i,0,m)scanf("%d%d%d",a+i,b+i,t+i),a[i]--,r+=b[i];
	for(int i=m-1;i>=0;--i){
		fore(j,0,n){
			f[j]=abs(a[i]-j);
			if(i<m-1){
				int t0=t[i+1]-t[i];
				int s=max(-1LL*d*t0+j,0LL);
				int e=min(1LL*d*t0+j+1,1LL*n);
				f[j]+=st_query(s,e);
			}
		}
		st_init();
	}
	int r0=1<<30;
	fore(i,0,n)r0=min(r0,f[i]);
	printf("%I64d\n",r-r0);
	return 0;
}