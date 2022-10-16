#include <iostream>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

set<int> p;
bool S[100001];
map<int, int> meantonum;
int a, b, n;

bool place(int i)
{
    if (p.find(a - i) != p.end() && p.find(b - i) != p.end())
        return 0;
    if (p.find(a - i) == p.end() && p.find(b - i) == p.end())
    {
        cout << "NO";
        exit(0);
    }
    if (p.find(a - i) == p.end() && p.find(b - i) != p.end())
    {
        S[meantonum[i]] = S[meantonum[b - i]] = 1;
        p.erase(i);
        p.erase(b - i);
        if (p.find(a - (b - i)) != p.end())
            place(a - (b - i));
        return 1;
    }
    if (p.find(a - i) != p.end() && p.find(b - i) == p.end())
    {
        S[meantonum[i]] = S[meantonum[a - i]] = 0;
        p.erase(i);
        p.erase(a - i);
        if (p.find(b - (a - i)) != p.end())
            place(b - (a - i));
        return 1;
    }
}

void strictplace(int i)
{
    if (p.find(a - i) == p.end() && p.find(b - i) != p.end())
    {
        S[meantonum[i]] = S[meantonum[b - i]] = 1;
        p.erase(i);
        p.erase(b - i);
        if (p.find(a - (b - i)) != p.end())
            place(a - (b - i));
        return;
    }
    if (p.find(a - i) != p.end() && p.find(b - i) == p.end())
    {
        S[meantonum[i]] = S[meantonum[a - i]] = 0;
        p.erase(i);
        p.erase(a - i);
        if (p.find(b - (a - i)) != p.end())
            place(b - (a - i));
        return;
    }
    if (p.find(a - i) == p.end() && p.find(b - i) == p.end())
    {
        cout << "NO";
        exit(0);
    }

    S[meantonum[i]] = S[meantonum[a - i]] = 0;
    p.erase(i);
    p.erase(a - i);
    if (p.find(b - (a - i)) != p.end())
        place(b - (a - i));
}

int main()
{
    int t;
    cin >> n >> a >> b;
    for (int i = 0; i < n; ++i)
    {
        cin >> t;
        p.insert(t);
        meantonum[t] = i;
        if (t > a && t > b)
        {
            cout << "NO";
            return 0;
        }
    }
    if (a == b)
        b = 0;
    while (p.size())
    {
        for (set<int>::iterator i = p.begin(); ; )
        {
            if (place(*i))
                break;
            if ((++i) == p.end())
            {
                strictplace(*(--i));
                while (p.size())
                    strictplace(*p.begin());
                break;
            }
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i)
        cout << S[i] << ' ';
    return 0;
}