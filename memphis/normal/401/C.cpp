#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define maxn 1000005

int N,M;

int main(){
//freopen("1.in","r",stdin);
//freopen("1.out","w",stdout);

	scanf("%d%d",&N,&M);
	if(N>M+1 || M>(N+1<<1))puts("-1");
	else{
		for(;M>(N<<1);--M)putchar('1');
		for(;N&&M>1&&N<M+1;--N,--M,--M)
			printf("011");
		for(;N&&M;--N,--M)printf("01");
		for(;N;--N)putchar('0');
		for(;M;--M)putchar('1');
	}
}