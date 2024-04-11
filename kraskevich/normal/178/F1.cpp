#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s[20];
int n;
int pref[20][20];
bool in[20];
int best = 0;
int k;

int prf(string a, string b)
{
    for(int i = 0; i < min(a.length(), b.length()); ++i)
            if(a[i] != b[i])
                    return i;
    return min(a.length(), b.length());
}

bool bit(int mask, int n)
{
     return (mask & (1 << n)) ? true : false;
}

void solve()
{
     int cnt = 0;
     for(int i = 0; i < n; ++i)
             if(in[i])
                      ++cnt;
     if(cnt != k)
            return;
     int cur = 0;
     for(int i = 0; i < n; ++i)
             for(int j = 0; j < n; ++j)
                     if(in[i] && in[j] && i != j)
                              cur += pref[i][j];
     best = max(best, cur / 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k; 
    
    for(int i = 0; i < n; ++i)
            cin >> s[i];
    
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    pref[i][j] = prf(s[i], s[j]);
    
    for(int mask = 0; mask < (1 << n); ++mask)
    {
            for(int i = 0; i < n; ++i)
                    in[i] = bit(mask, i);
            solve();
    }
    
    cout << best << endl;
    
    cin >> n;
    
    return 0;
}