#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

ll a[9];
int n;
bool ok = false;

void check(ll b[3][3])
{
     if(ok)
           return;
    vector<ll> s;
    for(int i = 0; i < n; ++i)
    {
            ll sum = 0;
            for(int j = 0; j < n; ++j)
                    sum += b[i][j];
            s.push_back(sum);
    }
    for(int i = 0; i < n; ++i)
    {
            ll sum = 0;
            for(int j = 0; j < n; ++j)
                    sum += b[j][i];
            s.push_back(sum);
    }
    ll sum = 0;
    for(int i = 0; i < n; ++i)
            sum += b[i][i];
    s.push_back(sum);
    sum = 0;
    for(int i = 0; i < n; ++i)
            sum += b[i][n - i - 1];
    s.push_back(sum);
    sort(s.begin(), s.end());
    bool curok = true;
    for(int i = 1; i < s.size(); ++i)
            if(s[i] != s[i - 1])
            {
                    curok = false;
                    break;
            }
    if(curok)
    {
             ok = true;
             cout << s[0] << endl;
             for(int i = 0; i < n; ++i)
             {
                     for(int j = 0; j < n; ++j)
                             cout << b[i][j] << " ";
                     cout << endl;
             }
    }
}

ll b[3][3];

void solve()
{
     vector<int> pos(n * n);
     for(int i = 0; i < pos.size(); ++i)
             pos[i] = i;            
     for(;;)
     {
            for(int i = 0; i < pos.size(); ++i)
                    b[i / n][i % n] = a[pos[i]];
            if(ok)
                  return;
            check(b);
            next_permutation(pos.begin(), pos.end());
     }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    
    for(int i = 0; i < n * n; ++i)
            cin >> a[i];
    
    solve();
    
    return 0;
}