#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 301;

string s = "";
vector<string> a, b, c;
int n, kol[N];

bool cmp(string &a, string &b) {
    return a.size() < b.size();
}

void go() {
    cout << "? 1 " << n << endl;
    for (int i = 0; i < n * (n + 1) / 2; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        a.pb(s);
    }

    cout << "? 2 " << n  << endl;
    for (int i = 0; i < n * (n - 1) / 2; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        a.pb(s);
    }
    sort(a.begin(), a.end());
    int cur = 1;
    if (a[0] != a[1])
        c.pb(a[0]);
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == a[i - 1])
            cur++;
        else
            cur = 1;
        if (i == a.size() - 1 || a[i] != a[i + 1])
            if (cur % 2 == 1)
                c.pb(a[i]);//, cout << a[i] << endl;
        //cout << a[i] << ' ' << cur << endl;
    }
    sort(c.begin(), c.end(), cmp);
    //cout << c[0] << ' ' << c[1] << ' ' << c[2] << ' ' << c[3] << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s.size(); j++)
            kol[s[j]]++;
        for (int j = 0; j < c[i].size(); j++)
            if (kol[c[i][j]] == 0) {
                s += c[i][j];
                //cout << s << ' ' << i << endl;
            } else
                kol[c[i][j]] --;
        }
    //cout << 'e'
    //cout << s << endl;
    //reverse(s.begin(), s.end());
}

signed main()
{
    cin >> n;
    if (n <= 3) {
        string s = "";
        for (int i = 1; i <= n; i++) {
            cout << "? " << i << ' ' << i << endl;
            char c;
            cin >> c;
            s += c;
        }
        cout << "! " << s << endl;
        return 0;
    }
    go();
    cout <<"! "<< s << endl;
    return 0;
}