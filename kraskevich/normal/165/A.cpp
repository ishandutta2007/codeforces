#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

#define pb push_back
#define F first
#define S second
typedef long long ll;

int main() {
    int n, res = 0;
    cin >> n;
    int x[n], y[n];
    for(int i = 0; i < n; ++i)
            cin >> x[i] >> y[i];
    for(int i = 0; i < n; ++i) {
            bool r = false,  l = false, u = false, d = false;
            for(int j = 0; j < n; ++j) {
                    if(i == j)
                         continue;
                    if(x[i] == x[j])
                            if(y[i] > y[j])
                                    d = true;
                            else
                                u = true;
                    if(y[i] == y[j])
                            if(x[i] > x[j])
                                    l = true;
                            else
                                r = true;
            }
            if(l && r && u && d)
                 ++res;
    }
    cout << res;
    cin >> n; 
    return 0;
}