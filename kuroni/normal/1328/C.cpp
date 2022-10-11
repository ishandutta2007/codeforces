#include <bits/stdc++.h>
using namespace std;

int t, n;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        bool eq = true;
        string le = "", ri = "";
        for (char &c : s) {
            if (!eq) {
                le += '0';
                ri += c;
            } else {
                if (c == '0') {
                    le += '0';
                    ri += '0';	
                } else if (c == '2') {
                    le += '1';
                    ri += '1';
                } else {
                    le += '1';
                    ri += '0';
                    eq = false;
                }
            }
        }
        cout << le << '\n' << ri << '\n';
    }
}