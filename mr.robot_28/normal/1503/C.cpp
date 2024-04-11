#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <pair <int, int> > x(n);
    int sum = 0;
    set <pair <int, int> > st;
    int maxright = 1e9;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i].X >> x[i].Y;
        sum += x[i].Y;
        st.insert({x[i].X, x[i].Y});
        maxright = min(maxright, x[i].X);
    }
    int max1 = x[0].X;
    while(sz(st) > 0)
    {
        pair <int, int> t = *st.begin();
        st.erase(*st.begin());
        if(t.X <= maxright)
        {
            max1= max(max1,t.X);
            maxright = max(maxright, t.X + t.Y);
        }
        else
        {
            sum += t.X - maxright;
            maxright = t.X + t.Y;
        }
    }
    cout << sum;
    return 0;
}