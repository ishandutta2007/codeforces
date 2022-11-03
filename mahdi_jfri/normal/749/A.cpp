#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
vector<int> ans;
int main()
{
    int n;
    cin >> n;
    while(n >= 2 && n != 3)
    {
        n -= 2;
        ans.pb(2);
    }
    if(n == 3)
        ans.pb(3);
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
}