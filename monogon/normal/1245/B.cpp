
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n, a, b, c;
string s;
int R, P, S;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a >> b >> c >> s;
        R = P = S = 0;
        for(char c : s) {
            if(c == 'R') R++;
            if(c == 'P') P++;
            if(c == 'S') S++;
        }
        int amt = min(R, b) + min(P, c) + min(S, a);
        string t = "";
        if(amt * 2 >= n) {
            cout << "YES" << endl;
            for(int i = 0; i < n; i++) {
                if(s[i] == 'R' && b > 0) { t.push_back('P'); b--; }
                else if(s[i] == 'P' && c > 0) { t.push_back('S'); c--; }
                else if(s[i] == 'S' && a > 0) { t.push_back('R'); a--; }
                else t.push_back('-');
            }
            int i = 0;
            while(a > 0) {
                while(t[i] != '-') i++;
                t[i] = 'R';
                a--;
            }
            while(b > 0) {
                while(t[i] != '-') i++;
                t[i] = 'P';
                b--;
            }
            while(c > 0) {
                while(t[i] != '-') i++;
                t[i] = 'S';
                c--;
            }
            cout << t << endl;
        }else {
            cout << "NO" << endl;
        }
    }
}