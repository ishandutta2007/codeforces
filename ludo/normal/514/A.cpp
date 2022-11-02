#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define INF 2147483647
#define MOD 1000000007
#define MAX 100000

typedef long long ll;
typedef pair<int, int> pii;

string x;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    cin >> x;
    bool leading_zero = true;
    for (unsigned int i = 0; i < x.size(); i++) {
        if (x[i] >= '5' && (i != 0 || x[i] != '9' || !leading_zero)) {
            x[i] = '9' - x[i] + '0';
        }
        leading_zero = false;
    }
    cout << x << endl;

    return 0;
}