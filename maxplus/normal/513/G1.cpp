#include <algorithm>
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> inv;
int ts, ta;

int count_inv(string &a)
{
    int ans = 0;
    for (int i = 0; i < a.size(); ++i)
        for (int j = 0; j < i; ++j)
            if (a[i] < a[j])
                ans++;
    return ans;
}

void mem(int n)
{
    string a;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        a[i] = i + 1;
    do
        inv[a] = count_inv(a);
    while (next_permutation(a.begin(), a.end()));
}

void gen(int r, string &a)
{
    if (r == 0)
    {
        ts += inv[a], ta++;
        return;
    }
    else
        for (int i = 0; i < a.size(); ++i)
            for (int j = 0; j <= i; ++j)
            {
                reverse(a.begin() + j, a.begin() + i + 1);
                gen(r - 1, a);
                reverse(a.begin() + j, a.begin() + i + 1);
            }
}

int main()
{
    int n, m;
    string a;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        a[i] -= '0';
    }
    mem(n);
    gen(m, a);
    cout.precision(100);
    cout << fixed << (double_t)ts / ta;
    return 0;
}