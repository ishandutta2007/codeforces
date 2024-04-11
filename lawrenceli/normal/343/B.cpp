#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define rep(i, n) for (int i=0, _##i=(n); i<_##i; i++)
#define repi(i, n) for (typeof(n.begin()) i=n.begin(), _##i = n.end(); i != _##i; i++)
#define repv(i, n) for (int i=0, _##i=((n).size()); i<_##i; i++)
#define print(x) cerr << #x << " is " << x << endl;

typedef long long ll;
typedef pair<int, int> pii;

template <class T> T min(T a, T b, T c) { return min(a, min(b, c)); }
template <class T> T max(T a, T b, T c) { return max(a, max(b, c)); }
template <class T> void setmin(T& a, T b) { if (b < a) a = b; }
template <class T> void setmax(T& a, T b) { if (b > a) a = b; }

const int MAXN = 100100;

int n;
char str[MAXN];
list<char> lst;
typeof(lst.begin()) it1, it2;

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    scanf("%s", str); n = strlen(str);
    for (int i=0; i<n; i++) lst.push_back(str[i]);
    it1 = lst.begin();
    while (it1 != lst.end()) {
        it2 = it1; ++it2;
        if (*it1 == *it2) {
            it1 = lst.erase(it1); it1 = lst.erase(it1);
            if (it1 != lst.begin()) --it1;
        } else ++it1;
    }
    if (lst.empty()) printf("Yes\n");
    else printf("No\n");
}