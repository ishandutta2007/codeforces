#include <iostream>
#include <cstdlib>

using namespace std;

//void out()
//{
//    cout << 0;
//    exit(0);
//}

int main()
{
    int n, am = 0;
    string s, t;
    cin >> n;
    cin >> s;
    cin >> t;
//    if (s == t)
//    {
////        for (int st = 0; st < n; )
////        {
////            int p = st + 1;
////            while (s[p] == s[st])
////                p++;
////            am += p - st;
////            st = p;
////        }
//        cout << am + 26 * (n + 1);
//        return 0;
//    }
    for (int i = 0; i < n; ++i)
        if (s[i] != t[i])
            am++;
    if (am == 1)
    {
        cout << 2;
        return 0;
    }
    s += "0";
    t += "1";
    am = 0;
    //ff
    int p = 0;
    while (s[p] == t[p]) p++;
    string ns = s;
    ns.insert(ns.begin() + p, t[p]);
    while (ns[p] == t[p]) p++;
    string nt = t;
    nt.insert(nt.begin() + p, ns[p]);
    while (ns[p] == nt[p]) p++;
    string w;
    if (p > n)
        am++, w = ns;
    p = 0;
    while (s[p] == t[p]) p++;
    nt = t;
    nt.insert(nt.begin() + p, s[p]);
    while (s[p] == nt[p]) p++;
    ns = s;
    ns.insert(ns.begin() + p, nt[p]);
    while (ns[p] == nt[p]) p++;
    if (p > n)
        am++;
    if (am == 2 && w == ns)
        am--;
    cout << am;
    return 0;
}