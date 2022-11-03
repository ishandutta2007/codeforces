#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>

using namespace std;

#define maxn 101
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)

int gcd(int a,int b){if(b==0)return a;return gcd(b,a%b);}

int N,a,b,Max,t;

int main(){
//	freopen("game.in","r",stdin);
//	freopen("game.out","w",stdout);
	
//	scanf("%d",&t);
//	while(t--){
		scanf("%d",&N);
		scanf("%d",&a); 
		Max=a;
		rep(i,2,N){
			scanf("%d",&b);
			Max=max(Max,b);
			a=gcd(a,b);
		}
		if((Max/a-N)&1)puts("Alice");
		else puts("Bob");
//	}
}