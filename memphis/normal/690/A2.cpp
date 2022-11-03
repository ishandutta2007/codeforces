#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=100005;

int n;

int main(){
	scanf("%d",&n);
	if(n&1) printf("%d\n",(n+1>>1)-1);
	else{
		int t=1;
		while(n>=t<<1) t<<=1;
		printf("%d\n",n-t>>1);
	}
}