#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int N = 4e5 + 100;

signed main()
{
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    vector <pair <int, int> > p;
    priority_queue <int, vector <int>, less<int> > q1;
    priority_queue <int, vector <int>, greater<int> > q2;
    int ans = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x>> y;
        p.push_back({x + y, x - y});
    }
    sort(p.begin(), p.end());
    q1.push(0);
    q2.push(0);
    for(auto p1 : p)
    {
        int y = p1.X;
        int x = p1.Y;
        ans += max(0LL, max(q1.top() - (x + y), (x - y) - q2.top()));
        if(!sz(q1) || q2.top() + y > x)
        {
            q1.push(x + y);
            q1.push(x + y);
            q2.push(q1.top() -2 * y);
            q1.pop();
        }
        else
        {
            q2.push(x - y);
            q2.push(x - y);
            q1.push(q2.top() + y * 2);
            q2.pop();
        }
    }
    ans /= 2;
    cout << ans;
    return 0;
}