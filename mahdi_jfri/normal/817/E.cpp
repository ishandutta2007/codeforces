#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define bit(a , b) (((a) >> b) & 1)
const ll maxn = 5e6 + 20;
ll l[maxn] , r[maxn] , lsum[maxn] , rsum[maxn] , tah = 1 , ln , pnow , res;
void ar(int p , int x , int z , ll i = 31)
{
    if(i < 0)
        return;
    if(!l[p])
    {
        l[p] = tah++;
        r[p] = tah++;
    }
    if(bit(x , i))
        rsum[p] += z , ar(r[p] , x , z , i - 1);
    else
        lsum[p] += z , ar(l[p] , x , z , i - 1);
}
void solve(int p , ll i = 31)
{
    if(i < 0)
        return;
    if(!l[p])
        return;
    if(bit(ln , i))
    {
        if(bit(pnow , i))
        {
            res += rsum[p];
            solve(l[p] , i - 1);
        }
        else
        {
            res += lsum[p];
            solve(r[p] , i - 1);
        }
    }
    else
    {
        if(bit(pnow , i))
            solve(r[p] , i - 1);
        else
            solve(l[p] , i - 1);
    }
}
int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        int a;
        cin >> a;
        if(a == 1)
        {
            int x;
            cin >> x;
            ar(0 , x , 1);
        }
        if(a == 2)
        {
            int x;
            cin >> x;
            ar(0 , x , -1);
        }
        if(a == 3)
        {
            res = 0;
            cin >> pnow >> ln;
            solve(0);
            cout << res << endl;
        }
    }
}