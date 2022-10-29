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
int t[100005];
vector<int> d[200005];

int main(){
	fore(i,1,200005)for(int j=i;j<200005;j+=i)d[j].pb(i);
	scanf("%d",&n);
	fore(i,0,n/2)scanf("%d",a+i);
	int p=0;
	fore(i,0,n/2){
		pair<int,int> r=mp(1<<20,1<<20); // min
		for(int x:d[a[i]]){
			int y=a[i]/x;
			if(x>y)break;
			// t1-t0=x , t1+t0=y
			if((x+y)%2)continue;
			int t1=(x+y)/2;
			int t0=y-t1;
			if(t0<=p||t0>=t1)continue;
			r=min(r,mp(t1,t0));
		}
		if(r.fst==(1<<20)){puts("No");return 0;}
		t[2*i+1]=r.fst;
		t[2*i]=r.snd;
		p=r.fst;
	}
	puts("Yes");
	ll s=0; // suma
	fore(i,0,n){
		if(i)putchar(' ');
		ll x=1LL*t[i]*t[i]-s;
		printf("%lld",x);
		s+=x;
	}
	puts("");
	return 0;
}