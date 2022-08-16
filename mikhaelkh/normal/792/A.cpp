#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    vector<int> v;
    int n;
    cin >> n;
    for (int i=0; i<n; ++i) {
    	int a;
    	cin >> a;
    	v.push_back(a);
    }
    sort(v.begin(), v.end());
    int mn = INT_MAX;
    for (int i=1; i<n; ++i)
    	mn = min(mn, v[i]-v[i-1]);
    int res = 0;
    for (int i=1; i<n; ++i)
    	if (v[i]-v[i-1] == mn)
    		++res;
    cout << mn << ' ' << res << endl;

    
    return 0;
}