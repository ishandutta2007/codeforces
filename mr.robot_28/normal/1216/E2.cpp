#include <bits/stdc++.h>

using namespace std;

long long get(long long r) {
	return (r + 1) * r / 2;
}

long long sumto(long long r, int need) {
	long long pw = 1;
	long long sum = 0;
	long long add = 0;
	for (int len = 1; ; ++len) {
		if (pw * 10 - 1 < r) {
			long long cnt = pw * 10 - pw;
			if (need) {
				sum += add * cnt + get(cnt) * len;
				add += cnt * len;
			} else {
				sum += cnt * len;
			}
		} else {
			long long cnt = r - pw + 1;
			if (need) {
				sum += add * cnt + get(cnt) * len;
			} else {
				sum += cnt * len;
			}
			break;
		}
		pw *= 10;
	}
	return sum;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int q;
	cin >> q;
	while (q--) {
		long long k;
		cin >> k;
		--k;
		
		long long l = 1	, r = 1e9;
		long long res = -1;
		while (r - l >= 0) {
			long long mid = (l + r) >> 1;
			if (sumto(mid, 1) > k) {
				res = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		k -= sumto(res - 1, 1);
		
		l = 1, r = res;
		long long num = -1;
		while (r - l >= 0) {
			int mid = (l + r) >> 1;
			if (sumto(mid, 0) > k) {
				num = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		
		cout << to_string(num)[k - sumto(num - 1, 0)] << endl;
	}
	
	return 0;
}