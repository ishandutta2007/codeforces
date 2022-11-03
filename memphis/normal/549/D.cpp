#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
#include<cmath>
#include<set>
#include<vector>
//#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int P=1000000007;
const int N=105;

int n,m,a[N][N],b[N][N],cnt;
char s[N][N];

int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) scanf("%s",s[i]+1);
	rep(i,1,n) rep(j,1,m) if(s[i][j]=='B') a[i][j]=1;else a[i][j]=-1;
	dep(i,n,1) dep(j,m,1){
		if(a[i][j]==b[i][j]) continue;
		cnt++;
		int z=a[i][j]-b[i][j];
		rep(u,1,i) rep(v,1,j) b[u][v]+=z;
	}
	printf("%d\n",cnt);
}