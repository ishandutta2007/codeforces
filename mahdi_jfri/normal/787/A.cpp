#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
map<ll , bool> t;
int main()
{
    int a , b , c , d;
    cin >> b >> a >> d >> c;
    for(int i = 0; i < maxn; i++)
    {
        t[a] = 1;
        a += b;
    }
    for(int i = 0; i < maxn; i++)
    {
        if(t[c])
        {
            cout << c << endl;
            return 0;
        }
        c += d;
    }
    cout << -1;
}