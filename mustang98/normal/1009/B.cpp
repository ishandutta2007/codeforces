#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

string s;

int main()
{
    //freopen("input.txt", "r", stdin);
    int cnt1 = 0;
    cin >> s;
    vector<char> v;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            cnt1++;
        } else {
            v.PB(s[i]);
        }
    }
    int cnt0 = 0;
    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == '0') cnt0++;
        else break;
    }
    for (int i = 0; i < cnt0; ++i) {
        cout << 0;
    }
    for (int i = 0; i < cnt1; ++i) {
        cout << 1;
    }
    for (int i = cnt0; i < v.size(); ++i) {
        cout << v[i];
    }

    return 0;
}