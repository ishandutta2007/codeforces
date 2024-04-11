//10:15
//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii; 

const int maxN = 100 + 10;
const int maxW = maxN * maxN;
int a[maxN];

int cnt[maxN], gone[maxN];

bitset<maxW> dp[maxN]; 

int main() {
    int n;
    cin >> n; 

    int diff = 0;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x; 
        if( !cnt[x] ) diff++;
        cnt[x]++; 
    }

    if( diff <= 2 ) {
        cout << n << endl;
        return 0; 
    }

    dp[0][0] = 1;
    int ans = 1;
    for(int i = 0; i < n;) { 
        for(int j = 0; j < maxN; j++) 
            if( cnt[j] ) { 
                i++; 
                cnt[j]--;
                gone[j]++; 
                int v = gone[j] * j; 
                bool good = !dp[gone[j]][v];

                if( good ) {
                    ans = max(ans, gone[j]);
                }

                for(int k = i+1 ; k >= 1 ; k--)
                    dp[k] |= (dp[k-1]<<j);
            }
    }
    cout << ans << endl;

    return 0;
}