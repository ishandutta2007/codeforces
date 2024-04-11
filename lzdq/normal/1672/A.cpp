#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,s;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		s=0;
		for(int i=1; i<=n; i++){
			int x; scanf("%d",&x);
			s^=x-1;
		}
		if(s&1) puts("errorgorn");
		else puts("maomao90");
	}
	return 0;
}