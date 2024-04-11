#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
#define rep(i,x,y) for(int i=x;i<=y;++i)

int T,n,p;

int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&p);
		int tmp=n*2+p;
		rep(i,1,n){
			rep(j,i+1,n){
				--tmp;
				printf("%d %d\n",i,j);
				if(!tmp)break;
			}
			if(!tmp)break;
		}
	}
}