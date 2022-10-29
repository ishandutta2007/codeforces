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

#define INF ((1<<30)-1)

int sp[5005];
int f[5005],f2[5005];
void go(int s, int e, int s0, int e0){
	if(s==e)return;
	int m=(s+e)/2,r=INF,rp=s0;
	fore(j,s0,min(e0,m)){
		int t=sp[m]-sp[j],r0;
		if(t>=f[j])r0=t;
		else r0=INF;
		if(r0<r)r=r0,rp=j;
	}
	f2[m]=r;
	go(s,m,s0,rp+1);go(m+1,e,rp,e0);
}

int n,h[5005];

bool doit(){
	go(0,n+1,0,n);
	mcpy(f,f2);
	return f[n]<INF;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",h+i);
	f[0]=0;
	fore(i,1,n+1)f[i]=f[i-1]+h[i-1];
	f[0]=INF;
	fore(i,0,n)sp[i+1]=sp[i]+h[i];
	int r=n-1;
	while(doit())r--;
	printf("%d\n",r);
	return 0;
}