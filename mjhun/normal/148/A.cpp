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
#define mset(x,a) (memset((x),(a),sizeof(x)))
#define mcpy(x,y) (memcpy((x),(y),sizeof(x)))
using namespace std;
typedef long long ll;

bool w[100005];

int main(){
	fore(i,0,4){
		int a;
		scanf("%d",&a);
		for(int t=a;t<100005;t+=a)w[t]=true;
	}
	int b,r=0;
	scanf("%d",&b);
	fore(i,1,b+1)r+=w[i];
	printf("%d\n",r);
	return 0;
}