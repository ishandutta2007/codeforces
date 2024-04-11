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
		scanf("%d%d",&n,&s);
		printf("%d\n",s/(n-(n+1>>1)+1));
	}
	return 0;
}