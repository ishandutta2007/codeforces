#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;

void solve() {
    cout << 999 * 2 << endl;
    for (int i = 1; i <= 999; i++)
        cout << i << " " << 1 << " " << i << " " << 2 << endl;
    for (int i = 999; i >= 1; i--)
        cout << i << " " << 1 << " " << i << " " << 2 << endl;
}

int main() { 
    #ifndef ONLINE_JUDGE
        freopen("in", "rt", stdin);
        freopen("out", "wt", stdout);   
    #endif
    solve();
    return 0;
}