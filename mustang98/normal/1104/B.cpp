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

int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin >> s;
    vector<char> v;
    int cnt = 0;
    for (int c : s) {
        if (v.empty() || v.back() != c) {
            v.PB(c);
        } else {
            v.pop_back();
            ++cnt;
        }
    }
    cout << (cnt % 2 ? "Yes" : "No") << endl;

    return 0;
}