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

int n,k;
int a[128];

int main(){
	scanf("%d%d",&n,&k);
	fore(i,0,n)scanf("%d",a+i);
	int r=0,i=0;
	while(i<n&&a[i]<=k)i++,r++;
	if(i==n){printf("%d\n",r);return 0;}
	i=n-1;
	while(a[i]<=k)i--,r++;
	printf("%d\n",r);
	return 0;
}