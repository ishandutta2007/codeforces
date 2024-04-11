#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200111, inf = 1000111222;

char buf[max_n];

string read_str() {
    scanf("%s", buf);
    return buf;
}

int n;

string solve(char sign, string a, string b) {
    string s;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < n; ++i) {
        while (!a.empty() && a.back() != sign) {
            s += a.back();
            a.pop_back();
        }
        while (!b.empty() && b.back() != sign) {
            s += b.back();
            b.pop_back();
        }
        s += sign;
        if (a.size()) a.pop_back();
        if (b.size()) b.pop_back();
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    s += a;
    s += b;
    return s;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int c0[3] = {0};
        int c1[3] = {0};
        string s[3];
        //int n;
        cin >> n;
        int k0 = 0;
        vector<string> v0;
        vector<string> v1;
        for (int i = 0; i < 3; ++i) {
            s[i] = read_str();
            for (char c : s[i]) {
                if (c == '0') c0[i]++;
                else c1[i]++;
            }
            if (c0[i] >= n) {
                v0.PB(s[i]);
            }
            if (c1[i] >= n) {
                v1.PB(s[i]);
            }
        }
        if (v0.size() >= 2) {
            printf("%s\n", solve('0', v0[0], v0[1]).c_str());
        } else {
            printf("%s\n", solve('1', v1[0], v1[1]).c_str());
        }
    }

    return 0;
}