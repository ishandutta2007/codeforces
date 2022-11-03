#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 4e5 + 20;
string n;
ll k = 1 , res = 1e9 , t;
bool a[maxn];
void bt(int i)
{
    if(i == n.size())
    {
        if(t == n.size())
            return;
        ll x = 0;
        for(int i = 0; i < n.size(); i++)
            if(!a[i])
                x = (x * 10) + n[i] - '0';
        if(x % k)
            return;
        bool f = 0;
        for(int i = 0; i < n.size(); i++)
        {
            if(!a[i] && !f)
            {
                if(n[i] == '0')
                    t++;
                else
                    f = 1;
            }
        }
        if(!f)
            t--;
        res = min(res , t);
        f = 0;
        for(int i = 0; i < n.size(); i++)
        {
            if(!a[i] && !f)
            {
                if(n[i] == '0')
                    t--;
                else
                    f = 1;
            }
        }
        if(!f)
            t++;
        return;
    }
    a[i] = 1;
    t++;
    bt(i + 1);
    t--;
    a[i] = 0;
    bt(i + 1);
}
int main()
{
    int k1 = 0;
    cin >> n >> k1;
    while(k1--)
        k *= 10;
    bt(0);
    cout << (res == 1e9? -1 : res);
}