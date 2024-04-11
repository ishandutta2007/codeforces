#include <bits/stdc++.h>
using namespace std;
#define ll long long 
const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    ll n, m, a, b, d,x,y , res = 0;
    cin >> n;
    cin >> a >> b;
    char l[80];
    ll q[80];
    ll inf = 1e12;
    q[0] = q[1] = q[2] = q[3] = inf;
    q[4] = q[5] = q[6] = q[7] = -inf;
    char c;
    while(n--)
    {
        cin >> c >> x >> y;
        if(x == a)
        {
            if(y > b)
            {
                if(q[0] > y)
                {
                    q[0] = y;
                    l[0] = c;
                }
            }
            else
            {
                if(q[4] < y)
                {
                    q[4] = y;
                    l[4] = c;
                }
            }
        }
        if(y == b)
        {
            if(x > a)
            {
                if(q[2] > x)
                {
                    q[2] = x;
                    l[2] = c;
                }
            }
            else
            {
                if(q[6] < x)
                {
                    q[6] = x;
                    l[6] = c;
                }
            }
        }
        if(x > a && y > b)
        {
            if(a - x == b - y)
            {
                if(x < q[1])
                {
                    q[1] = x;
                    l[1] = c;
                }
            }
        }
        if(x > a && y < b)
        {
            if(x - a == b - y)
            {
                if(x < q[3])
                {
                    q[3] = x;
                    l[3] = c;
                }
            }
        }
        
        if(x < a && y > b)
        {
            if(a - x == y - b)
            {
                if(x > q[7])
                {
                    q[7] = x;
                    l[7] = c;
                }
            }
        }
        if(x < a && y < b)
        {
            if(a - x == b - y)
            {
                if(x > q[5])
                {
                    q[5] = x;
                    l[5] = c;
                }
            }
        }
    }
    res = 0;
    for(int i = 0; i < 8;i++)
    
    {
        if(l[i] == 'Q')
        
        {
            cout << "YES";
            return 0;
        }
    }
    if(l[0] == 'R' || l[1] == 'B' || l[2] == 'R' || l[3] == 'B' || l[4] == 'R' || l[5] == 'B' || l[6] == 'R' || l[7] == 'B') 
    {
        cout << "YES";
        return 0;
    }
    else
    {
        cout << "NO";
        return 0;
    }
    
}