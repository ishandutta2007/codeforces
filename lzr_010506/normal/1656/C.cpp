#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)
#define ll long long
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T --)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        rep0(i, n) cin >> a[i];

        int c0 = 0, c1 = 0;
        rep0(i, n)
            if (a[i] == 1) c1 ++;
            else if (a[i] == 0) c0 ++;
        
        bool neq = 1;
        sort(a.begin(), a.end());
        rep(i, 1, n - 1)
            if (a[i - 1] + 1 == a[i]) neq = 0;
        
        if (!c1) puts("YES");
        else if (!c0 && neq) puts("YES");
        else puts("NO");
    }

    return 0 ;
}