#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const double EPS = 1e-9;
const int oo = 0x3f3f3f3;
const int MAXN = (int)1e5 + 10;

bool lookthis(string &s, string &t){
    int p1 = 0;
    for (int i = 0; i < s.length() && p1 < t.length(); ++i)
        if (s[i] == t[p1]) ++p1;
    return p1 == t.length();
}

string getString(int v){
    if (v == 0) return "0";
    string ans = "";
    while (v){
        char cur = (v % 10 + '0');
        ans = cur + ans;
        v /= 10;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s; cin >> s;

    for (int i = 0; i < 1000; i += 8){
        string cur = getString(i);
        if (lookthis(s, cur)){
            cout << "YES" << endl << cur << endl;
            exit(0);
        }
    }
    cout << "NO" << endl;

    return 0;
}