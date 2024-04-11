#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int x1, y1, x2, y2, x, y;
    cin >> x1 >> y1 >> x2 >> y2 >> x >> y;
    if ((x1 - x2) % x || (y1 - y2) % y || abs((x1 - x2) / x) % 2 != abs((y1 - y2) / y) % 2)
        cout << "NO";
    else
        cout << "YES";
}