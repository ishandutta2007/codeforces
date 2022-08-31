#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 200;

int main()
{
    int n;
    cin >> n;
    string home;
    cin >> home;
    string s, st, fin;
    multiset<string> sett;
    string sm[max_n];
    for (int i = 0; i < n; ++i)
    {
        cin >> sm[i];
    }
    for (int i = 0; i < n; ++i)
    {

        st = sm[i].substr(0, 3);
        fin = sm[i].substr(5, 3);
        //cout << st << ' ' << fin << endl;
        if (fin == home)
        {
            sett.insert(st);
        }
    }
    for (int i = 0; i < n; ++i)
    {

        st = sm[i].substr(0, 3);
        fin = sm[i].substr(5, 3);
        if (st != home) continue;
        if (sett.count(fin))
        {
            int c = sett.count(fin);
            sett.erase(fin);
            for (int j = 0; j < c - 1; ++j)
            {
                sett.insert(fin);
            }
            continue;
        }
        cout << "contest";
        return 0;
    }
    cout << "home";
    return 0;
}