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
#define	y1 PENAZZI

int x1[200005],x2[200005],y1[200005],y2[200005];
int n;
multiset<int> ax,bx,ay,by;

int main(){
	scanf("%d",&n);
	fore(i,0,n){
		scanf("%d%d%d%d",x1+i,y1+i,x2+i,y2+i);
		ax.insert(x1[i]);
		bx.insert(x2[i]);
		ay.insert(y1[i]);
		by.insert(y2[i]);
	}
	fore(i,0,n){
		ax.erase(ax.find(x1[i]));
		bx.erase(bx.find(x2[i]));
		ay.erase(ay.find(y1[i]));
		by.erase(by.find(y2[i]));
		if(*ax.rbegin()<=*bx.begin()&&*ay.rbegin()<=*by.begin()){
			printf("%d %d\n",*ax.rbegin(),*ay.rbegin());
			return 0;
		}
		ax.insert(x1[i]);
		bx.insert(x2[i]);
		ay.insert(y1[i]);
		by.insert(y2[i]);
	}
	assert(0);
	return 0;
}