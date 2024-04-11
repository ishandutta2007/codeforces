#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int dist(string a, string b) {
    int res = 0;
    for (int i = 0; i < a.length(); i++)
        if (a[i] != b[i])
            res++;
    return res;
}

string to_str(int n) {
    string s = to_string(n);
    while (s.length() < 2)
        s = '0' + s;
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    int x;
    cin >> x;
    string s;
    cin >> s;
    string res = "11:11";
    int lo = 1;
    int hi = 12;
    if (x == 24) {
        lo = 0; 
        hi = 23;
    }
    for (int h = lo; h <= hi; h++)
        for (int m = 0; m <= 59; m++) {
            string cur = to_str(h) + ":" + to_str(m);
            if (dist(cur, s) < dist(res, s))
                res = cur;
        }
    cout << res << endl;
    return 0;
}