#include <iostream>
using namespace std;
typedef long long LL;
int main() {
    int n, k;
    cin >> n >> k;
    LL num[n];
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    LL sum[n-k];
    sum[0] = 0;
    for(int i = 0; i < k; i++){
        sum[0] += num[i];
    }
    for(int i = 1; i <= n-k; i++){
        sum[i] = sum[i-1]-num[i-1]+num[i-1+k];
    }
    LL ans = 0;
    int a;
    LL max1 = 0;
    int ra;
    int b;
    for(int i = k; i <= n-k; i++){
        if(sum[i-k] > max1){
            max1 = sum[i-k];
            a = i-k;
        }
        if(ans < max1 + sum[i]){
            ans = max1 + sum[i];
            ra = a;
            b = i;
        }
    }
    cout << ra+1 << " " << b+1 << endl;
    return 0;
}