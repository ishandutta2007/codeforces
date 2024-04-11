#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int a,b,c;
ll x,y,z;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d%d",&a,&b,&c);
		x=b*(ll)(1e8)+a;
		y=b;
		z=c;
		printf("%lld %lld %lld\n",x,y,z);
	}
	return 0;
}