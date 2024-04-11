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

#include <unordered_set>
#include <unordered_map>

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

multiset<int> s[1 << 7];
multiset<int> whole;

const int N = 200007;

int w[N];
LL a[3];

int main() {
    int n;
    cin >> n;
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);

    map<int, int> attr;

    REP(i, n) {
        scanf("%d", &w[i]);
        int mask = 0;
        for (int j = 1; j < 8; ++j) {
            LL sum = 0;
            REP(k, 3) {
                if ((j >> k) & 1) {
                    sum += a[k];
                }
            }
            if (sum >= w[i]) {
                mask |= 1 << (j - 1);
            }
        }
        s[mask].insert(w[i]);
        whole.insert(w[i]);

        attr[w[i]] = mask;
    }

    if (s[0].size() > 0) {
        cout << -1 << endl;
        return 0;
    }

    int mask;

    int ans = 0;

    mask = 1 << 6;
    while (s[mask].size()) {
        int v = *s[mask].begin();
        s[attr[v]].erase(s[attr[v]].find(v));
        whole.erase(whole.find(v));
        ++ans;
    }

    mask = (1 << 6) + (1 << 5);
    while (s[mask].size()) {
        int v1 = *s[mask].begin();
        multiset<int>::iterator iter = whole.upper_bound(a[0]);
        if (iter != whole.begin()) {
            --iter;
            int v2 = *iter;
            assert(v1 != v2);
            whole.erase(whole.find(v1));
            whole.erase(whole.find(v2));
            s[attr[v1]].erase(s[attr[v1]].find(v1));
            s[attr[v2]].erase(s[attr[v2]].find(v2));
        } else {
            whole.erase(whole.find(v1));
            s[attr[v1]].erase(s[attr[v1]].find(v1));
        }
        ++ans;
    }

    mask = (1 << 6) + (1 << 5) + (1 << 4);
    while (s[mask].size()) {
        int v1 = *s[mask].begin();
        multiset<int>::iterator iter = whole.upper_bound(a[1]);
        if (iter != whole.begin()) {
            --iter;
            int v2 = *iter;
            assert(v1 != v2);
            whole.erase(whole.find(v1));
            whole.erase(whole.find(v2));
            s[attr[v1]].erase(s[attr[v1]].find(v1));
            s[attr[v2]].erase(s[attr[v2]].find(v2));
        } else {
            whole.erase(whole.find(v1));
            s[attr[v1]].erase(s[attr[v1]].find(v1));
        }
        ++ans;
    }

    mask = (1 << 6) + (1 << 5) + (1 << 4) + (1 << 2);
    while (s[mask].size()) {
        int v1 = *s[mask].begin();
        multiset<int>::iterator iter = whole.upper_bound(a[2]);
        if (iter != whole.begin()) {
            --iter;
            int v2 = *iter;
            assert(v1 != v2);
            whole.erase(whole.find(v1));
            whole.erase(whole.find(v2));
            s[attr[v1]].erase(s[attr[v1]].find(v1));
            s[attr[v2]].erase(s[attr[v2]].find(v2));
        } else {
            whole.erase(whole.find(v1));
            s[attr[v1]].erase(s[attr[v1]].find(v1));
        }
        ++ans;
    }

    while (true) {
        bool good = true;
        multiset<int>::iterator iter1 = whole.upper_bound(a[2]);
        if (iter1 == whole.begin()) {
            good = false;
        } else {
            --iter1;
        }
        if (!good) {
            break;
        }

        multiset<int>::iterator iter2 = whole.upper_bound(a[1]);
        do {
            if (iter2 == whole.begin()) {
                good = false;
            } else {
                --iter2;
            }
        } while (good && iter2 == iter1);

        if (!good) break;

        multiset<int>::iterator iter3 = whole.upper_bound(a[0]);
        do {
            if (iter3 == whole.begin()) {
                good = false;
            } else {
                --iter3;
            }
        } while (good && (iter3 == iter1 || iter3 == iter2));
        
        if (!good) {
            break;
        }

        whole.erase(iter1);
        whole.erase(iter2);
        whole.erase(iter3);
        ++ans;
    }

    while (!whole.empty()) {
        multiset<int>::iterator iter1 = whole.upper_bound(a[2]);
        assert(iter1 != whole.begin());
        --iter1;

        multiset<int>::iterator iter2 = whole.upper_bound(a[1] + a[0]);
        bool good = true;
        do {
            if (iter2 == whole.begin()) {
                good = false;
            } else {
                --iter2;
            }
        } while (good && iter2 == iter1);

        whole.erase(iter1);
        if (good) {
            whole.erase(iter2);
        }
        ++ans;
    }

    cout << ans << endl;
    return 0;
}