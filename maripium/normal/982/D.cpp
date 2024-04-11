#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int n;
int a[N];
typedef pair<int,int> ii;
vector<ii> buff;
int bit[N];
int cnt[N];
void upd(int x,int v) {
	for (x; x <= n; x += x & -x) bit[x] += v;
}
int get(int x) {
	int res = 0;
	for (x; x > 0; x -= x & -x) res += bit[x];
	return res;
}

int find(int x) {
	int l = 0, r = n + 1;
	while(l < r) {
		int mid = l + r >> 1;
		if (get(mid) >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> a[i];
		buff.push_back(ii(a[i], i));
	}
	if (n == 1) return cout << a[1] + 1 << endl,0;
	sort(buff.begin(), buff.end(), greater<ii>());
	cnt[n] = 1;
	int res = 1;
	int sz = 0;
	set<int> st; st.insert(n);
	for (int i = 0;i < n;++i) {
		int id = buff[i].second;
		int val = get(id);
		int l = find(val), r = find(val + 1);
		upd(id, 1);
		cnt[r - l - 1]--;
		if (cnt[r - l - 1] == 0) st.erase(r - l - 1);
		cnt[id - l - 1]++; if (cnt[id - l - 1] == 1 && id - l - 1 != 0) st.insert(id - l - 1);
		cnt[r - id - 1]++; if (cnt[r - id - 1] == 1 && r - id - 1 != 0) st.insert(r - id - 1);
		if (st.size() == 1 && i < n - 1) {
			int nsz = (n - i - 1) / *st.begin();
			if (nsz >= sz) {
				sz = nsz;
				res = buff[i + 1].first + 1;
			}
		}  
	}
	cout << res;
}