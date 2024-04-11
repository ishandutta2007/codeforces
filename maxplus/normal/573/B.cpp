#include <iostream>
#include <vector>
#include <set>
#define f first
#define s second
#define pb push_back

using namespace std;

set<pair<int, int>> s;
set<int> ex, ed;
vector<int> tmp;
int a[100001];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        (cin >> a[i]), s.insert({a[i], i}), ex.insert(i);
    ed.insert(0);
    ed.insert(n - 1);
    int t = 0;
    while (ex.size())
    {
        ++t;
        for (auto i: ed)
            ex.erase(i);
        for (auto i: ed)
        {
            if (ex.count(i - 1))
                tmp.pb(i - 1);
            if (ex.count(i + 1))
                tmp.pb(i + 1);
        }
        ed.clear();
        while (s.begin()->f == t)
        {
            if (ex.count(s.begin()->s - 1))
                ed.insert(s.begin()->s - 1);
            if (ex.count(s.begin()->s + 1))
                ed.insert(s.begin()->s + 1);
            ex.erase(s.begin()->s);
            s.erase(s.begin());
        }
        for (auto i: tmp)
            ed.insert(i);
        tmp.clear();
    }
    cout << t;
    return 0;
}