#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-12;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

bool l[222222], r[222222];

bool go(VI& a, int t) {
    // cout << "t is " << t << endl;
    int n = a.size(); // 2 0 2 3 -2 -3
    deque< pair<int, int> > q;
    REP(i, n) a[i] -= i;
    REP(i, n) {
        while (!q.empty() && q.front().second <= i - t) q.pop_front();
        while (!q.empty() && q.back().first >= a[i]) q.pop_back();
        q.push_back(MP(a[i], i));
        // cout << q.front().first << " ";
        if (i >= t - 1 && q.front().first >= t - i) {
            l[i] = true;
        } else {
            l[i] = false;
        }
    }
    // cout << endl;
    // REP(i, n) cout << l[i] << " ";
    // cout << endl;
    REP(i, n) a[i] += i;

    reverse(ALL(a));
    REP(i, n) a[i] -= i;
    q.clear();
    REP(i, n) {
        while (!q.empty() && q.front().second <= i - t) q.pop_front();
        while (!q.empty() && q.back().first >= a[i]) q.pop_back();
        q.push_back(MP(a[i], i));
        if (i >= t - 1 && q.front().first >= t - i) {
            r[i] = true;
        } else {
            r[i] = false;
        }
    }
    REP(i, n) a[i] += i;
    reverse(ALL(a));
    // REP(i, n) cout << r[i] << " ";
    // cout << endl;

    REP(i, n) if (l[i] && r[n - 1 - i]) return true;
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<int> a;
    a.resize(n);
    REP(i, n) scanf("%d", &a[i]);
    // go(a, 3);
    int low = 1, high = n;
    while (low < high) {
        int mid = ((low + high) >> 1) + 1;
        if (go(a, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low << endl;
    return 0;
}