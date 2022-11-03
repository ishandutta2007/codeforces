#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

#define maxn 300002
#define rep(i,x,y) for(int i=x;i<=y;++i)

int f[maxn],ans[maxn],N,M,l,r,x;

int get(int v){if(f[v]==v)return v;return f[v]=get(f[v]);}

int main(){
	
	scanf("%d%d",&N,&M);
	rep(i,1,N+1) f[i]=i;
	rep(i,1,M){
		scanf("%d%d%d",&l,&r,&x);
		for(int j=get(l);j<=r;++j,j=get(j))
			if(j^x)f[j]=j+1,ans[j]=x;
	}
	rep(i,1,N){
		if(i^1)putchar(' ');
		printf("%d",ans[i]);
	} putchar('\n');
//	system("pause");
}