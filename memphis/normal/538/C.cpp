#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
//#include<set>
//#include<map>
#include<queue>
//#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define rev(it,v) for(vector<int>::iterator it=v.begin();it!=v.end();it++)
using namespace std;
#define N 1000005
#define LL long long
#define inf 0x3f3f3f3f

int n,m,d[N],h[N],ans;

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,m) scanf("%d%d",d+i,h+i);
	ans=max(ans,h[1]+d[1]-1);
	if(d[m]!=n)
		ans=max(ans,h[m]+n-d[m]);
	rep(i,1,m-1){
		if(abs(h[i+1]-h[i])>d[i+1]-d[i]){
			puts("IMPOSSIBLE");
			return 0;
		}
		ans=max(ans,(d[i+1]-d[i]-abs(h[i+1]-h[i])>>1)+max(h[i+1],h[i]));
	}
	printf("%d\n",ans);
}