#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
ll paein , chap , bala , rast , t;
int main()
{
    chap = bala = 1e9;
    int n , m;
    cin >> n >> m;
    for(ll i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for(ll j = 0; j < m; j++)
        {
            if(s[j] == 'B')
            {
                t++;
                chap = min(chap , j);
                rast = max(rast , j);
                bala = min(bala , i);
                paein = max(paein , i);
            }
        }
    }
    if(!t)
    {
        cout << 1;
        return 0;
    }
    while(rast - chap > paein - bala)
    {
        if(paein + 1 < n)
            paein++;
        else if(bala - 1 > -1)
            bala--;
        else
        {
            cout << -1;
            return 0;
        }
    }
    while(rast - chap < paein - bala)
    {
        if(rast + 1 < m)
            rast++;
        else if(chap - 1 > -1)
            chap--;
        else
        {
            cout << -1;
            return 0;
        }
    }
    cout << (rast - chap + 1) * (rast - chap + 1) - t << endl;
}