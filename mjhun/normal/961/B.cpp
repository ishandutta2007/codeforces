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

int a[100005];
int s[100005];
int n,k,ss,r;

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n)scanf("%d",a+i);
	fore(i,0,n){
		int t;
		scanf("%d",&t);
		if(t==1){ss+=a[i];a[i]=0;}
	}
	fore(i,0,n)s[i+1]=s[i]+a[i];
	fore(i,0,n-k+1)r=max(r,s[i+k]-s[i]);
	printf("%d\n",ss+r);
	return 0;
}