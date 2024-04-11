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

int n,m,k;
int a[200005];
int s[2048];
int w[2048];
int f[2048];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	fore(i,0,n)scanf("%d",a+i);
	sort(a,a+n);
	fore(i,0,k)s[i+1]=s[i]+a[i];
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		if(x>k)continue;
		w[x]=max(w[x],y);
	}
	f[0]=0;
	fore(i,1,k+1){
		f[i]=1<<30;
		fore(j,1,i+1)f[i]=min(f[i],f[i-j]+s[i]-s[i-j+w[j]]);
	}
	printf("%d\n",f[k]);
	return 0;
}