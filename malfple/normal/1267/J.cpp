#include <bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;

const int N = 2e6;
int cnt[N + 5];
vector<int> ambil, element;

int binser(int x) {
	int lo = 1;
	int hi = 2000;
	int ans = 1;
	while(lo <= hi) {
		int mid = (lo + hi) / 2;
		if(mid * mid <= x) {
			ans = mid;
			lo = mid + 1;
		}
		else hi = mid - 1;
	}
	int total = 0;
	for(int i = 0;i < element.size();i++) {
		int num = element[i];
		total += (num + ans - 1) / ans;
	}
	return total;
}

inline int calc(int x) {
	int total = 0;
	for(int i = 0;i < element.size();i++) {
		int num = element[i];
		int v = num / x;
		if(v * x != num) v++;
		if(v * x - num > v) return N;
		total += v;
	}
	return total;
}

int main(){
	int ntc;
	scanf("%d",&ntc);
	while(ntc--) {
		int n;
		scanf("%d",&n);
		for(int i = 0;i < n;i++) {
			int x;
			scanf("%d",&x);
			if(cnt[x] == 0) ambil.pb(x);
			cnt[x]++;
		}
		element.clear();
		for(int i = 0;i < ambil.size();i++) {
			element.pb(cnt[ambil[i]]);
			cnt[ambil[i]] = 0;
		}
		ambil.clear();
		sort(element.begin(), element.end());
		int ans = binser(element[0]);
		for(int i = 1;i * i <= element[0];i++) {
			int val = element[0] / i;
			if(val * i < element[0]) val++;
//			printf("CALC AT %d %d\n",i, val);
			ans = min(ans, calc(val));
			val++;
//			printf("CALC AT %d %d\n",i,val);
			ans = min(ans, calc(val));
		}
		printf("%d\n",ans);
	}
	return 0;
}