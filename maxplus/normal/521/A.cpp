#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int a[256];
uint32_t ans = 1, mod = 1000000007, am;
vector<pair<int, char>> p;

int mpow(int64_t a, int deg)
{
    int64_t ans = 1, cd = 0, d = a;
    while ((1 << cd) <= deg)
    {
        if (deg & (1 << cd))
            ans = (ans * d) % mod;
        d = (d * d) % mod;
        cd++;
    }
    return ans;
}

//int div(int a, int b)
//{
//    return (a * pow(b, mod - 2)) % mod;
//}
//
//int fact

int main()
{
    int n, k;
    char c;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> c;
        ++a[c];
    }
    p.push_back({a['A'], 'A'});
    p.push_back({a['C'], 'C'});
    p.push_back({a['G'], 'G'});
    p.push_back({a['T'], 'T'});
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    while (p[am].first == p[0].first)  am++;
    cout << mpow(am, n);
//    cin >> n >> k;
//    cout << mpow(n, k);
    return 0;
}