#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <utility>

using namespace std;

map<string,string> M;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        string a, b; cin >> a >> b;
        if ((int)b.length() < (int)a.length())
            swap(a, b);
        M[a] = a;
        M[b] = a;
    }

    for (int i = 0; i < n; ++i)
    {
        string s; cin >> s;
        cout << M[s] << " \n"[i == n - 1];
    }
}