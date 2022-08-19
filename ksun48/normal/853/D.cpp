#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	LL ans = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		ans += a[i];
		a[i] /= 1000;
	}
	int sums[n+1];
	sums[0] = 0;
	for(int i = 0; i < n; i++){
		sums[i+1] = sums[i] + a[i];
	}

	int best = 0;
	for(int i = 0; i <= n; i++){
		best = max(best, min(sums[i] - sums[0], 10*(sums[n] - sums[i]) ));
	}
	for(int i = 0; i < n; i++){
		if(a[i] == 2) continue;
		if(1){
			// case 1
			int f = min(sums[i], a[i]*10);
			int numleft = sums[i] - f;
			int s = i+1;
			int e = n;
			while(s + 1 < e){
				int m = (s+e)/2;
				int t1 = sums[m] - sums[i+1];
				int t2 = sums[n] - sums[m];
				if(t1 + numleft>= 10*t2){
					e = m;
				} else {
					s = m;
				}
			}
			best = max(best, f + min(numleft + (sums[s] - sums[i+1]), 10*(sums[n] - sums[s]) ));
			best = max(best, f + min(numleft + (sums[e] - sums[i+1]), 10*(sums[n] - sums[e]) ));
		}
		if(1){
			int f = min(a[i], 10*(sums[n] - sums[i+1]) );
			int numleft = 10*(sums[n] - sums[i+1]) - f;
			int s = 0;
			int e = i;
			while(s + 1 < e){
				int m = (s+e) / 2;
				int t1 = sums[m] - sums[0];
				int t2 = sums[i] - sums[m];
				if(t1 >= 10*t2 + numleft){
					e = m;
				} else {
					s = m;
				}
			}
			best = max(best, f + min(sums[s] - sums[0], 10*(sums[i] - sums[s]) + numleft));
			best = max(best, f + min(sums[e] - sums[0], 10*(sums[i] - sums[e]) + numleft));
		}
	}
	LL q = best;
	cout << ans - 100*q << endl;
}