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
#define mcopy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

int p[1<<20],r=1<<20;

int main(){
	fore(i,2,1<<20)if(!p[i]){
		for(int j=i;j<(1<<20);j+=i)p[j]=i;
	}
	int x;
	scanf("%d",&x);
	fore(i,x-p[x]+1,x){
		if(p[i]!=i)r=min(r,i-p[i]+1);
		else r=min(r,i);
	}
	printf("%d\n",r);
	return 0;
}