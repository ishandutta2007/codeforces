#include <iostream>
using namespace std;
int dp[1000000];
int next[1000000];
int main() {
    int n, d;
    cin >> n >> d;
    int c[n];
    for(int i = 0; i < n; i++) cin >> c[i];
    dp[0] = 1;
    for(int i = 1; i < 1000000; i++) dp[i] = 0;
    for(int i = 1; i < 1000000; i++) next[i] = -1;;
    for(int i = 0; i < n; i++){
        for(int j = 1000000-c[i]-1; j >= 0; j--){
            if(dp[j] == 1){
                dp[j+c[i]] = 1;
            }
        }
    }
    int last = 0;
    for(int i = 0; i < 1000000; i++){
        if(dp[i]) last = i;
        if(i >= d){
            if(last > i-d){
                next[i-d] = last;
            }
        }
    }
    int cur = 0;
    int turns = 0;
    while(next[cur] > cur){
        turns++;
        cur = next[cur];
    }
    cout << cur << " " << turns << endl;
    return 0;
}