#include <string>
#include <time.h>
#include <vector>
#include <algorithm>
#include <bitset>
#include <utility>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <cmath>
#include <deque>

#define pii pair<ll,ll>
#define MOD 1000000007
#define mp make_pair
#define X first
#define Y second
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll a[100500], b[100500];
deque<ll> f;
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        if (i % 2)
            f.push_back(a[i]);
        else
            f.push_front(a[i]);
    }
    for (auto i : f) {
        cout << i << " ";
    }
    return 0;
}