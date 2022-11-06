
#include <utility>
#include <iostream>
#include <cmath>
#include <deque>
#include <string>
#include <time.h>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <bitset>
#include <fstream>

#define pii pair<ll,ll>
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
using namespace std;
#define N 13
#define OFF 400001
#define MOD 998244353
#define C 13000
#define NN 1000000
ll n, m, k, x, y;
ll queries = 0;

double d[15005];

int main() {
    srand(time(0));
    cin >> n;
    while (n--) {
        cin >> x;
        cout << (x + 1) / 2 << "\n";
    }
    return 0;
}