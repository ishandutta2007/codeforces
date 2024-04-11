#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    cout << "? " << 1 << " " << 2 << endl; cout.flush();
    cout << "? " << 1 << " " << 3 << endl; cout.flush();
    cout << "? " << 2 << " " << 3 << endl; cout.flush();

    int x, y, z; cin >> x >> y >> z;

    vector<int> A(n + 1);
    A[1] = (x + y - z) / 2;
    A[2] = x - A[1], A[3] = y - A[1];

    for (int i = 4; i <= n; ++i){
        cout << "? " << 1 << " " << i << endl; cout.flush();
        int v; cin >> v;
        A[i] = v - A[1];
    }

    cout << "!";

    for (int i = 1; i <= n; ++i) cout << " " << A[i];

    cout << endl;

    return 0;
}