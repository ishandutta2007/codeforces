#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<string,int> psi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	set<int> inside;
	set<int> seen;
	vector<psi> event(n);

	for (int i = 0; i < n; ++i){
		cin >> event[i].first >> event[i].second;
		auto cur = seen.find(event[i].second);
		
		if (event[i].first == "-" && cur == seen.end())
			inside.insert(event[i].second);

		if (cur == seen.end())
			seen.insert(event[i].second);
	}

	int ans = inside.size();

	for (auto p : event){
		if (p.first == "-")
			inside.erase(p.second);
		else
			inside.insert(p.second);
		ans = max(ans, (int)inside.size());
	}

	cout << ans << endl;

	return 0;
}