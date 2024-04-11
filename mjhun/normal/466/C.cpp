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
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

int n;
ll a[1<<19],s;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%lld",a+i),s+=a[i];
	if(s%3){puts("0");return 0;}
	s/=3;
	ll c=0,r=0;int t=0;
	fore(i,0,n-1){
		c+=a[i];
		if(c==2*s)r+=t;
		if(c==s)t++;
	}
	printf("%lld\n",r);
	return 0;
}