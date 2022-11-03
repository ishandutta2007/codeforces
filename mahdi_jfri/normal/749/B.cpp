#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int x[4] , y[4] , dx , dy;
set<pair<int , int> > ans;
int main()
{
    for(int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    dx = x[0] - x[1];
    dy = y[0] - y[1];
    ans.insert({x[2] + dx , y[2] + dy});
    ans.insert({x[2] - dx , y[2] - dy});
    dx = x[1] - x[2];
    dy = y[1] - y[2];
    ans.insert({x[0] + dx , y[0] + dy});
    ans.insert({x[0] - dx , y[0] - dy});
    dx = x[0] - x[2];
    dy = y[0] - y[2];
    ans.insert({x[1] + dx , y[1] + dy});
    ans.insert({x[1] - dx , y[1] - dy});
    cout << ans.size() << endl;
    while(!ans.empty())
    {
        cout << ans.begin() -> first << " " << ans.begin() -> second << endl;
        ans.erase(ans.begin());
    }
}