#include <algorithm>
#include <iostream>
#define N 200001

using namespace std;

vector<int> s[N];
int eff[N];
int64_t eans[N], oans[N];
int64_t tans;

void getans(int n)
{
    int64_t o, e, cs = 0;
    vector<int64_t> v;
    for (auto i: s[n])
    {
        getans(i);
        v.push_back(oans[i] - eans[i]);
        cs += eans[i];
    }
    sort(v.begin(), v.end());
    e = cs;
    o = cs + eff[n];
    for (int i = int(v.size()) - 1; i > -1; --i)
    {
        cs += v[i];
        if ((int(v.size()) - i) & 1)
            o = max(cs, o);
        else
            e = max(cs, e), o = max(cs + eff[n], o);
    }
    eans[n] = e;
    oans[n] = o;
    tans = max(tans, max(o, e));
}

int main()
{
    cin.tie(0), ios_base::sync_with_stdio(0);
    int n = 200000, a = 0;
    eff[0] = 100000;
    cin >> n;
    cin >> a >> eff[0];
    for (int i = 1; i < n; ++i)
    {
        a = 1;
        eff[i] = 100000;
        cin >> a >> eff[i];
        s[--a].push_back(i);
    }
    getans(0);
    cout << max(tans, max(oans[0], eans[0]));
    return 0;
}