#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
ll x,m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n==1)
    {
        cin >> m;
        if(m)
            cout <<"YES";
        else
            cout << "NO";
        return 0;
    }
    for(int i=0 ; i < n ;i++)
    {
        cin >> m;
        if(!m)
            x++;
        if(x>1)
        {
            cout << "NO";
            return 0;
        }
    }
    if(x == 0)
        cout << "NO";
    else
        cout << "YES";
}