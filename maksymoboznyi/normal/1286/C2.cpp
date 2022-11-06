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
    int k = n - n / 2;
    cout << "? 1 " << k << endl;
    for (int i = 0; i < k * (k + 1) / 2; i++) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        a.pb(s);
    }

    cout << "? 2 " << k  << endl;
    for (int i = 0; i < k * (k - 1) / 2; i++) {
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
    for (int i = 0; i < k; i++) {
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

int cnt[N][N];
char ans[N];
int tmp[N];

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
    //cout << s << endl;
    for (int i = 'a'; i <= 'z'; i++)
        kol[i] = 0;
    for (int i = 0; i < n; i++)
        ans[i] = '#';
    cout << "? 1 " << n << endl;
    for (int i = 0; i < n * (n + 1) / 2; i++) {
        string t;
        cin >> t;
        for (int j = 0; j < t.size(); j++)
            cnt[t[j]][t.size()]++;
        if (t.size() == n) {
            for (int j = 0; j < t.size(); j++)
                kol[t[j]]++;
        }
    }
    for (int q = 0; q < n / 2; q++) {
        ans[q] = s[q];
        kol[s[q]]--;
        for (char c = 'a'; c <= 'z'; c++) {
            if (kol[c] == 0)
                continue;
            kol[c]--;
            ans[n - q - 1] = c;
            for (int j = 'a'; j <= 'z'; j++) {
                tmp[j] = (q + 2) * kol[j];
            }
            for (int i = 0; i <= q; i++)
                tmp[ans[i]] += i + 1;
            for (int i = n - 1; i >= n - q - 1; i--)
                tmp[ans[i]] += n - i;
            bool r = 1;
            for (int i = 'a'; i <= 'z'; i++)
                if (tmp[i] != cnt[i][n - q - 1]) {
                    r = 0;
                    //cout << char(i) << ' ' << tmp[i] << ' ' << cnt[i][n - q - 1] << endl;
                    break;
                }
            if (r)
                break;
            else
                kol[c]++;//, cout << q << ' ' << c << endl;
        }
    }
    if (n % 2 == 1)
        ans[n / 2] = s[n / 2];
     cout << "! ";
    for (int i = 0; i < n; i++)
        cout << ans[i];
    return 0;
}