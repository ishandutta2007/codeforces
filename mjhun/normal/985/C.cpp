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

int n,k,l,m;
int x[100005];

int main(){
	scanf("%d%d%d",&n,&k,&l);m=n*k;
	fore(i,0,m)scanf("%d",x+i);
	sort(x,x+m);
	int t=upper_bound(x,x+m,x[0]+l)-x;
	if(1LL*t*(k-1)<m-t){puts("0");return 0;}
	ll r=0;
	int i=t-1,q=m-t;
	fore(_,0,n){
		int a=min(q,k-1);
		q-=a;i-=k-1-a;
		r+=x[i];
		i--;
	}
	assert(q==0&&i==-1);
	printf("%lld\n",r);
	return 0;
}