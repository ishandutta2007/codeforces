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

int n;
int a[100005];
int q[100005],q2[100005];
int l0,l1;
vector<int> f;
set<int> p;

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d",a+i),q[--a[i]]++;
	int k=-1;
	fore(i,0,n)if(q[i]%2){
		if(k>=0){puts("0");return 0;}
		k=i;
	}
	// tengo que tener el primero que falla (*o el ultimo)
	// si es impar y falla el del medio tengo que tener una vez al menos el que falla
	fore(i,0,(n+1)/2)if(a[i]!=a[n-1-i]||i==n-1-i&&a[i]!=k)f.pb(i);
	if(!SZ(f)){printf("%lld\n",1LL*n*(n+1)/2);return 0;}
	if(k>=0&&a[n/2]!=k){
		fore(i,0,n)if(a[i]==k)p.insert(i);
	}
	while(1){
		q2[a[l0]]++;
		if(q2[a[l0]]>q[a[l0]]/2)break;
		l0++;
	}
	if(l0>=n/2)l0=1<<30;
	mset(q2,0);
	while(1){
		q2[a[n-1-l1]]++;
		if(q2[a[n-1-l1]]>q[a[n-1-l1]]/2)break;
		l1++;
	}
	if(l1>=n/2)l1=1<<30;
	ll r=0;
	fore(i,0,f[0]+1){
		int l=max(f.back(),n-1-l1);
		if(SZ(p)){
			auto it=p.lower_bound(i);
			if(it==p.end())l=n;
			else l=max(l,*it);
		}
		//printf(" %d %d\n",i,n-l);
		r+=n-l;
		l=max(f.back(),n-1-l0);
		if(SZ(p)){
			auto it=p.upper_bound(n-1-i);
			if(it==p.begin())l=n;
			else {
				--it;
				l=max(l,n-1-*it);
			}
		}
		//printf("  %d %d\n",i,n-l);
		r+=max(n-f[0]-1-l,0);
	}
	printf("%lld\n",r);
	return 0;
}