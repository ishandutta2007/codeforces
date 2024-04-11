#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;

const int N = 100005;
int n;
struct E{
	int a, b;
	bool operator <(const E &x) const{
		return -a + b < -x.a + x.b; 
	} 
}e[N];
LL ans = 0;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &e[i].a, &e[i].b);
	}
	sort(e + 1, e + 1 + n);
	for(int i = 1; i <= n; i++) {
		ans += (LL)e[i].a * (i - 1) + (LL)e[i].b * (n - i);
	} 
	printf("%lld\n", ans);
	return 0;
}