#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
LL freq[50000];
int main() {
    int a;
    cin >> a;
    char k[5000];
    cin>> k;
    int n = strlen(k);
    int psums[n+1];
    psums[0] = 0;
    for(int i = 0; i < n; i++){
        psums[i+1] = psums[i]+(k[i]-'0');
    }
    for(int i = 0; i < 50000; i++) freq[i] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            freq[psums[j]-psums[i]]++;
        }
    }
    
    if(a == 0){
        LL total = n*(n+1)/2;
        cout << total*total-(total-freq[0])*(total-freq[0]) << endl;
    } else {
        LL ans = 0;
        for(int i = 1; i < 50000; i++){
            if(a % i == 0 && (a/i) < 50000){
                ans += freq[i]*freq[a/i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}