
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 2e5 + 5;
int t, n;
string s;
bool b[N];

int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n >> s;
        fill(b, b + n, false);
        int first = -1;
        int final = -1;
        int finali = -1;
        for(int i = 1; i < n; i++) {
            if(s[i] < s[i - 1]) {
                b[i] = true;
                if(first == -1) {
                    first = i;
                }
                finali = i;
                final = s[i];
            }
        }
        int last = -1;
        for(int i = 0; i < first; i++) {
            if(s[i] >= last && s[i] <= s[first]) {
                b[i] = true;
                last = s[i];
            }
        }
        int prev0 = -1;
        int prev1 = -1;
        int first0 = -1;
        for(int i = 0; i < n; i++) {
            if(b[i]) {
                if(s[i] < prev1) {
                    cout << '-' << endl;
                    goto endloop;
                }
                prev1 = s[i];
            }else {
                if(s[i] < prev0) {
                    if(s[i] >= prev1) {
                        prev1 = s[i];
                        b[i] = true;
                        if(i > finali) {
                            finali = i;
                            final = s[i];
                        }
                        continue;
                    }else {
                        cout << '-' << endl;
                        goto endloop;
                    }
                }
                prev0 = s[i];
                if(first0 == -1) {
                    first0 = s[i];
                }
            }
        }
        if(final <= first0) {
            for(int i = 0; i < n; i++) {
                cout << (b[i] ? 1 : 2);
            }
            cout << endl;
        }else {
            cout << '-' << endl;
        }
        endloop:;
    }
}