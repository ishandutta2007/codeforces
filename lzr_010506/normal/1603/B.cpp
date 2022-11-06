#include<bits/stdc++.h>
#define maxn 200005
#define int long long
#define INF 0x3f3f3f3f
using namespace std;
int a[maxn];
signed main() {
	int T;
	cin >> T;
	while(T--) {
		int x,y;
		scanf("%lld%lld",&x,&y);
		if(x == y) {
			cout << x << endl;
			continue;
		}
		if(x>y) {
			printf("%lld\n",x+y);
			continue;
		}else {
			printf("%lld\n",y-(y-x)%x/2);
		}

	}
}