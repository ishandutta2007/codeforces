#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=2e5+5;
int n;
pr a[MAXN];
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d",&a[i].first);
			a[i].second=i;
		}
		sort(a+1,a+n+1);
		printf("%d %d\n",a[1].second,a[n].second);
	}
	return 0;
}