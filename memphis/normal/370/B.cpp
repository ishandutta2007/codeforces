#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 105
#define rep(i,x,y) for(int i=x;i<=y;++i)

int a[maxn][maxn],N,m[maxn];
bool f[maxn];

int main(){
	scanf("%d",&N);
	rep(i,1,N){
		scanf("%d",&m[i]);
		rep(j,1,m[i])scanf("%d",&a[i][j]);
	}
	rep(i,1,N){
		memset(f,0,sizeof(f));
		rep(j,1,m[i])f[a[i][j]]=true;
		bool flag=true;
		rep(j,1,N){
			if(j==i)continue;
			bool ff=true;
			rep(k,1,m[j]) if(!f[a[j][k]])ff=false;
			if(ff)flag=false;
		}
		if(flag)puts("YES");
		else puts("NO");
	}
//	system("pause");
}