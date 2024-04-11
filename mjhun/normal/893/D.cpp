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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int n;ll d;
ll s[100005],w[100005];

int main(){
	scanf("%d%lld",&n,&d);
	fore(i,0,n)scanf("%lld",s+i+1);
	fore(i,0,n)s[i+1]+=s[i];
	w[n]=-(1LL<<60);
	for(int i=n-1;i>=0;--i)w[i]=max(s[i+1],w[i+1]);
	if(w[0]>d){puts("-1");return 0;}
	ll k=0;int r=0;
	fore(i,0,n)if(s[i]==s[i+1]&&s[i+1]+k<0){
		k=d-w[i];r++;
		if(s[i+1]+k<0){puts("-1");return 0;}
	}
	printf("%d\n",r);
	return 0;
}