#include<bits/stdc++.h>
using namespace std;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;
vector <int> index;
vector <int> ind, ind1;
int m;
string s1;
int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    return b;
}
vector <int>  pow1, pow2;
vector <pair <int, int> > hashes1;
void build()
{
    pow1.resize(m + 1);
    pow2.resize(m + 1);
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i <= m; i++)
    {
        pow1[i] = 1LL * pow1[i - 1] * 27 % mod1;
        pow2[i] = 1LL * pow2[i - 1] * 27 % mod2;
    }
    hashes1.resize(m);
    for(int i = 0; i < m; i++)
    {
        if(i == 0)
        {
            hashes1[i].first = hashes1[i].second = s1[i] - 'a' + 1;
        }
        else
        {
            hashes1[i].first = (1LL * hashes1[i - 1].first * 27 + s1[i] - 'a' + 1) % mod1;
            hashes1[i].second = (1LL * hashes1[i - 1].second * 27 + s1[i] - 'a' + 1) % mod2;
        }
    }
    char t = 'a' - 1;
    s1 += t;
    ind.resize(m);
    ind1.resize(m + 1);
    vector <int> col(m + 1), new_col(m + 1);
    int _sx = max(m + 1, 27);
    vector <int> cnt(_sx, 0);
    vector <int> it_st(_sx, 0);
    for(int i = 0; i < m + 1; i++)
    {
        cnt[s1[i] - t]++;
    }
    it_st[0] = 0;
    for(int i = 1; i < _sx; i++)
    {
        it_st[i] = it_st[i - 1] + cnt[i - 1];
    }
    vector <int> new_ind1(m + 1);
    for(int i = 0; i < m + 1; i++)
    {
        ind1[it_st[s1[i] - t]] = i;
        it_st[s1[i] - t]++;
    }
    int k = 0;
    for(int i = 0; i < m + 1; i++)
    {
        if(i != 0 && s1[ind1[i]] != s1[ind1[i - 1]])
        {
            k++;
        }
        col[ind1[i]] = k;
    }
    int u = log2(m + 1) + 1;
    for(int it = 0; it < u; it++)
    {
        for(int i = 0; i < m + 1; i++)
        {
            cnt[i] = 0;
            it_st[i] = 0;
        }
        for(int i = 0; i < m + 1; i++)
        {
            cnt[col[i]]++;
        }
        for(int i = 1; i < m + 1; i++)
        {
            it_st[i] = cnt[i - 1] + it_st[i - 1];
        }
        for(int i = 0; i < m + 1; i++)
        {
            int i1 = (ind1[i] - (1 << it) + (m + 1)) % (m + 1);
            new_ind1[it_st[col[i1]]] = i1;
            it_st[col[i1]]++;
        }
        int k = 0;
        for(int i = 0; i < m + 1; i++)
        {
            ind1[i] = new_ind1[i];
            int j1 = (ind1[i] + (1 << it)) % (m + 1);
            int j2;
            if(i != 0)
            {
                j2 = (ind1[i - 1] + (1 << it)) % (m + 1);
            }
            if(i != 0 && (col[ind1[i]] != col[ind1[i - 1]] || col[j1] != col[j2]))
            {
                k++;
            }
            new_col[ind1[i]] = k;
        }
        for(int i = 0; i < m + 1; i++)
        {
            col[i] = new_col[i];
        }
    }
    for(int i = 1; i < m + 1; i++)
    {
        ind[ind1[i]] = i - 1;
    }
}
pair <int, int> get_hash(int l, int r)
{
    if(l == 0)
    {
        return hashes1[r];
    }
    int fi1 = (hashes1[r].first - 1LL * hashes1[l - 1].first * pow1[r - l + 1] % mod1 + mod1) % mod1;
    int fi2 = (hashes1[r].second - 1LL * hashes1[l - 1].second * pow2[r - l + 1] % mod2 + mod2) % mod2;
    return {fi1, fi2};
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> s1;
    m =s1.size();
    build();
    int n;
    cin >> n;
    vector <vector <int> > vec(m);
    vector <pair <int, string> > query(n);
    vector <vector <int> > vec1(n);
    for(int i = 0; i < n; i++)
    {
        int k;
        string s;
        cin >> k >> s;
        query[i] = {k, s};
        vector <pair <int, int> > hashes(s.size());
        for(int j = 0; j< s.size(); j++)
        {
            if(j == 0)
            {
                hashes[j] = {s[j] - 'a' + 1, s[j] - 'a' + 1};
            }
            else
            {
                hashes[j].first = (1LL * hashes[j - 1].first * 27 + s[j] - 'a' + 1) % mod1;
                hashes[j].second = (1LL * hashes[j - 1].second * 27 + s[j] - 'a' + 1) % mod2;
            }
        }
        bool fl = 0;
        int l = 0, r = m + 1;
        while(r - l > 1)
        {
            int midd = (r + l) / 2;
            int a = ind1[midd];
            int l1 = -1, r1 = min(m - a, (int)s.size());
            while(r1 - l1 > 1)
            {
                int midd1 = (r1 + l1) / 2;
                if(hashes[midd1] == get_hash(a, a + midd1))
                {
                    l1 = midd1;
                }
                else
                {
                    r1 = midd1;
                }
            }
            if(l1 == s.size() - 1)
            {
                fl = 1;
                r = midd;
            }
            else if(l1 == m - a - 1)
            {
                l = midd;
            }
            else if(s[l1 + 1] <= s1[a + l1 + 1])
            {
                r = midd;
            }
            else
            {
                l = midd;
            }
        }
        if(!fl)
        {
            continue;
        }
        int l2 = 0, r2 = m + 1;
        while(r2 - l2 > 1)
        {
            int midd = (r2 + l2) / 2;
            int a = ind1[midd];
            int l1 = -1, r1 = min(m - a, (int)s.size());
            while(r1 - l1 > 1)
            {
                int midd1 = (r1 + l1) / 2;
                if(hashes[midd1] == get_hash(a, a + midd1))
                {
                    l1 = midd1;
                }
                else
                {
                    r1 = midd1;
                }
            }
            if(l1 == s.size() - 1)
            {
                l2 = midd;
            }
            else if(l1 == m - a - 1)
            {
                l2 = midd;
            }
            else if(s[l1 + 1] < s1[a + l1 + 1])
            {
                r2 = midd;
            }
            else
            {
                l2 = midd;
            }
        }
        vector <int> mass;
        for(int j = l + 1; j < r2; j++)
        {
            int a = ind1[j];
            vec[a].push_back(i);
        }
    }
    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < vec[i].size(); j++)
        {
            vec1[vec[i][j]].push_back(i);
        }
    }
    for(int i = 0; i < n; i++)
    {
        int k = query[i].first;
        if(vec1[i].size() < k)
        {
            cout << -1 << "\n";
            continue;
        }
        int ans = 1e9;
        for(int j = 0; j + k - 1 < vec1[i].size(); j++)
        {
            ans = min(ans, vec1[i][j + k - 1] - vec1[i][j] + (int)query[i].second.size());
        }
        cout<< ans << "\n";
    }
    return 0;
}