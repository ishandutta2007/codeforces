#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

typedef long long LL;
int mod(1e9 + 7);
const int N(1011);
int s[N][N];

int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    vector<bitset<N> > vec;
    vec.push_back(bitset<N>());
    for(int i(0); i < n; i++) vec.back().set(i);
    for(int i(1); i <= m; i++) {
        string st;
        cin >> st;
        bitset<N> tmp;
        for(int j(0); j < n; j++)
            if(st[j] == '1') 
                tmp.set(j);
        vector<bitset<N>> nw;
        for(bitset<N> t : vec) {
            bitset<N> t1 = t & tmp;
            bitset<N> t2 = t ^ t1;
            if(t1.count() != 0 && t2.count() != 0) {
                nw.push_back(t1);
                nw.push_back(t2);
            }else {
                nw.push_back(t);
            }
        }
        vec = nw;
    }
    for(int i(1); i <= n; i++) {
        for(int j(1); j <= i; j++) {
            s[i][j] = j == 1 || j == i ? 1 : (s[i - 1][j - 1] + (LL)s[i - 1][j] * j) % mod;
            s[i][0] = (s[i][0] + s[i][j]) % mod;
        }
        
    }
    int ans(1);
    for(auto i : vec) {
        ans = ans * (LL)s[i.count()][0] % mod;
    }
    printf("%d\n", ans);
}