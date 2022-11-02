#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 100128;
string s;
int a[MAXN];
int b[MAXN];
int dp[MAXN];
int main () {
    int n;
    cin >> s >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
    }
    dp[0] = 0;
    for(int i = 1; i < s.size(); i++)
        if(s[i] == s[i - 1]){
            dp[i] = dp[i - 1] + 1;
        }
        else{
            dp[i] = dp[i - 1];
        }
    for(int i = 0; i < n; i++)
        cout << dp[b[i]] - dp[a[i]] << " " << '\n';
}