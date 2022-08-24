#include <bits/stdc++.h>
using namespace std;
int n, x, y;
bool mark[20];
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i = 0; i <= 9; i++) {
        vector < int > check;
        for (int j = 1; j <= n; j++) {
            if (j & (1 << i)) check.push_back(j);
        }
        if (check.size() == 0) continue;
        cout << "? " << check.size() << " ";
        for (int i = 0; i < check.size(); i++) cout << check[i] << " ";
        cout << endl;
        int ans;
        cin >> ans;
        if (ans == x * (check.size() % 2)) {
            mark[i] = false;
        }
        else mark[i] = true;
    }
    int ind = -1;
    for (int i = 0; i <= 9; i++) {
        if (mark[i]) ind = i;
    }
    int a1 = 0;
    int a2 = 0;
    a1 |= (1 << ind);
    for (int i = 0; i <= 9; i++) {
        if (i == ind) continue;
        vector < int > check;
        for (int j = 1; j <= n; j++) {
            if ((j & (1 << i)) | (j & (1 << ind))) check.push_back(j);
        }
        if (check.size() == 0) continue;
        cout << "? " << check.size() << " ";
        for (int i = 0; i < check.size(); i++) cout << check[i] << " ";
        cout << endl;
        int ans;
        cin >> ans;
        if (ans == x * (check.size() % 2)) {
            if (mark[i]) {
                a2 |= (1 << i);
            }
            else {
                a1 |= (1 << i);
                a2 |= (1 << i);
            }
        }
        else {
            if (mark[i]) {
                a1 |= (1 << i);
            }
        }
    }
    if (a1 > a2) swap(a1, a2);
    cout << "! " << a1 << " " << a2 << endl;
    return 0;
}