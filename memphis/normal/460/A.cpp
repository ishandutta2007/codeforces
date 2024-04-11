#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<map>
#include<ctime>
//#include<iostream> 
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
//#define N
//#define M
#define ll long long
#define lb long double
#define inf 0x7f7f7f7f
using namespace std;

int n,m,ans;

int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);

	scanf("%d%d",&n,&m);
	ans=n;
	rep(i,1,100000){
		if(n+i-1<i*m) break;
		ans=n+i;
	}
	printf("%d\n",ans);
}