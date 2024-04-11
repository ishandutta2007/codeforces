#include <algorithm>
#include <iostream>
#include <string.h>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define pii pair<int, int>
#define pll pair<long long, long long>
#define F first
#define S second
#define MP make_pair


multiset<int> a, b;
vector<int> all;
vector<int> aa;
vector<int> bb;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i)
    {
        int cura;
        cin >> cura;
        a.insert(cura);
        all.push_back(cura);
    }
    for (int i = 0; i < m; ++i)
    {
        int curb;
        cin >> curb;
        b.insert(curb);
        all.push_back(curb);
    }

    for (int i = 0; i < all.size(); ++i)
    {
        if (b.find(all[i]) != b.end() && a.find(all[i]) != a.end())
        {
            b.erase(b.find(all[i]));
            a.erase(a.find(all[i]));
        }
    }

    for (multiset<int>::iterator it = a.begin(); it != a.end(); ++it)
        aa.push_back(*it);
    for (multiset<int>::iterator it = b.begin(); it != b.end(); ++it)
        bb.push_back(*it);

    if (aa.size() > bb.size())
    {
        cout << "YES";
        return;
    }
    if (aa.size() == 0)
    {
        cout << "NO";
        return;
    }

    for (int i = 0; i < aa.size(); ++i)
    {
        int loa = lower_bound(aa.begin(), aa.end(), aa[i]) - aa.begin();
        int lob = lower_bound(bb.begin(), bb.end(), aa[i]) - bb.begin();
        int sza = (int)aa.size() - loa;
        int szb = (int)bb.size() - lob;
        if (sza > szb)
        {
            cout << "YES";
            return;
        }
    }

    cout << "NO";
}


int main()
{
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    solve();

    return 0;
}