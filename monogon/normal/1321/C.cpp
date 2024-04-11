
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    for(char c = 'z'; c > 'a'; c--) {
        for(int i = 0; i < (int) s.length(); i++) {
            if(s[i] == c && ((i > 0 && s[i - 1] == c - 1) || (i < (int) s.length() - 1 && s[i + 1] == c - 1))) {
                s.erase(s.begin() + i);
                i--;
                if(i >= 0) i--;
            }
        }
    }
    cout << n - (int) s.length() << endl;
}