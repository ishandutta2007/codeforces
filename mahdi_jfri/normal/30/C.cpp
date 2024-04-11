#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define X first
#define Y second
#define double long double
#define t(a) (a)*(a)
const int maxn = 1e4 + 20;
const double inf = 1e18;
double dp[maxn][2];
pair<pair<ll , ll> , pair<ll , double> > a[maxn];
bool cmp(pair<pair<ll , ll> , pair<ll , double> > a , pair<pair<ll , ll> , pair<ll , double> > b)
{
    return a.Y.X > b.Y.X;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i].X.X >> a[i].X.Y >> a[i].Y.X >> a[i].Y.Y;
    sort(a , a + n , cmp);
    cout << fixed << setprecision(6);
    dp[0][0] = 0;
    dp[0][1] = a[0].Y.Y;
    for(int i = 1; i < n; i++)
    {
        dp[i][0] = max(dp[i - 1][0] , dp[i - 1][1]);
        dp[i][1] = a[i].Y.Y;
        for(int j = i - 1; j > -1; j--)
            if(t(a[j].X.X - a[i].X.X) + t(a[j].X.Y - a[i].X.Y) <= t(a[j].Y.X - a[i].Y.X))
                dp[i][1] = max(dp[i][1] , dp[j][1] + a[i].Y.Y);
    }
    cout << max(dp[n - 1][0] , dp[n - 1][1]);
}