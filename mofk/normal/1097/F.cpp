#include <bits/stdc++.h>

using namespace std;

int n, q;
bitset <7001> a[100005];
bitset <7001> dvs[7001];
int mob[7001];
bitset <7001> vec[7001];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 1; i <= 7000; ++i) for (int j = i; j <= 7000; j += i) dvs[j].set(i);
    for (int i = 1; i <= 7000; ++i) mob[i] = 1;
    for (int i = 2; i * i <= 7000; ++i) for (int j = i * i; j <= 7000; j += i * i) mob[j] = 0;
    for (int i = 1; i <= 7000; ++i) for (int j = 1; j * i <= 7000; ++j) if (mob[j]) vec[i].set(i * j);
    cin >> n >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, v;
            cin >> x >> v;
            a[x] = dvs[v];
        }
        else if (type == 2) {
            int x, y, z;
            cin >> x >> y >> z;
            a[x] = a[y] ^ a[z];
        }
        else if (type == 3) {
            int x, y, z;
            cin >> x >> y >> z;
            a[x] = a[y] & a[z];
        }
        else {
            int x, v;
            cin >> x >> v;
            cout << ((a[x] & vec[v]).count() & 1);
        }
    }
    cout << endl;
    return 0;
}