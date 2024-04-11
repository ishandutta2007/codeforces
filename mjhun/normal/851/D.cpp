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

int n;ll x,y;
ll q[1<<21],s[1<<21];
bool p[1<<21];

int main(){
	memset(p,true,sizeof(p));
	scanf("%d%lld%lld",&n,&x,&y);
	fore(i,0,n){
		int x;
		scanf("%d",&x);q[x+1]++;s[x+1]+=x;
	}
	fore(i,2,1<<21)q[i]+=q[i-1],s[i]+=s[i-1];
	ll r=1LL<<60;
	fore(i,2,(1<<21)-1)if(p[i]){
		ll z=0;
		for(int j=i;j<((1<<21)-1);j+=i){
			p[j]=false;
			ll w=x/y;
			int a=max(1LL*j-i,j-w-1)+1;
			z+=x*(q[a]-q[j-i+1]);
			z+=y*(j*(q[j+1]-q[a])-(s[j+1]-s[a]));
		}
		r=min(r,z);
	}
	printf("%lld\n",r);
	return 0;
}