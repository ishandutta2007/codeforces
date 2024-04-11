#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int n, a, b;
vector <int> x;

int main(){
	int i, t, cur, ans = 0;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i){
		scanf("%d", &t);
		x.push_back(t);
	}
	scanf("%d%d", &a, &b);
	sort(x.begin(), x.end());
	x.resize(unique(x.begin(), x.end()) - x.begin());
	while(a != b){
		cur = a - 1;
		for(i = int(x.size()) - 1; i >= 0 && x[i] + cur > a; -- i)
			if(a - a % x[i] < cur && a - a % x[i] >= b) cur = a - a % x[i];
		a = cur;
		while(x.size() && a - a % x.back() < b) x.pop_back();
		ans ++;
	}
	printf("%d\n", ans);
	return 0;
}