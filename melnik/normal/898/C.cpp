#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

map <string, set<string>> a;

bool IsSuffix(string s1, string s2) {
	reverse(s1.begin(), s1.end());
	reverse(s2.begin(), s2.end());
	int sz1 = s1.size();
	int sz2 = s2.size();
	if (sz1 > sz2)
		return false;
	for (int i = 0; i < sz1; ++i)
		if (s1[i] != s2[i])
			return false;
	return true;
}

vector <string> to_del;

void Update(string t) {
    to_del.clear();
	for (auto it1 = a[t].begin(); it1 != a[t].end(); ++it1)
		for (auto it2 = a[t].begin(); it2 != a[t].end(); ++it2) {
			if (it1 == it2)
				continue;
			if (IsSuffix(*it1, *it2))
				to_del.pb(*it1);
				// a[t].erase(it1);
		}
	for (auto s1 : to_del)
		a[t].erase(s1);
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	string t;
    	cin >> t;
    	int x;
    	cin >> x;
    	while (x--) {
    		string num;
    		cin >> num;
    		a[t].insert(num);
    		Update(t);
    	}
    }

    cout << a.size() << endl;
    for (auto it = a.begin(); it != a.end(); ++it) {
    	cout << it -> f << ' ';
    	cout << it -> s.size() << ' ';
    	for (auto it2 = it -> s.begin(); it2 != it -> s.end(); ++it2)
    		cout << *it2 << ' ';
    	cout << endl;
    }
    return 0;
}