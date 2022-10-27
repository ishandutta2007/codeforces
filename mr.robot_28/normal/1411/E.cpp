#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) (int)a.size()

using namespace std;
#define int long long
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector <int> st(30);
    st[0] = 1;
    for(int i = 1; i < 30; i++)
    {
        st[i] = st[i - 1] * 2;
    }
    vector <int> a(n);
    string s;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        a[i] = st[s[i] - 'a'];
    }
    t += a[n - 2] - a[n - 1];
    a.pop_back();
    a.pop_back();
    int c = 0;
    for(int i = 0; i < a.size(); i++)
    {
        c += a[i];
        a[i] *= 2;
    }
    if(t < -c || t > c)
    {
        cout << "No";
        return 0;
    }
    t += c;
    vector <int> b(n);
    vector <int> coun(63);
    for(int i = 0; i < n - 2; i++)
    {
        b[i] = s[i] - 'a' + 1;
        coun[b[i]]++;
    }
    vector <int> mass(62);
    int t1 = t;
    for(int i = 0; i < 62; i++)
    {
        mass[i] = t1 % 2;
        t1 = t1 / 2;
    }
    for(int i = 0; i < 62; i++)
    {
        if(mass[i] == 1)
        {
            coun[i]--;
            if(coun[i] < 0)
            {
                cout << "No";
                return 0;
            }
        }
        coun[i + 1] += coun[i] / 2;
    }
    cout << "Yes";
    return 0;
}