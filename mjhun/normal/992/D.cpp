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

#define INF ((1LL<<61)-5)

ll mul(ll a, ll b){
	ll r=a*b;
	if(r%a||r%b||r/a!=b||r/b!=a)return INF;
	return r;
}

int n;ll k,a[200005];
int o[200005];

int main(){
	scanf("%d%lld",&n,&k);
	fore(i,0,n)scanf("%lld",a+i);
	for(int i=n-1;i>=0;--i)o[i]=(1+o[i+1])*(a[i]==1);
	int r=0;
	fore(i,0,n){
		ll p=a[i],s=a[i];
		int j=i+1;
		while(1){
			if(s*k==p)r++;
			if(j==n)break;
			//printf(" %d\n",j);
			if(o[j]){
				if(s*k>=p)s+=o[j],j+=o[j];
				else {
					ll t=min(1LL*o[j],(p-s*k+k-1)/k);
					s+=t;j+=t;
				}
			}
			else {
				p=mul(p,a[j]);
				s+=a[j];
				j++;
			}
			if(p==INF)break;
		}
	}
	printf("%d\n",r);
	return 0;
}