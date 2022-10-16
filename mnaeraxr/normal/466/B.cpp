#include <bits/stdc++.h>

using namespace std;

int main()
{
	long long n, a, b;
	cin >> n >> a >> b;
	long long area = n * 6;

	pair<long long, pair<long long, long long>> ans;
	ans.first = 2000000000000000000LL;

	for (auto va = a; ; ++va){
		auto vb = (area + va - 1) / va;
		bool flag = vb < b;
		vb = max(vb, b);
		if (va > vb) break;
		auto cur = make_pair(va, vb);
		auto ccur = make_pair(va * vb, cur);
		ans = min(ans, ccur);
		if (flag) break;
	}

	for (auto vb = b; ; ++vb){
		auto va = (area + vb - 1) / vb;
		bool flag = va < a;
		va = max(va, a);
		if (vb > va) break;
		auto cur = make_pair(va, vb);
		auto ccur = make_pair(va * vb, cur);
		ans = min(ans, ccur);
		if (flag) break;
	}

	cout << ans.first << endl;
	cout << ans.second.first << " " << ans.second.second << endl;
}