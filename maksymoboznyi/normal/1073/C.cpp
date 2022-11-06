#include <bits/stdc++.h>
#define pb push_back
#define ll long long

using namespace std;

const int N = 2e5 + 5;
const long long inf = 2e18;

int n, used[N], x, y, a, b;
string s;
char c, d;

bool check(int len) {
    int a1 = a, b1 = b;
    for (int i = 0; i < len; i++) {
        if (s[i] == 'R')
            a--;
        if (s[i] == 'L')
            a++;
        if (s[i] == 'U')
            b--;
        if (s[i] == 'D')
            b++;
    }
    int d = abs(a - x) + abs(b - y);
    //cout << d << ' ' << len << endl;
    if (d <= len && (d % 2 == len % 2)) {
        a = a1, b = b1;
        return 1;
    }
    for (int i = len; i < n; i++)
    {
        if (s[i] == 'R')
            a--;
        if (s[i] == 'L')
            a++;
        if (s[i] == 'U')
            b--;
        if (s[i] == 'D')
            b++;

        if (s[i-len] == 'R')
            a++;
        if (s[i-len] == 'L')
            a--;
        if (s[i-len] == 'U')
            b++;
        if (s[i-len] == 'D')
            b--;
        d = abs(a - x) + abs(b - y);
        if (d <= len && (d % 2 == len % 2)) {
            a = a1, b = b1;
            return 1;
        }
    }
    a = a1, b = b1;
    return 0;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> s;
    cin >> x >> y;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'R')
            a++;
        if (s[i] == 'L')
            a--;
        if (s[i] == 'U')
            b++;
        if (s[i] == 'D')
            b--;
    }
    c ='#', d = '#';
   // cout << a << ' ' << b << endl;
    if (a < x)
        c = 'L';
    if (a > x)
        c = 'R';
    if (b < y)
        d = 'D';
    if (b > y)
        d = 'U';
   // cout << c << ' ' << d << endl;
    int del = (abs(a - x) + abs(b - y));
    //cout << c << ' ' << d << ' ' << del << endl;
    if (del % 2 == 1 || del > 2*n) {
        cout << -1;
        return 0;
    }
    if (del == 0) {
        cout << 0;
        return 0;
    }
    int l = 0, r = n;
    while (l < r - 1) {
        int m = (l + r) / 2;
        if (check(m))
            r = m;
        else
            l = m;
        //cout << l << ' ' << r << endl;
    }
    //cout << check(5);
    //cout << check(52);
   // cout << '*' << r << endl;
    if (check(r))
        cout << r;
    else
        cout << -1;
    return 0;
}