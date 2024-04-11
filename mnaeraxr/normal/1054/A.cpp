#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int x, y, z, t1, t2, t3;
    cin >> x >> y >> z >> t1 >> t2 >> t3;

    int stair = t1 * abs(x - y);

    int elev = t2 * (abs(z - x) + abs(x - y)) + 3 * t3;

    cout << (elev <= stair ? "YES" : "NO") << endl;
}