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

int n;ll w,b,x;
int c[1024];
ll f[10005],z[10005];

int main(){
	scanf("%d%lld%lld%lld",&n,&w,&b,&x);
	fore(i,0,n)scanf("%d",c+i);
	fore(i,0,n)scanf("%lld",z+i);
	memset(f,-1,sizeof(f));f[0]=w;
	fore(i,0,n){
		fore(_,0,c[i]){
			int j=0;
			while(f[j]>=0)j++;
			for(j--;j>=0;j--)if(f[j]>=z[i])f[j+1]=max(f[j+1],f[j]-z[i]);
		}
		for(int j=0;f[j]>=0;j++)f[j]+=x,f[j]=min(f[j],w+b*j);
	}
	int r=0;
	while(f[r]>=0)r++;
	printf("%d\n",r-1);
	return 0;
}