#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;++i)

int N,x,sum,y;

int main(){
	scanf("%d%d",&N,&x);
	rep(i,1,N){
		scanf("%d",&y);
		sum+=y;
	}
	if(sum<0)sum=-sum;
	if(sum==0)puts("0");else
	printf("%d\n",(sum-1)/x+1);
}