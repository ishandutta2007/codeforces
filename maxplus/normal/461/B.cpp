#include <vector>
#define N 1000000
std::vector<int> c[N];
#include <iostream>
#define mod (long long)1000000007


using namespace std;

long long var0[N], var1[N];
int col[N];

long long qp(long long a, long long b)
{
    long long d = a, ans = 1;
    for (long long deg = 0; ((long long)1 << deg) <= b; ++deg)
    {
        if (b & (1 << deg))
            ans = (ans * d) % mod;
        d = (d * d) % mod;
    }
    return ans;
}

long long dlv(long long a, long long b)
{
    long long pow = qp(b, mod - 2);
    return (a * pow) % mod;
}

void count(int x)
{
    var0[x] = 1;
    var1[x] = 0;
    for (int i = 0; i < c[x].size(); ++i)
    {
        count(c[x][i]);
        var0[x] *= var0[c[x][i]] + var1[c[x][i]] * (!col[c[x][i]]);
        var0[x] %= mod;
    }
    for (int i = 0; i < c[x].size(); ++i)
    {
        var1[x] += dlv(var0[x], var0[c[x][i]] + var1[c[x][i]] * (!col[c[x][i]])) * (var0[c[x][i]] * (col[c[x][i]]) + var1[c[x][i]] * (!col[c[x][i]]));
        var1[x] %= mod;
    }
}

int main()
{
    int n, t;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        cin >> t;
        c[t].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        cin >> col[i];
    count(0);
    cout << ((col[0])? var0[0]:var1[0]);
    return 0;
}