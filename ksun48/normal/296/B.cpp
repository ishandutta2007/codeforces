#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define MOD 1000000007
int main() {
    int n;
    cin >> n;
    char stuff[n+1];
    char calvin[n+1];
    cin >> stuff >> calvin;
    LL less = 1;
    LL more = 1;
    LL total = 1;
    LL equal = 1;
    for(int i = 0; i < n; i++){
        if(stuff[i] == '?' && calvin[i] == '?'){
            less = (less * 55) % MOD;
            more = (more * 55) % MOD;
            total = (total * 100) % MOD;
            equal = (equal * 10) % MOD;
        } else if(stuff[i] == '?'){
            int k = (calvin[i] - '0');
            more = (more*max(10-k,0)) % MOD;
            less = (less*max(k+1,0)) % MOD;
            total = (total * 10) % MOD;
        } else if(calvin[i] == '?'){
            int k = stuff[i] - '0';
            less = (less*max(10-k,0)) % MOD;
            more = (more*max(k+1,0)) % MOD;
            total = (total * 10) % MOD;
        } else {
            if(calvin[i] > stuff[i]){
                more = 0;
            } else if(calvin[i] < stuff[i]){
                less = 0;
            }
            if(calvin[i] != stuff[i]){
                equal = 0;
            }
        }
        
    }
    //cout << total << " " << more << " " << less << " " << equal << endl;
    cout << (total + 2*MOD - more - less + equal) % MOD << endl;
    return 0;
}