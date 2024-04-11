#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rep0(i, x) for(int i = 0; i < x; i ++)

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
        vector<int> a(n), b(n);
        rep0(i, n) cin >> a[i];
        long long cnt = 0, flag = 1, sum = 0;
        rep(i, 1, n - 2)
        {
            cnt += (a[i] + 1LL) / 2LL;
            if(a[i] > 1) flag = 0;
        }
        if(flag == 1) {cout << "-1\n"; continue;}
        if(n == 3 && a[1] % 2 == 1) {cout << "-1\n"; continue;}
        cout << cnt << "\n";
    }
}