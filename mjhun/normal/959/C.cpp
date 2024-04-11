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

int main(){
	scanf("%d",&n);
	if(n<=5)puts("-1");
	else {
		puts("1 2");
		fore(i,2,n){
			if(i%2==0)printf("1 %d\n",i+1);
			else printf("2 %d\n",i+1);
		}
	}
	fore(i,0,n-1)printf("%d %d\n",i+1,i+2);
	return 0;
}