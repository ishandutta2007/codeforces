#include <bits/stdc++.h>

using namespace std;

const int N = 600 * 1000 + 10;

int pos[N];
int new_pos[N];
int c[N];
int new_c[N];
int head[N];
int cnt[N];
string s;
int n;

int low(int i, int step)
{
    i -= step;
    if (i < 0)
        i += n;
    return i;
}

int high(int i, int step)
{
    i += step;
    if (i >= n)
        i -= n;
    return i;
}

bool are_same(int p1, int p2, int step)
{
    if (c[p1] != c[p2])
        return false;
    p1 = high(p1, step);
    p2 = high(p2, step);
    if (c[p1] != c[p2])
        return false;
    return true;
}

void build_array()
{
    n = s.length();
    fill(head, head + N, 0);
    fill(cnt, cnt + N, 0);

    for (int i = 0; i < n; ++i)
        ++cnt[s[i]];
    for (int i = 1; i < N; ++i)
        head[i] = head[i - 1] + cnt[i - 1];
    for (int i = 0; i < n; ++i)
    {
        c[i] = s[i];
        pos[head[c[i]]++] = i;
    }
    head[0] = 0;
    for (int i = 1; i < N; ++i)
        head[i] = head[i - 1] + cnt[i - 1];
    for (int step = 1; step <= n; step *= 2)
    {
        for (int i = 0; i < n; ++i)
        {
            int cur = low(pos[i], step);
            new_pos[head[c[cur]]++] = cur;
        }
        head[0] = 0;
        new_c[new_pos[0]] = 0;
        bool all_diff = true;
        for (int i = 1; i < n; ++i)
            if (are_same(new_pos[i], new_pos[i - 1], step))
            {
                new_c[new_pos[i]] = new_c[new_pos[i - 1]];
                all_diff = false;
            }
            else
            {
                new_c[new_pos[i]] = new_c[new_pos[i - 1]] + 1;
                head[new_c[new_pos[i]]] = i;
            }
        copy(new_c, new_c + n, c);
        copy(new_pos, new_pos + n, pos);
        if (all_diff)
            break;
    }
}

vector<int> lcp;
vector<int> rev;

void calc_lcp() {
    rev.resize(n);
    for (int i = 0; i < n; i++)
        rev[pos[i]] = i;
    lcp.resize(n - 1);
    int curLen = 0;
    for (int i = 0; i < n; i++) {
        if (rev[i] == n - 1)
            continue;
        int j = pos[rev[i] + 1];
        while (i + curLen < n && j + curLen < n && s[i + curLen] == s[j + curLen])
            curLen++;
        lcp[rev[i]] = curLen;
        if (curLen > 0)
            curLen--;
    }     
}

int ans[N];
vector<int> atLowOpen[N];
vector<int> atHighOpen[N];
vector<int> atIdOpen[N];
vector<int> atIdClose[N];
vector<int> atLowClose[N];
vector<int> atHighClose[N];

int table[N][25];
int getLog[N];

void build_table() {
    int h = 0;
    for (int i = 1; i < N; i++) {
        while ((1 << h) <= i)
            h++;
        h--;
        getLog[i] = h;
    }
    for (int i = 0; i < n - 1; i++)
        table[i][0] = lcp[i];
    for (int h = 1; h < 25; h++)
        for (int i = 0; i + (1 << (h - 1)) < n - 1; i++) 
            table[i][h] = min(table[i][h - 1], table[i + (1 << (h - 1))][h - 1]);
}    

int getMin(int i, int j) {
    int k = getLog[j - i + 1];
    int x = table[i][k];
    int y = table[j - (1 << k) + 1][k];
    return min(x, y);
}


template<class Tsum, class Tval>
class Tree
{
    vector<Tval> f;

public:
    Tree(int n): f(n) {}

    void update(int pos, Tval add) {
        for (; pos < f.size(); pos = (pos | (pos + 1)))
            f[pos] += add;
    }

    Tsum getSum(int pos) {
        Tsum res = 0;
        for (; pos >= 0; pos = (pos & (pos + 1)) - 1)
            res += (Tsum)f[pos];
        return res;
    }

    Tsum getSum(int L, int R) {
        return getSum(R) - getSum(L - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int cnt;
    cin >> cnt;
    int q;
    cin >> q;
    vector<string> st(cnt);
    for (int i = 0; i < cnt; i++)
        cin >> st[i];
    vector<int> starts(cnt);
    vector<int> color;
    for (int i = 0; i < cnt; i++) {
        starts[i] = s.length();
        s += st[i];
        for (int j = 0; j < st[i].length(); j++)
            color.push_back(i);
        color.push_back(-1);        
        if (i != cnt - 1)
            s += '$';
        else
            s += (char)('$' - 1);
    }
    n = s.length();
    build_array();
    calc_lcp();
    build_table();
    /*for (int x : lcp)
        cerr << x << " ";
    cerr << endl;*/
    /*for (int l = 0; l < n - 1; l++) {
        int curMin = 1e9;
        for (int r = l; r < n - 1; r++) {
            curMin = min(curMin, lcp[r]);
            cerr << l << " " << r << " " << curMin << " " << getMin(l, r) << endl;
            assert(curMin == getMin(l, r));
        }
    }*/
    vector<int> low(cnt);
    vector<int> high(cnt);
    for (int i = 0; i < cnt; i++) {
        int pos = rev[starts[i]];
        int l = 0;
        int r = pos + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (getMin(pos - m, pos - 1) >= st[i].length())
                l = m;
            else
                r = m;
        }
        low[i] = pos - l;
        l = 0;
        r = n - pos;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (getMin(pos, pos + m - 1) >= st[i].length())
                l = m;
            else
                r = m;
        }
        high[i] = pos + l;                             
    }    
    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        k--;
        int L = low[k];
        int R = high[k];
        atIdOpen[L].push_back(i);
        atLowOpen[L].push_back(l);
        atHighOpen[L].push_back(r);
        atIdClose[R].push_back(i);
        atLowClose[R].push_back(l);
        atHighClose[R].push_back(r);  
        // cerr << l << " " << r << " " << k << " " << L << " " << R << endl;              
    }
    Tree<int, int> tree(cnt);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < atIdOpen[i].size(); j++)
            ans[atIdOpen[i][j]] -= tree.getSum(atLowOpen[i][j], atHighOpen[i][j]);
        int c = color[pos[i]];
        if (c >= 0)
            tree.update(c, 1);
        for (int j = 0; j < atIdClose[i].size(); j++)
            ans[atIdClose[i][j]] += tree.getSum(atLowClose[i][j], atHighClose[i][j]);             
    }
    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
    return 0;
}