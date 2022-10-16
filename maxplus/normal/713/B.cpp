#include <iostream>
#include <vector>
#define pb push_back
#define then <<' '<<

using namespace std;

//int b1 = 2, l1 = 2, t1 = 2, r1 = 2, b2 = 3, l2 = 4, t2 = 3, r2 = 5;

int ask(int a1, int a2, int a3, int a4)
{
    cout << '?' then a1 then a2 then a3 then a4 << endl;
//    cout << ((a1 <= b1 && a2 <= l1 && a3 >= t1 && a4 >= r1) + (a1 <= b2 && a2 <= l2 && a3 >= t2 && a4 >= r2)) << endl;
    cin >> a1;
//    a1 = ((a1 <= b1 && a2 <= l1 && a3 >= t1 && a4 >= r1) + (a1 <= b2 && a2 <= l2 && a3 >= t2 && a4 >= r2));
    return a1;
}

int l, r, m, one = 1, n;

int bsl(int &a1, int &a2, int &a3, int &a4, int t)
{
    l = 0, r = n;
    while (r - l > 1)
    {
        m = (l + r) / 2;
        if (ask(a1, a2, a3, a4) >= t)
            r = m;
        else
            l = m;
    }
    return r;
}

int bsr(int &a1, int &a2, int &a3, int &a4, int t)
{
    l = 1, r = n + 1;
    while (r - l > 1)
    {
        m = (l + r) / 2;
        if (ask(a1, a2, a3, a4) >= t)
            l = m;
        else
            r = m;
    }
    return l;
}

int main()
{
    vector<int> R, T, L, B;
    cin >> n;
    R.pb(bsl(one, one, n, m, 2));
    R.pb(bsl(one, one, n, m, 1));
    T.pb(bsl(one, one, m, n, 2));
    T.pb(bsl(one, one, m, n, 1));
    L.pb(bsr(one, m, n, n, 2));
    L.pb(bsr(one, m, n, n, 1));
    B.pb(bsr(m, one, n, n, 2));
    B.pb(bsr(m, one, n, n, 1));
//    for (auto i: R)
//        cout << i << ' ';
//    cout << '\n';
//    for (auto i: T)
//        cout << i << ' ';
//    cout << '\n';
//    for (auto i: L)
//        cout << i << ' ';
//    cout << '\n';
//    for (auto i: B)
//        cout << i << ' ';
//    cout << '\n';
    for (int msk = 0; msk < 16; ++msk) if (B[!!(msk & 8)] <= T[!!(msk & 2)] && B[ !(msk & 8)] <= T[ !(msk & 2)] &&
                                          L[!!(msk & 4)] <= R[!!(msk & 1)] && L[ !(msk & 4)] <= R[ !(msk & 1)])
        if (ask(B[!!(msk & 8)], L[!!(msk & 4)], T[!!(msk & 2)], R[!!(msk & 1)]) &
            ask(B[ !(msk & 8)], L[ !(msk & 4)], T[ !(msk & 2)], R[ !(msk & 1)]))
            return cout << '!' then B[!!(msk & 8)] then L[!!(msk & 4)] then T[!!(msk & 2)] then R[!!(msk & 1)]
                        then B[ !(msk & 8)] then L[ !(msk & 4)] then T[ !(msk & 2)] then R[ !(msk & 1)] << endl, 0;
    return 0;
}