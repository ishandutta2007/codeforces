#include <bits/stdc++.h>
//#define pb push_back;
#define ll long long
using namespace std;

struct vertex
{
    int flag;
    int next[2], val;
};
vertex bor[10000005];
int col = 1, n;
vector<bool> get(int a)
{
    vector<bool> res;
    res.clear();
    int i = 1;
    while (i*2<=a)
        i *= 2;
    while (i != 0)
    {
        res.push_back(a/i);
        a %= i;
        i /= 2;
    }
    vector<bool> r;
    r.clear();
    for (int i = 0; i < 27 - res.size(); i++)
        r.push_back(0);
    for (int i = 0; i < res.size(); i++)
        r.push_back(res[i]);
    return r;
}
vector<bool> p;

void add_to_bor(int val)
{
    p = get(val);
    int cur = 1;
    for (int i = 0; i < p.size(); i++)
    {
        bor[cur].val++;
        if (bor[cur].next[p[i]] == 0)
        {
            col++;
            bor[cur].next[p[i]] = col;
        }
        cur = bor[cur].next[p[i]];
    }
    bor[cur].val++;
    bor[cur].flag ++;
}

void erase_from_bor(int val)
{
    p = get(val);
    int cur = 1;
    for (int i = 0; i < p.size(); i++)
    {
        bor[cur].val--;
        cur = bor[cur].next[p[i]];
    }
    bor[cur].val--;
    bor[cur].flag--;
}

int get_ans(int pp, int l)
{
    p = get(pp ^ l);
    vector<bool> ppp = get(l);

    int cur = 1, ans = 0;
    for (int i = 0; i < p.size(); i++)
    {
        if (ppp[i] == 1)
            ans += bor[bor[cur].next[!p[i]]].val;
        cur = bor[cur].next[p[i]];
     //   cout << i << ' '<< ans << endl;
    }
    return ans;
}


int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        //cout << i << endl;
        int type;
        cin >> type;
        if (type == 1)
        {
            int x;
            cin >> x;
            add_to_bor(x);
        }
        if (type == 2)
        {
            int x;
            cin >> x;
            erase_from_bor(x);
        }
        if (type == 3)
        {
            int p, l;
            cin >> p >> l;
            cout << get_ans(p, l)<<endl;
        }
    }
    return 0;
}