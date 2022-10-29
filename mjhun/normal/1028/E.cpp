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

ll x[200005];
ll r[200005];
int n;

int pr(int i){
	if(i==0)return n-1;
	return i-1;
}
int nx(int i){
	if(i==n-1)return 0;
	return i+1;
}

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",x+i);
	bool e=true;
	fore(i,1,n)e=e&&x[i]==x[i-1];
	if(e){
		if(x[0]==0){
			printf("YES\n1");
			fore(_,1,n)printf(" 1");
			puts("");
		}
		else puts("NO");
		return 0;
	}
	int t=-1;
	fore(i,0,n)if(x[i]>x[pr(i)]){t=i;break;}
	assert(t>=0);
	r[t]=x[t];
	for(int i=pr(t);i!=t;i=pr(i)){
		ll cc=r[nx(i)],b=x[i],a=x[pr(i)];
		ll k=max(a-b,0LL)/cc+1;
		r[i]=cc*k+b;
	}
	puts("YES");
	fore(i,0,n)printf("%lld%c",r[i]," \n"[i==n-1]);
	return 0;
}