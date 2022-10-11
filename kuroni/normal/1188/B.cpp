    #include <bits/stdc++.h>
    using namespace std;
     
    map<int, int> ma;
    int n, k, p;
    long long x, y, ans = 0;
     
    int main()
    {
        cin >> n >> p >> k;
        while (n--)
        {
            cin >> x;
            y = x * x % p;
            y = y * y % p;
            (y -= k * x) %= p;
            (y += p) %= p;
            (ans += ma[y]++);
        }
        cout << ans;
    }