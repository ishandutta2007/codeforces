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
#define TR(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();i++)
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
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

void p_out(int a, int b) {
    cout << a + 1 << " " << b + 1 << endl;
}

int main() {
    int n;
    cin >> n;
    vector<int> perm;
    perm.resize(n);
    REP(i, n) {
        scanf("%d", &perm[i]);
        --perm[i];
    }
    map< int, vector<VI> > cycles;
    vector<bool> vis;
    vis.resize(n);
    fill(ALL(vis), false);
    bool has_o = false;
    REP(i, n) {
        if (vis[i]) continue;
        vector<int> current;
        int t = i;
        while (!vis[t]) {
            vis[t] = true;
            current.push_back(t);
            t = perm[t];
        }
        cycles[current.size()].push_back(current);
        if (current.size() > 2) {
            if (current.size() & 1) {
                has_o = true;
            }
        }
    }
    if ((has_o && cycles.find(1) == cycles.end())
        || (cycles.find(1) == cycles.end() && cycles.find(2) == cycles.end())) {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> base;
    if (cycles.find(1) != cycles.end()) {
        vector<VI>& v = cycles[1];
        base = v.back();
        v.pop_back();
    } else {
        vector<VI>& v = cycles[2];
        base = v.back();
        v.pop_back();
    }
    cout << "YES" << endl;
    if (base.size() == 2) {
        p_out(base[0], base[1]);
    }
    TR(it1, cycles) {
        TR(it2, it1->second) {
            vector<int>& v = *it2;
            int p = 0;
            TR(it, v) {
                p_out(*it, base[p++ % base.size()]);
            }
        }
    }

    return 0;
}