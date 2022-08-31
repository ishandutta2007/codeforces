#include <bits/stdc++.h>
using namespace std;

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int n, m;
	set<int> a;
    cin >> n >> m;
    for (int i=0; i<m; ++i) {
    	int k, f = 0;
    	cin >> k;
    	a.clear();
    	for (int j=0; j<k; ++j) {
    		int x;
    		cin >> x;
    		if (a.count(-x))
    			f = 1;
    		a.insert(x);
    	}
    	if (!f) {
    		cout << "YES\n";
    		return 0;
    	}	    				
    }
    cout << "NO\n";
    return 0;
}