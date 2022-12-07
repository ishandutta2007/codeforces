#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define int long long

typedef long long ll;

const int INF = 2e9 + 7;
const int mod = 1e9 + 7;
const int N = 1111111;
const long long LLINF = 4e18 * 1LL + 10;

int n, d, s;
int a[N];

int check(int x) 
{
    int ans = 0;
    for(int i = 1; i < n - x; i ++)
        ans += max(0LL, a[i] - a[i - 1] - 1);
    
    if(ans > x + d) return 0;
    return 1;
}

main() 
{
    cin >> n >> s; 
    s --;
    int ans = 0;
    for(int i = 0; i < n; i ++) 
    {
        cin >> a[i];
        if(a[i] == 0 && i != s) 
            ans ++, d ++;
        
    }
    if(a[s] != 0) ans ++;
    a[s] = 0;
    sort(a, a + n);

    int l = 0, r = n - 1;


    while(r - l > 1) 
    {
        int mid = (l + r) / 2;
        if(check(mid)) r = mid;
        else l = mid;
    }

    if(check(l)) cout << ans + l;
    else cout << ans + r;

    return 0;
}