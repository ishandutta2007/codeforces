#include <iostream>
#include <string>
using namespace std;

const int mod = 1000 * 1000 * 1000 + 7;

long long f[101][3000];

int main() {
    for(int i = 0; i <= 100; ++i)
            for(int j = 0; j < 3000; ++j)
                    f[i][j] = 0;
    f[0][0] = 1;
    for(int i = 0; i < 100; ++i)
            for(int j = 0; j < 25 * i + 1; ++j) 
                    for(int k = 0; k < 26; ++k)
                            f[i + 1][j + k] = (f[i + 1][j + k] + f[i][j]) % mod;
    int t;
    cin >> t;
    int ans[t];
    for(int test = 0; test < t; ++test) {
            string s;
            cin >> s;
            long long sum = 0;
            for(int i = 0; i < s.length(); ++i)   
                    sum += s[i] - 'a';
            ans[test] = (f[s.length()][sum] - 1 + mod) % mod;
    }
    for(int i = 0; i < t; ++i)
            cout << ans[i] << endl;
    cin >> t;
    return 0;
}