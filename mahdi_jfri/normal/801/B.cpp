#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
string x , y;
int main()
{
    cin >> x >> y;
    string res;
    for(int i = 0; i < x.size(); i++)
    {
        if(x[i] == y[i])
            res += x[i];
        else if(x[i] < y[i])
        {
            cout << -1;
            return 0;
        }
        else
            res += y[i];
    }
    cout << res;
}