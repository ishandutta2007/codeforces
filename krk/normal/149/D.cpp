#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 705;
const int mod = 1000000007;

string s;
stack <int> S;
int to[Maxn];
int ways[Maxn][Maxn][3];

int getWays(int l, int r, int st)
{
    if (l > r) return 1;
    if (ways[l][r][st] == -1) {
        int part1, part2;
        if (st == 0) {
            part1 = 2LL * ll(getWays(l + 1, to[l] - 1, 1)) % ll(mod) * 
                          ll(getWays(to[l] + 1, r, 0)) % ll(mod);
            part2 = 2LL * ll(getWays(l + 1, to[l] - 1, 2)) % ll(mod) *
                          ll(getWays(to[l] + 1, r, 1)) % ll(mod);
        } else if (st == 1) {
               part1 = ll(getWays(l + 1, to[l] - 1, 1)) *
                       ll(getWays(to[l] + 1, r, 0)) % ll(mod);
               part2 = 2LL * ll(getWays(l + 1, to[l] - 1, 2)) % ll(mod) *
                             ll(getWays(to[l] + 1, r, 1)) % ll(mod);
        } else {
               part1 = ll(getWays(to[r] + 1, r - 1, 2)) *
                       ll(getWays(l, to[r] - 1, 0)) % ll(mod);
               part2 = 2LL * ll(getWays(to[r] + 1, r - 1, 1)) % ll(mod) *
                             ll(getWays(l, to[r] - 1, 2)) % ll(mod);
        }
        ways[l][r][st] = (part1 + part2) % mod;
    }
    return ways[l][r][st];
}

int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
        if (s[i] == '(') S.push(i);
        else {
             to[S.top()] = i; to[i] = S.top(); S.pop();
        }
    fill((int*)ways, (int*)ways + Maxn * Maxn * 3, -1);
    cout << getWays(0, s.length() - 1, 0) << endl;
    return 0;
}