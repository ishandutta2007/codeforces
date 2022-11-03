#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int p1 , p2 , day , w[maxn];
int main()
{
    int n , k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> w[i];
    for(int i = 0; i < n; i++)
    {
        if(!p1)
        {
            p1 += min(w[i] , k);
            w[i] -= min(w[i] , k);
        }
        if(!p2)
        {
            p2 += min(w[i] , k);
            w[i] -= min(w[i] , k);
        }
        if(p1 && p2)
        {
            day++;
            p1 = 0;
            p2 = 0;
        }
        if(w[i])
        {
            day += w[i] / (2 * k);
            w[i] %= (2 * k);
            i--;
        }
    }
    if(p1 || p2)
        day++;
    cout << day;
}