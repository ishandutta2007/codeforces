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
	int x,y,z,t1,t2,t3;
	scanf("%d%d%d%d%d%d",&x,&y,&z,&t1,&t2,&t3);
	int a=abs(x-y)*t1;
	int b=abs(x-z)*t2+abs(x-y)*t2+t3*3;
	//printf(" %d %d\n",a,b);
	puts(b<=a?"YES":"NO");
	return 0;
}