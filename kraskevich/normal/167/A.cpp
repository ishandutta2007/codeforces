#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <string>
#include <map>
#include <stack>
#include <deque>
using namespace std;

#define F first
#define S second
#define m_p make_pair
#define p_b push_back
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cout.setf(ios::fixed);
    cout.precision(10);
    
    ll n, a, d;
    cin >> n >> a >> d;
    double last = -1;
    for(int i = 0; i < n; ++i) {
            ll t, v;
            cin >> t >> v;
            double fin;
            if((double)v * v / (2.0 * a) > d)
                         fin = (double)t + sqrt((double)(2 * d) / (double)a);
            else {
                 double x = (double)d - (double)(v * v) / (double)(2 * a);
                 fin = t + (double)v / (double)a + x / (double)v;
            }
            if(last > fin)
                    fin = last;
            cout << fin << endl;
            last = fin;
    }
    return 0;
}