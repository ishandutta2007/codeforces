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

vector<int> d;

int main(){
	int l,r,x,y;
	scanf("%d%d%d%d",&l,&r,&x,&y);
	for(int i=1;i*i<=y;++i)if(y%i==0){
		d.pb(i);
		if(i*i<y)d.pb(y/i);
	}
	int t=0;
	for(int a:d)for(int b:d){
		int g=__gcd(a,b);
		t+=a>=l&&a<=r&&b>=l&&b<=r&&g==x&&1LL*a*b/g==y;
	}
	printf("%d\n",t);
	return 0;
}