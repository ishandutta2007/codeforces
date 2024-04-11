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
int a[200005],b[200005];

int main(){
	scanf("%d",&n);
	fore(i,0,n)scanf("%d%d",a+i,b+i),a[i]--,b[i]--;
	if(n==3){puts("1 2 3");return 0;}
	putchar('1');
	int x=0;
	fore(_,0,n-1){
		if(a[a[x]]==b[x]||b[a[x]]==b[x])x=a[x];
		else x=b[x];
		printf(" %d",x+1);
	}
	puts("");
	return 0;
}