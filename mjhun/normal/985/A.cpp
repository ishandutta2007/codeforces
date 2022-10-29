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
int x[128];

int main(){
	scanf("%d",&n);
	fore(i,0,n/2)scanf("%d",x+i);
	sort(x,x+(n/2));
	int r=1<<30;
	fore(kk,1,3){
		int s=0,k=kk;
		fore(i,0,n/2)s+=abs(x[i]-k),k+=2;
		r=min(r,s);
	}
	printf("%d\n",r);
	return 0;
}