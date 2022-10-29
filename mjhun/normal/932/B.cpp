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
#define mset(a,v) memset(a,v,sizeof(a))
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int f(int x){
	int r=1;
	while(x){
		if(x%10)r*=x%10;
		x/=10;
	}
	return r;
}
int g[1<<20];
int sp[1<<20][10];

int main(){
	fore(i,0,10)g[i]=i;
	fore(i,1,1<<20)g[i]=g[f(i)];
	fore(i,1,1<<20){
		mcopy(sp[i],sp[i-1]);
		sp[i][g[i-1]]++;
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);r++;
		printf("%d\n",sp[r][k]-sp[l][k]);
	}
	return 0;
}