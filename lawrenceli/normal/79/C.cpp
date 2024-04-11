#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>
#include <set>

using namespace std;

const int MAXN = 100100; //length of string

string s;
int n;
string b[15];
bool good[15][MAXN];

multiset<int> st;

void init(int c) {
    for (int i=0; i+b[c].length()<=s.length(); i++) {
        good[c][i] = (s.substr(i, b[c].length()) == b[c]);
        if (good[c][i])
            st.insert(i + b[c].length());
    }
}

int cur[15];

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> s >> n;
    for (int i=0; i<n; i++) cin >> b[i];

    for (int i=0; i<n; i++) init(i);

    int lt = 0, rt = 0;
    int ans = 0, pos = 0;
    while (rt <= s.length()) {
        if (!st.empty() && rt >= *st.begin()) {
            for (int i=0; i<n; i++)
                if (good[i][lt])
                    st.erase(st.find(lt + b[i].length()));
            lt++;
        } else {
            if (rt - lt > ans)
                ans = rt - lt, pos = lt;
            rt++;
        }
    }

    cout << ans << ' ' << pos << endl;
    return 0;
}