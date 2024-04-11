#include <iostream>
#include <vector>
#define pb push_back

using namespace std;

vector<int> nei[100000];
bool v[100000];
int c[100000];

void walk(int a)
{
    v[a] = 1;
    for (auto i: nei[a]) if (c[i] == c[a] && !v[i])
        walk(i);
}

int main()
{
    int n, a, b, C = 0;
    cin >> n;
    for (int i = 1; i < n; ++i)
        cin >> a >> b, nei[--a].pb(--b), nei[b].pb(a);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    for (int i = 0; i < n; ++i) if (!v[i])
        walk(i), C++;
    for (int i = 0; i < n; ++i)
    {
        int nc = 1;
        for (auto j: nei[i]) if (c[j] != c[i])
            nc++;
        if (nc == C)
        {
            cout << "YES\n" << i + 1;
            return 0;
        }
    }
    cout << "NO";
    return 0;
}