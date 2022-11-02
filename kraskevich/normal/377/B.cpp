#include <bits/stdc++.h>

using namespace std;

#define PII pair<int, int>
#define F first
#define S second

struct student
{
    int skill;
    int cost;
    int id;
};

struct bug
{
    int skill;
    int id;
};

bool cmpS(student a, student b)
{
    return a.skill > b.skill;
}

bool cmpB(bug a, bug b)
{
    return a.skill > b.skill;
}

vector<student> a;
vector<bug> b;
int n, m;
long long s;
int ans[100 * 1000 + 10];

bool can(int d)
{
    set<PII> have;
    vector<int> sep;
    for (int i = 0; i < b.size(); i += d)
        sep.push_back(i);
    if (sep.size() > a.size())
        return false;
    int ptr = 0;
    long long sum = 0;
    for (int i = 0; i < sep.size(); i++) {
        int x = sep[i];
        int lo = b[x].skill;
        while (ptr < a.size() && a[ptr].skill >= lo)
        {
            have.insert(PII(a[ptr].cost, a[ptr].id));
            ptr++;
        }
        if (!have.size())
            return false;
        auto it = have.begin();
        ans[b[x].id] = it->S;
        sum += (long long)it->F;
        have.erase(have.begin());
    }
    sep.push_back(b.size());
    for (int i = 0; i + 1 < sep.size(); i++)
    {
        int x = sep[i];
        for (int j = x + 1; j < sep[i + 1]; j++)
            ans[b[j].id] = ans[b[x].id];
    }
    return sum <= s;
}

int main() {
    ios_base::sync_with_stdio(0);
    #ifdef TEST
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    cin >> n >> m >> s;
    b.resize(m);
    a.resize(n);
    for (int i = 0; i < m; i++)
    {
        b[i].id = i;
        cin >> b[i].skill;
    }
    sort(b.begin(), b.end(), cmpB);
    for (int i = 0; i < n; i++)
        a[i].id = i + 1;
    for (int i = 0; i < n; i++)
        cin >> a[i].skill;
    for (int i = 0; i < n; i++)
        cin >> a[i].cost;
    sort(a.begin(), a.end(), cmpS);
    int L = 1;
    int R = m + 1;
    while (L < R)
    {
        int M = (L + R) / 2;
        if (can(M))
            R = M;
        else
            L = M + 1;
    }
    if (L == m + 1)
    {
        cout << "NO";
        return 0;
    }
    can(L);
    cout << "YES" << "\n";
    for (int i = 0; i < m; i++)
        cout << ans[i] << " ";

    return 0;
}