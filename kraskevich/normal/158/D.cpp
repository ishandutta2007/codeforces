#include <iostream>
#include <vector>
using namespace std;

const int inf = 2 * 1000 * 1000 * 1000 + 1;

int main() {
    int n;
    cin >> n;
    int t[n];
    for(int i = 0; i < n; ++i)
            cin >> t[i];
    vector<int> num;
    for(int i = 3; i <= n; ++i)
            if(n % i == 0)
                 num.push_back(i);
    int res = -inf;
    for(int i = 0; i < num.size(); ++i) {
            int mod = n / num[i];
            vector<int> sum(mod, 0);
            for(int j = 0; j < n; ++j)
                    sum[j % mod] += t[j];
            for(int j = 0; j < mod; ++j)
                    res = max(res, sum[j]);
    }
    cout << res;
    cin >> n;
    return 0;
}