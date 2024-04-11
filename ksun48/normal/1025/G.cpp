#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL MOD = 1000000007;
LL solve(vector<int> freq){
    LL ans = 0;
    for(int i = 0; i < freq.size(); i++){
        if(freq[i] > 0){
            LL num = 1;
            for(int j = 0; j < freq[i]-1; j++){
                num = (num + num) % MOD;
            }
            num--;
            ans = (ans + num) % MOD;
        }
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int> freq(n, 0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        a--;
        if(a < 0) a = i;
        freq[a]++;
    }
    LL ans = solve({n}) - solve(freq);
    if(ans < 0) ans += MOD;
    cout << ans << endl;
}