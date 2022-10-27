#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
#define ll long long
using namespace std;
const int N =  42;
const int M =  2e5;
const int mod = 998244353;
int n, k;
int q[N];
ll active[N], inactive[N];
ll masks[N];
ll pref[N][N];
bool rec(ll mask, int i)
{
    if(i == k - 1)
    {
        int ones = __builtin_popcountll(mask);
        int zeroes = n - ones;
        ll sorted_mask = ((1LL << ones) - 1) << zeroes;
        ll diff = mask ^ sorted_mask;
        return (diff & masks[i]) == diff;
    }
    int min_ones = __builtin_popcountll(mask & masks[i]);
    mask |= masks[i];
    for(int ones = min_ones; ones <= min_ones + inactive[i]; ones++)
    {
//        cout << mask << " " << i << " " << ones << " " << (mask & pref[i][ones]) << "\n";
        if(!rec(mask & pref[i][ones], i + 1))
        {
            return 0;
        }
    }
    return 1;

}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    if(n == 1)
    {
        cout << "ACCEPTED";
        return 0;
    }
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        cin >> q[i];
        pref[i][q[i]] = (1LL << n) - 1;
        for(int j = 0; j < q[i]; j++)
        {
            int x;
            cin >> x;
            x--;
            masks[i] |= (1LL << x);
            pref[i][q[i] - (j + 1)] = (1LL << n) - 1 - masks[i];
      //      cout << pref[i][q[i] - (i + 1)] << " ";
        }
        //cout << "\n";
        inactive[i] = __builtin_popcountll(masks[i] & (~active[i]));
        active[i + 1] = active[i] | masks[i];
    }
    if(q[k - 1] == n)
    {
        cout << "ACCEPTED";
        return 0;
    }
    if(active[k - 1] != (1LL << n) - 1)
    {
        cout << "REJECTED";
        return 0;
    }
    if(!rec(0, 0))
    {
        cout << "REJECTED";
    }
    else
    {
        cout << "ACCEPTED";
    }
    return 0;
}