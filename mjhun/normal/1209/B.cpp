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

int r=0;
int n,a[128],b[128],s[128];
char tt[128];

int main(){
	scanf("%d%s",&n,tt);
	fore(i,0,n)s[i]=tt[i]-'0';
	fore(i,0,n)scanf("%d%d",a+i,b+i);
	fore(t,0,(1<<20)){
		int z=0;
		fore(i,0,n){
			int q=max(t-b[i]+1,0);
			q=(q+a[i]-1)/a[i];
			q&=1;
			z+=(s[i]^q);
		}
		r=max(r,z);
	}
	printf("%d\n",r);
	return 0;
}