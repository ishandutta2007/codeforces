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

int main(){
	int n,a,b;
	scanf("%d%d%d",&n,&a,&b);
	for(int i=0;a*i<=n;++i){
		if((n-a*i)%b==0){
			printf("YES\n%d %d\n",i,(n-a*i)/b);
			return 0;
		}
	}
	puts("NO");
	return 0;
}