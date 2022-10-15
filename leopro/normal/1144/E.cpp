#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> sum(n + 1, 0);
    char c;
    for (int i = 1; i <= n; ++i){
        cin >> c;
        sum[i] += c;
    }
    for (int i = 1; i <= n; ++i){
        cin >> c;
        sum[i] += c;
    }
    for (int i = n; i > 0; --i){
        if (sum[i] >= int('a') + int('z') + 1){
            sum[i] -= (int('z') - int('a') + 1);
            sum[i - 1] += 1;
        }
    }
    if (sum[0] % 2 == 1) sum[1] += int('z') - int('a') + 1;
    for (int i = 1; i <= n; ++i){
        cout << char(sum[i] / 2);
        cout.flush();
        if (sum[i] % 2 == 1) sum[i + 1] += int('z') - int('a') + 1;
    }
    return 0;
}