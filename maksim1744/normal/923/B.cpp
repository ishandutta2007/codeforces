#include <bits/stdc++.h>

using namespace std;

const bool debug = false;

int main(int argc, char const *argv[])
{
    if (debug) {
        freopen("input.txt", "r", stdin);
    }
    long long n;
    cin >> n;
    set< pair< long long, int > > s;
    vector< long long > v(n);
    vector< long long > t(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    long long st = 0;
    long long nowv = 0;
    long long nowc = 0;
    for (int i = 0; i < n; i++) {
        nowv = 0;
        nowc++;
        s.insert(pair< long long, int > (v[i] + st, i));
        while (!s.empty() && s.begin() -> first <= st + t[i]) {
            nowv += s.begin() -> first - st;
            s.erase(s.begin());
            nowc--;
        }
        nowv += nowc * t[i];
        st += t[i];
        cout << nowv << ' ';
    }
    return 0;
}