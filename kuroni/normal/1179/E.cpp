#include <bits/stdc++.h>
using namespace std;

const int N = 1005;
const long long INF = 1E18;
    
mt19937_64 mt(133769420);
vector<int> cl, ce, cr;
int n, a[N], st[N];
long long lim, al[N], ar[N];

int random(int n)
{
    uniform_int_distribution<int> dis(0, n - 1);
    return dis(mt);
}

long long ask(int u, long long v)
{
    cout << "? " << u << " " << v << endl;
    long long ret;
    cin >> ret;
    return ret;
}

long long BS(int u, long long tar, long long le, long long ri)
{
    while (le <= ri)
    {
        long long mi = (le + ri) / 2;
        long long cur = ask(u, mi);
        if (cur == tar)
            return mi;
        else if (cur < tar)
            le = mi + 1;
        else
            ri = mi - 1;
    }
}

void solve(long long le, long long ri, int add, vector<int> ve)
{
    int n = ve.size();
    if (n == 1)
    {
        al[ve.back()] = le; ar[ve.back()] = ri;
        return;
    }
    vector<int> ml, mr;
    long long pos, mid = lim * (add + n / 2);
    while (!ve.empty())
    {
        int cl = ml.size(), cr = mr.size();
        pos = BS(ve[random(ve.size())], mid, le, ri);
        for (int i = 0; i < ve.size(); i++)
        {
            long long cur = ask(ve[i], pos);
            if (cur > mid)
                st[i] = 0;
            else if (cur == mid)
                st[i] = 1;
            else
                st[i] = 2;
            cl += (st[i] == 0);
            cr += (st[i] == 2);
        }
        for (int i = ve.size() - 1; i >= 0; i--)
        {
            if (st[i] == 0 && cl <= n / 2)
            {
                ml.push_back(ve[i]);
                ve[i] = ve.back(); ve.pop_back();
            }
            else if (st[i] == 2 && cr <= n - n / 2)
            {
                mr.push_back(ve[i]);
                ve[i] = ve.back(); ve.pop_back();
            }
            else if (st[i] == 1 && cl <= n / 2 && cr <= n - n / 2)
            {
                if (cl < n / 2)
                {
                    ml.push_back(ve[i]);
                    cl++;
                }
                else
                {
                    mr.push_back(ve[i]);
                    cr++;
                }
                ve[i] = ve.back(); ve.pop_back();
            }
        }
    }
    solve(le, pos, add, ml);
    solve(pos, ri, add + n / 2, mr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> lim;
    lim /= n;
    vector<int> ve(n);
    for (int i = 0; i < n; i++)
        ve[i] = i + 1;
    solve(0, INF, 0, ve);
    cout << "!" << endl;
    for (int i = 1; i <= n; i++)
        cout << al[i] << " " << ar[i] << endl;
}