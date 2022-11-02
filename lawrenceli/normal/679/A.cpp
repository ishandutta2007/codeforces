#include <bits/stdc++.h>

using namespace std;

int a[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 49};

int main() {
    int cnt = 0;
    for (int i = 0; i < 19; i++) {
        cout << a[i] << endl;
        string s; cin >> s;
        if (s == "yes") cnt++;
    }

    if (cnt <= 1) cout << "prime" << endl;
    else cout << "composite" << endl;
}