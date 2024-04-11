#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const double eps=1e-10;
inline double qpow(double x,int y){
	double ret=1;
	for(;y;x*=x,y>>=1)
		if(y&1){
			ret*=x;
			if(ret<eps)return 0;
		}
	return ret;
}
double ans;
int m,n;
int main(){
	scanf("%d%d",&m,&n);
	for(double i=1;i<=m;i+=1)ans+=(qpow(i/m,n)-qpow((i-1)/m,n))*i;
	printf("%lf",ans);
	return 0;
}