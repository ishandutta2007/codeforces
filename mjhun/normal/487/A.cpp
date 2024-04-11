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

int e,r;

int main(){
	int hy,ay,dy;
	int hm,am,dm;
	int H,A,D;
	scanf("%d%d%d%d%d%d%d%d%d",&hy,&ay,&dy,&hm,&am,&dm,&H,&A,&D);
	if(ay<=dm){
		e=A*(dm+1-ay);
		ay=dm+1;
	}
	if(am<=dy){
		printf("%d\n",e);
		return 0;
	}
	r=(am-dy)*D;
	fore(i,ay,205){
		int aa=i-ay;
		fore(j,dy,am){
			int dd=j-dy;
			int t=(hm+i-dm-1)/(i-dm);
			int hh=max(0,t*(am-j)+1-hy);
			r=min(r,aa*A+dd*D+hh*H);
		}
	}
	printf("%d\n",r+e);
	return 0;
}