#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=5e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int a[maxn],m,n,r;
ll prea[maxn];
double ans;
int main(){
	scanf("%d",&m);
	while(m--){
		ri op;
		scanf("%d",&op);
		if(op&1){
			scanf("%d",&a[++n]);
			prea[n]=prea[n-1]+a[n];
			while(r+1<n&&(prea[r]+a[n])*(r+2)>(prea[r+1]+a[n])*(r+1))++r;
			ans=a[n]-(double)(prea[r]+a[n])/(r+1);
		}
		else printf("%.12lf\n",ans);
	}
	return 0;
}