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
	int x1,x2,x3,x4,y1,y2,y3;
	scanf("%d%d%d%d",&x1,&x2,&x3,&x4);
	y3=max(x3,x4);
	y2=max(y3+1,max(x2,2*x4+1));
	y1=max(y2+1,x1);
	if(y1<=2*x1&&y2<=2*x2&&y3<=2*min(x3,x4))printf("%d\n%d\n%d\n",y1,y2,y3);
	else puts("-1");
	return 0;
}