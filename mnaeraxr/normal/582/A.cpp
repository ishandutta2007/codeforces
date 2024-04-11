#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;
	multiset<int> ms;
	vector<int> ans(n);
	for (int i = 0; i < n * n; ++i){
		int v; cin >> v;
		ms.insert(v);
	}

	for (int i = 0; i < n; ++i){
		int v = *ms.rbegin();
		ans[i] = v;
		ms.erase(ms.find(v));

		for (int j = 0; j < i; ++j){
			int g = __gcd(ans[j],v);
			auto it = ms.find(g);
			if (it == ms.end()) exit(0);			
			ms.erase(it);

			it = ms.find(g);
			if (it == ms.end()) exit(0);			
			ms.erase(it);
		}
	}

	for (int i= 0; i < n; ++i)
		cout << ans[i] << " ";
	cout << endl;


	return 0;
}