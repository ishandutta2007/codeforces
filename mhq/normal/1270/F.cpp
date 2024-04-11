#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast, unroll-loops", "omit-frame-pointer","inline")
#pragma GCC option("arch=native","tune=native","no-zero-upper")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native,avx2")
#include <iostream>
#include <vector>
#include <string>
using namespace std;


string s;
int n;
int p[200005];
vector<int> v[200005];
int used[200005];
long long ans;

int main(int argc, const char * argv[]) {
    #ifdef __APPLE__
        freopen("/Users/danya.smelskiy/Documents/Danya/Resources/input.txt","r",stdin);
        //freopen("/Users/danya.smelskiy/Documents/Danya/Danya/output.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> s;
    n = s.size();
    s = "#" + s;
    for (int i = 1; i <= n; ++i) {
        p[i] = p[i - 1] + (s[i] - '0');
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; j += i) {
            v[j].push_back(i);
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < v[i].size(); ++j)
            used[v[i][j]] = 1;
        for (int j = i; j <= n; ++j)
            ans += used[p[j] - p[j - i]];
        for (int j = 0; j < v[i].size(); ++j)
            used[v[i][j]] = 0;
    }
    cout << ans << '\n';
}