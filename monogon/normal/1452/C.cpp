
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        string s;
        cin >> s;
        int n = s.length();
        int s1 = 0, s2 = 0, cnt = 0;
        rep(i, 0, n) {
            if(s[i] == '(') {
                s1++;
            }else if(s[i] == ')') {
                if(s1 > 0) {
                    s1--;
                    cnt++;
                }
            }else if(s[i] == '[') {
                s2++;
            }else {
                if(s2 > 0) {
                    s2--;
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}