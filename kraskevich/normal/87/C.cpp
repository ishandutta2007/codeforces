#include <iostream>
#include <vector>
using namespace std;

vector<int> g(100001, -1);
vector<int> stp(100001, 1000000);

int move(int n)
{
    if(g[n] != -1)
        return g[n];
        
    if(n <= 2)
    {
        g[n] = 0;
        return 0;
    }
        
    vector<bool> u(n + 1, false);
    for(long long i = 2; i * (i + 1) / 2 <= n; i++)
    {
         long long cur =  i * (i + 1) / 2, go = -1;
         if(cur <= n && (n - cur) % i == 0)
            go = (n - cur) / i + 1;
        
         if(go > 0)
         {
             int res = 0;
             for(int j = go; j < go + i; ++j)
                    res ^= move(j);
             u[res] = true;
             if(!res)
                stp[n] = min(stp[n], (int)i);
        }
    }
    
    for(int i = 0; i < n; ++i)
        if(!u[i])
        {
            g[n] = i;
            break;
        }
        
    return g[n];
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    move(n);
    
    if(!g[n])
        cout << -1;
    else
        cout << stp[n];
    
    cin >> n;
    
    return 0;
};