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

int n;
int w[200005];
ll r;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		int x;
		scanf("%d",&x);
		int s=0,e=1<<15;
		while(e-s>1){
			int m=(s+e)/2;
			if(m*m<=x)s=m;
			else e=m;
		}
		assert(s*s<=x&&(s+1)*(s+1)>x);
		int a=min(x-s*s,(s+1)*(s+1)-x),b;
		if(x!=s*s)b=0;
		else if(x==0)b=2;
		else b=1;
		r+=b;
		w[i]=a-b;
	}
	sort(w,w+n);
	fore(i,0,n/2)r+=w[i];
	printf("%lld\n",r);
	return 0;
}