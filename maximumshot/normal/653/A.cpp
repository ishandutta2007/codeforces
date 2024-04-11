#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <set>
#include <string>
#include <tuple>
#include <fstream>
#include <stdio.h>
#include <cstring>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef pair< int, int > pii;

const int inf = 1000 * 1000 * 1000;
const ll inf64 = 1ll * inf * inf;
const double pi = acos(-1.0);

bool solve() {
    
    int n;
    cin >> n;
    
    vec< int > t(n);
    
    for(int i = 0;i < n;i++) cin >> t[i];
    
    sort(ALL(t));
    t.resize(unique(ALL(t)) - t.begin());
    
    for(int i = 1;i + 1 < (int)t.size();i++) {
        if(t[i + 1] - t[i - 1] <= 2) {
            cout << "YES\n";
            return true;
        }
    }

    cout << "NO\n";

	return true;
}

int main() {

	//while(solve());
	solve();
	
	return 0;
}