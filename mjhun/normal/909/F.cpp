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

int r[100005],n;

int main(){
	scanf("%d",&n);
	if(n%2){
		puts("NO");
		if(n<7)puts("NO");
		else {
			printf("YES\n7 3 6 5 1 4 2");
			for(int i=8;i<n;i+=2)printf(" %d %d",i+1,i);
			puts("");
		}
	}
	else {
		int m=n;
		while(m){
			int w=1<<(31-__builtin_clz(m));
			r[w-1]=w;r[w]=w-1;
			fore(i,w,m+1){
				int a=i,b=2*w-1-i;
				r[a]=b;r[b]=a;
			}
			m=2*w-2-m;
		}
		printf("YES\n%d",r[1]);
		fore(i,2,n+1)printf(" %d",r[i]);
		puts("");
		if(n==1<<(31-__builtin_clz(n)))puts("NO");
		else {
			printf("YES\n%d",n-1);
			for(int i=2;i<=n-4;i+=2)printf(" %d %d",i+1,i);
			printf(" %d %d %d\n",n,1,n-2);
		}
	}
	return 0;
}