#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(20);
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s == "0") {
        cout << "0\n";
        return 0;
    }
    int cnt = 0;
    for (char c : s)
        if (c == '0')
            cnt++;
    cout << 1;
    for (int i = 0; i < cnt; i++)
        cout << 0;
    cout << "\n";
}