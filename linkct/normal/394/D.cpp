#include <cstdio>
#include <algorithm>
using namespace std;

int seq[1005], n, basement, step;

inline bool check(int span){
	int minDelta, i, j, maxStep = (seq[n] - seq[1] + (span << 1)) / (n - 1), base;
	for(i = 0; i <= maxStep; ++ i){
		minDelta = span << 1;
		base = seq[1] + span;
		for(j = 2; j <= n; ++ j){
			int down = base + (j - 1) * i - seq[j] - span;
			if(down > 0){
				if(down > minDelta)
					break;
				base -= down;
				minDelta -= down;
			}else if(down < -(span << 1))
				break;
			else minDelta = min(minDelta, (span << 1) + down);
			if(minDelta < 0)
				break;
		}
		if(j == n + 1){
			basement = base;
			step = i;
			return true;
		}
	}
	return false;
}
int main(){
	int i, l, r, mid;
	scanf("%d", &n);
	for(i = 1; i <= n; ++ i)
		scanf("%d", &seq[i]);
	sort(seq + 1, seq + 1 + n);
	l = 0;
	r = ((seq[n] - seq[1]) >> 1) + 2;
	while(l < r){
		mid = (l + r) >> 1;
		if(check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n%d %d\n", r, basement, step);
	return 0;
}