
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int n, q;
string s[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> s[0] >> s[1];
        int i = 0, j = 0, j2 = 0;
        while(i < n) {
            if(s[j][i] <= '2') {
                if(j == j2) {
                    i++;
                }else {
                    cout << "NO" << endl;
                    goto endloop;
                }
            }else {
                if(j == j2) {
                    j2 = j;
                    j = (j + 1) % 2;
                }else {
                    i++;
                    j2 = j;
                }
            }
        }
        cout << (j == 1 ? "YES" : "NO") << endl;
        endloop:;
    }
}