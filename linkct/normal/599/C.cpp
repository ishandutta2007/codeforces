#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100005;

int n, seq[MAXN], pf[MAXN];

int main(){
	int i, minv, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &seq[i]);
		pf[i] = max(pf[i - 1], seq[i]);
	}
	for(i = n, minv = 0; i; -- i){
		if(!minv) minv = seq[i];
		else minv = min(minv, seq[i]);
		if(pf[i - 1] <= minv){
			++ ans;
			minv = 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}