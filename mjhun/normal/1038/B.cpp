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


int main(){
	int n;
	scanf("%d",&n);
	int t=n*(n+1)/2;
	int p=-1;
	for(int i=2;i*i<=t;++i)if(t%i==0){p=i;break;}
	if(p<0){puts("No");return 0;}
	puts("Yes");
	printf("1 %d\n%d",p,n-1);
	fore(i,1,n+1)if(i!=p)printf(" %d",i);
	puts("");
	return 0;
}