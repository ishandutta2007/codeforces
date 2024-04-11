#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n;
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		printf("%d\n",(n+1)/10);
	}
	return 0;
}