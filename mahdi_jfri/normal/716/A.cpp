#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn =1e6;
ll res;
ll temp2;
int main()
{
    ll n,c;
    cin >> n >> c;
    ll temp;
    cin >> temp;
    n--;
    res++;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> temp2;
        if(temp2 - temp > c)
            res=1;
        else
            res++;
        temp = temp2;
    }
    cout << res;
}