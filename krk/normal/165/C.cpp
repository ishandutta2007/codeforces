#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;

int k;
string s;
vector <int> V;
ll res;

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> k >> s;
    V.push_back(-1);
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '1') V.push_back(i);
    V.push_back(s.length());
    if (k == 0)
        for (int i = 0; i + 1 < V.size(); i++)
            res += ll(V[i + 1] - V[i]) * ll(V[i + 1] - V[i] - 1) / 2LL;
    else for (int i = 0; i + k + 1 < V.size(); i++)
            res += ll(V[i + 1] - V[i]) * ll(V[i + k + 1] - V[i + k]);
    printf("%I64d\n", res);
    return 0;
}