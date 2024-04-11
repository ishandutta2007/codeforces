#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000005ll;

int n, m;
ll k;
string curs;

struct pos {
    string value;
    ll smaller;
    vector <ll> eq;
    pos(string gs, string gvalue) {
        value = gvalue;
        smaller = 0;
        eq.resize(gs.size(), 0);
    }
    ll Add(ll a, ll b)
    {
        return min(Inf, a + b);
    }
    void Add(int key, ll val, const string &add) {
        int p = 0;
        while (key < eq.size() && p < add.size() && curs[key] == add[p]) {
            key++; p++;
        }
        if (key >= eq.size()) return;
        if (p >= add.size()) { eq[key] = Add(eq[key], val); return; }
        if (add[p] < curs[key]) smaller = Add(smaller, val);
    }
    ll getAll() {
        ll res = smaller;
        for (int i = 0; i < eq.size(); i++)
            res = Add(res, eq[i]);
        return res;
    }
};

ll Add(ll a, ll b)
{
    return min(Inf, a + b);
}

ll Count()
{
    if (curs == "0") return 0;
    pos A(curs, "0"), B(curs, "1");
    if (curs[0] == '0') A.eq[1]++;
    else A.smaller++;
    if (curs[0] == '1' && curs.length() > 1) B.eq[1]++;
    for (int i = 2; i <= n; i++) {
        pos tmp = A;
        A = B;
        string nvalue = tmp.value + A.value;
        if (nvalue.length() > curs.length()) nvalue = nvalue.substr(0, curs.length());
        B.value = nvalue;
        for (int j = 1; j < curs.length(); j++)
            B.Add(j, tmp.eq[j], A.value);
        B.smaller = Add(B.smaller, tmp.smaller);
    }
    return B.getAll();
}

int main()
{
    scanf("%d %I64d %d", &n, &k, &m);
    for (int i = 0; i < m; i++) {
        curs += "0";
        if (Count() >= k) {
            cout << curs.substr(0, i) << endl;
            return 0;
        }
        curs[int(curs.length()) - 1] = '1';
        if (Count() >= k)
            curs[int(curs.length()) - 1] = '0';
    }
    cout << curs << endl;
    return 0;
}