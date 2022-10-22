#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

ll BIT1[Maxn], BIT2[Maxn], ans;
int a[Maxn];
vector <int> nums;

int Cod(int num)
{
    return lower_bound(nums.begin(), nums.end(), num) - nums.begin() + 1;
}

ll Take(ll BIT[], int from)
{
    ll num = 0;
    for (int i = from; i > 0; i -= i & -i)
       num += BIT[i];
    return num;
}

void Give(ll BIT[], int from, ll val)
{
     for (int i = from; i < Maxn; i += i & -i)
        BIT[i] += val;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        nums.push_back(a[i]);
    }
    sort(nums.begin(), nums.end());
    unique(nums.begin(), nums.end());
    for (int i = n-1; i >= 0; i--) {
        ll tmp = Take(BIT2, Cod(a[i])-1);
        ans += tmp;
        tmp = Take(BIT1, Cod(a[i])-1);
        Give(BIT2, Cod(a[i]), tmp);
        Give(BIT1, Cod(a[i]), 1);
    }
    cout << ans << endl;
    return 0;
}