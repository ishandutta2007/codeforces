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

int n,m;
ll a[300005],b[300005];
ll sa,sb;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i),sa+=a[i];
	scanf("%d",&m);
	fore(i,0,m)scanf("%lld",b+i),sb+=b[i];
	if(sa!=sb){puts("-1");return 0;}
	int i=1,j=0;
	sa=a[0];sb=0;
	int r=1;
	while(i<n&&j<m){
		if(sa==sb)r++;
		if(sa<=sb)sa+=a[i++];
		else sb+=b[j++];
	}
	printf("%d\n",r);
	return 0;
}