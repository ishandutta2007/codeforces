#include <algorithm>
#include <iostream>
#include <vector>
//#include <ctime>
//#include <set>
#define N 200001
#define sqN 1200

using namespace std;

template<class it>
int mupper_bound(it b, it e, int key)
{
    int l = 0, r = e - b + 1, m;
    while (r - l > 1)
    {
        m = (r + l) >> 1;
        if (*(b + m) <= key)
            l = m;
        else
            r = m;
    }
    return *(b + l);
}

int ma[N], mb[N], n, a[N], b[N], c[N];
vector<int> lsta, lstb, strc[sqN];
void realize(int pos)
{
    sort(lsta.begin(), lsta.end());
    sort(lstb.begin(), lstb.end());
    for (int i = 0; i < lsta.size(); ++i)
        ma[lsta[i]] = i;
    for (int i = 0; i < lstb.size(); ++i)
        mb[lstb[i]] = i;
    for (int i = pos; i < n; ++i)
    {
        auto t = mupper_bound(&*lsta.begin(), &*prev(lsta.end()), a[i]);
        if (t > a[i])
            continue;
        a[i] -= ma[t] + 1;
    }
    for (int i = pos; i < n; ++i)
    {
        auto t = mupper_bound(&*lstb.begin(), &*prev(lstb.end()), b[i]);
        if (t > b[i])
            continue;
        b[i] -= mb[t] + 1;
    }
    lsta.clear();
    lstb.clear();
}

int main()
{
//    srand(time(0));
    int t1, t2, cb;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    n = 200000;
    cin >> n;
//    for (int i = 0; i < n; ++i)
//        a[i] = b[i] = i;
//    random_shuffle(a, a + n);
//    random_shuffle(b, b + n);
//    auto start = clock();
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    for (int i = 0; i < n; ++i)
    {
        if (i && !(i % sqN))
            realize(i);
        t1 = a[i], t2 = b[i];
        for (auto j: lsta)
            if (j <= t1)
                --a[i];
        for (auto j: lstb)
            if (j <= t2)
                --b[i];
        c[i] = a[i] + b[i];
        lsta.push_back(t1);
        lstb.push_back(t2);
    }
    for (int i = n - 1; i > 0; --i)
        c[i - 1] += c[i] / (n - i), c[i] %= (n - i);
    c[0] %= n;
    cb = -1;
    for (int i = 0; i < n; ++i)
        strc[cb += !(i % sqN)].push_back(i);
    for (int i = 0; i < n; ++i)
    {
        cb = 0;
        while (c[i] >= strc[cb].size())
            c[i] -= strc[cb++].size();
        cout << strc[cb][c[i]] << ' ';
        strc[cb].erase(strc[cb].begin() + c[i]);
    }
//    cout << (clock() - start) * 1000.0 / CLOCKS_PER_SEC;
    return 0;
}