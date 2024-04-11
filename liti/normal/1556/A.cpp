//be naame khodaa
#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <cstring>
#include <sstream>
#include <numeric>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back
#define sz(x) ((int)(x).size())

const int N = -1;

int main() {
    int t;
    cin >> t;

    for(int i = 0; i < t; i++) { 
        int x, y;
        cin >> x >> y; 
        if(x % 2 != y % 2) { 
            cout << "-1\n";
        } else if(x == 0 && y == 0) {
           cout << "0\n";
        } else if(x == y) {
            cout << "1\n";
        } else {
            cout << "2\n";
        }
    }
    return 0;
}