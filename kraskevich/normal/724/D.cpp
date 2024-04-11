#include <bits/stdc++.h>

using namespace std;

string s;
string x;
int n;
int m;

    
bool can(int len) {
    char last = x[len - 1];
    int cnt = 0;
    for (int i = 0; i < len; i++)
        if (x[i] == last)
            cnt++;
    int lastGood = -1;
    int lastMaybe = -1;
    int lastTaken = -1;
    int maybe = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] < last)
            lastGood = i;
        else if (s[i] == last) 
            lastMaybe = i;
        if (i - m + 1 >= 0) {
            if (lastTaken >= i - m + 1)
                continue;
            if (lastGood >= i - m + 1) {
                lastTaken = lastGood;
                continue;
            }
            if (lastMaybe >= i - m + 1) {
                lastTaken = lastMaybe;
                maybe++;
                continue;
            }
            return false;
        }
    }
    return maybe <= cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr); 
    cin >> m;   
    cin >> s;
    x = s;
    sort(x.begin(), x.end());
    n = s.length();
    int lo = 0;
    int hi = n;
    while (hi - lo > 1) {
        int mid = (lo + hi) / 2;
        if (can(mid)) {
            hi = mid;
        } else {
            lo = mid;
        }
    }
    cout << x.substr(0, hi) << endl;
    return 0;
}