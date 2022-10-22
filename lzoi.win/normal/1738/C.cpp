#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,x,y,a;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		x=y=0;
		while(n--){
			scanf("%d",&a);
			if(a&1) x++;
			else y++;
		}
		if(!(x&1)&&(x>>1&1)||(x&1)&&!(x>>1&1)&&!(y&1)) puts("Bob");
		else puts("Alice");
	}
	return 0;
}