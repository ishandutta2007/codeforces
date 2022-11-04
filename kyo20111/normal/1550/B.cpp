#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a, b;
string s;
int dp[111][111];

void solve(){
    cin >> n >> a >> b >> s;
    int sum = a*n;
    if(b >= 0) sum += b*n;
    else{
        int c[2] = {0, 0};
        for(int i=0;i<s.size();i++){
            int j=i;
            while(j+1<s.size() && s[j+1] == s[i]) j++;
            c[s[i]-'0']++;
            i=j;
        }
        sum += (min(c[0], c[1]) + 1) * b;
    }

    cout << sum;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}