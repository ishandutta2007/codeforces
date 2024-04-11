#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)

using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T --)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        rep0(i, n) cin >> a[i], b[i] = a[i];
        sort(a.begin(), a.end());
        int flag = 1;
        rep0(i, n) if(a[i] != b[i]) flag = 0;
        if(flag == 0) puts("YES");
        else puts("NO");
    }
}