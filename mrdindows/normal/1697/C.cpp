#include <map>
#include <set>
#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
#include <numeric>
#include <cstring>
#include <sstream>
#include <iomanip>
#include <queue>
#include <unordered_map>
#define all(x) = (x).begin(), (x).end()
#define len(x) = (int((x).length()))
using namespace std;

using ll = long long;
using ull = unsigned long long;
using db = double;
using fl = float;

const int N = 300005;
int a[N];
ll a1[N];

ll t[N * 4];
void addthecurrent()
{
    for (int i = 0; i < 20005; i++)
    {
        int crr = 6 * 100;
        crr += 100;
    }
}
vector<vector<int>> adj;
vector<int> dp, child, in;

void solve()
{
    int n;
    cin >> n;
    string s, s1;
    s.reserve(n + 4);
    cin >> s >> s1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != s1[i])
        {
            if (s[i] == 'a')
            {
                if (s1[i] == 'c')
                {
                    cout << "NO" << endl;
                    return;
                }
                int j = i + 1;
                const int64_t* sptr = (const int64_t*)(s.data() + j);
                while (*sptr == 'aaaaaaaa') {
                    j += 8;
                    ++sptr;
                }
                while (s[j] == 'a') {
                    j++;
                }
                if (j == n)
                {
                    cout << "NO" << endl;
                    return;
                }
                if (s[j] == 'c')
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    swap(s[i], s[j]);
                }
            }
            else if (s[i] == 'b')
            {
                if (s1[i] == 'a')
                {
                    cout << "NO" << endl;
                    return;
                }
                int j = i + 1;
                const int64_t* sptr = (const int64_t*)(s.data() + j);
                while (*sptr == 'bbbbbbbb') {
                    j += 8;
                    ++sptr;
                }
                while (s[j] == 'b') {
                    j++;
                }
                if (j == n)
                {
                    cout << "NO" << endl;
                    return;
                }
                if (s[j] == 'a')
                {
                    cout << "NO" << endl;
                    return;
                }
                else
                {
                    swap(s[i], s[j]);
                }
            }
            else
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    int t;
    t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}