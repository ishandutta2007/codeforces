#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <cstring>

#define wait system("pause")
#define MP make_pair

using namespace std;

const int MAXN = (int)2e6 + 10;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

pair< int64,pair<int64,int64> > dp[20][20];
bool from[20][20];
int64 pow10[20];

int main()
{
    int n; cin >> n;
    string s;
    cin >> s;
        
    pow10[0] = 1;
    for (int i = 1; i < 20; ++i)
        pow10[i] = 10 * pow10[i - 1];
            
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if (!i && !j) continue;
            
            if (!i){
               int64 val = dp[i][j - 1].second.second;
               val += (s[i + j - 1] - '0') * pow10[n - j];
               dp[i][j] = MP(val, MP(0, val));
               from[i][j] = true;
            }
            else if (!j){
               int64 val = dp[i - 1][j].second.first;
               val += (s[i + j - 1] - '0') * pow10[n - i];
               dp[i][j] = MP(val, MP(val, 0));
               from[i][j] = false;
            }
            else{
                 pair<int64,int64> cur = dp[i][j - 1].second;
                 cur.second += (s[i + j - 1] - '0') * pow10[n - j];
                 dp[i][j] = MP(cur.first + cur.second, cur);
                 from[i][j] = true;
                 
                 cur = dp[i - 1][j].second;
                 cur.first += (s[i + j - 1] - '0') * pow10[n - i];
                 if (cur.first + cur.second > dp[i][j].first)
                 {
                    from[i][j] = false;
                    dp[i][j] = MP(cur.first + cur.second, cur);
                 }
            }
            
            //cout << i << " " << j << " " << dp[i][j].second.first << " " << dp[i][j].second.second << endl;
        }
    }
    
    string ans = "";
    int i = n, j = n;
    while (i | j)
    {
          if (from[i][j]){
             ans = "M" + ans;
             j--;
          }
          else{
             ans = "H" + ans;
             i--;
          }
    }
    
    cout << ans << endl;
    
    //wait;
}