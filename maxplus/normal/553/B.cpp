#include <algorithm>
#include <iostream>
#define pb push_back

using namespace std;

int a[100], t, u[100], m, mp;
int64_t f[55];

vector<int> nv, v;
vector<vector<int>> vv;

string gen(int l, int64_t n, int d)
{
    if (l == 1)         return string("") + char(11 + d);
    if (l == 0)         return string("");
    if (n > f[l - 1])   return string("") + char(12 + d) + char(11 + d) + gen(l - 2, n - f[l - 1], d + 2);
    else                return string("") + char(11 + d) + gen(l - 1, n, d + 1);
}

//void genslow(int n, int k)
//{
//    int ans = 0;
////    cin >> n;
//    for (int i = 0; i < n; ++i)
//        a[i] = i;
//    do
//    {
//        t++;
//        vv.clear();
//        for (int i = 0; i < n; ++i)
//            if (u[a[i]] != t)
//            {
//                v.clear();
//                v.pb(a[i]);
//                u[v.back()] = t;
//                m = v.back(), mp = 0;
//                while (a[v.back()] != v[0])
//                    {v.pb(a[v.back()]), u[v.back()] = t; if (m < v.back()) m = v.back(), mp = v.size() - 1;}
//                nv.clear();
//                for (int i = mp; i < v.size(); ++i)
//                    nv.pb(v[i]);
//                for (int i = 0; i < mp; ++i)
//                    nv.pb(v[i]);
//                vv.pb(nv);
//            }
//        sort(vv.begin(), vv.end());
//        int num = 0;
//        for (auto i: vv)
//            for (auto j: i)
//                if (a[num++] != j)
//                    goto end_cyc;
//        if (++ans == k)
//        {
//            for (int i = 0; i < n; ++i)
//                cout << a[i] + 1 << ' ';
//            cout << '\n';
//            return;
//        }
//        end_cyc:;
//    }
//    while (next_permutation(a, a + n));
//    cout << ans;
//}

int main()
{
    int64_t n, k;
    cin >> n >> k;
    f[0] = f[1] = 1;
    for (int i = 2; i < n; ++i)
        f[i] = f[i - 1] + f[i - 2];
    auto t = gen(n, k, 0);
    for (auto i: t)
        cout << int(i - 10) << ' ';
    cout << '\n';
//    genslow(n, k);
    return 0;
}