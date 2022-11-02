#include <iostream>
#include <vector>
using namespace std;

#define pii pair<int, int>

int f[501][501];
pii p[501][501];
int cnt[501][501];
const int inf = 1000 * 1000;

int change(string s, int l, int r)
{
    int res = 0;
    while(l < r)
    {
            if(s[l] != s[r])
                    ++res;
            ++l;
            --r;
    }
    return res;
}

vector<string> ans;

void rec(int i, int j, string s)
{
     if(i == 0)
          return;
     pii prev = p[i][j];
     string cur = "";
     for(int t = prev.first + 1; t <= i; ++t)
             cur += s[t];
     ans.push_back(cur);
     rec(prev.first, prev.second, s);
}
             
string good(string s)
{
       string res = s;
       int l = 0, r = s.length() - 1;
       while(l <= r)
       {
               res[l] = res[r] = s[l];
               ++l;
               --r;
       }
       return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    string s;
    
    cin >> s;
    
    int k;
    
    cin >> k;
    
    s = '$' + s;
    int n = s.length();
    
    for(int i = 1; i < n; ++i)
            for(int j = i; j < n; ++j)
                    cnt[i][j] = change(s, i, j);
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < k; ++j)
                    f[i][j] = inf;
    f[0][0] = 0;
    
    for(int pos = 1; pos < n; ++pos)
            for(int kk = 0; kk <= k; ++kk)
                    if(kk == 0)
                    {
                          f[pos][kk] = cnt[1][pos];
                          p[pos][kk] = pii(0, 0);
                    }
                    else
                        for(int prev = 0; prev < pos; ++prev)
                                if(f[pos][kk] > f[prev][kk - 1] + cnt[prev + 1][pos])
                                {
                                              f[pos][kk] = f[prev][kk - 1] + cnt[prev + 1][pos];
                                              p[pos][kk] = pii(prev, kk - 1);
                                }
    
    int res = -1;
    for(int i = 0; i < k; ++i)
            if(res < 0 || f[n - 1][res] > f[n - 1][i])
                   res = i;
    
    cout << f[n - 1][res] << endl;
    
    rec(n - 1, res, s);
    
    for(int i = (int)ans.size() - 1; i > 0; --i)
            cout << good(ans[i]) << "+";
    cout << good(ans[0]) << endl; 
    
    cin >> n;
    
    return 0;
}