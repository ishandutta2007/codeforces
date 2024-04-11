#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<long long> t(2000, 0);
int nn;

void add(int i, int add) {
     for(; i < nn; i = i | (i + 1))
           t[i] += add;
}

long long get(int r) {
    long long res = 0;
    for(r; r >= 0; r = (r & (r + 1)) - 1)
           res += t[r];
    return res;
}

long long get(int l, int r) {
     return get(r) - get(l - 1);
}

int main() {
    string s;
    cin >> s;
    int n = s.length();
    nn = n;
    bool p[n][n];
    long long sum[n];
    for(int i = 0; i < n; ++i)
            sum[i] = 0;
    for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                    p[i][j] = false;
    for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j) {
                    bool ok = true;
                    int l = i, r = j;
                    while(l < r) {
                            if(s[l] != s[r]) {
                                    ok = false;
                                    break;
                            }
                            ++l;
                            --r;
                    }
                    p[i][j] = ok;
            }
    long long res = 0;
    for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
                    if(p[i][j])
                               add(i, 1);
    for(int i = 0; i < n; ++i)
            for(int j = i; j < n; ++j)
                    if(p[i][j])
                               res += get(j + 1, n - 1);
    cout << res;
    cin >> n;
    return 0;
}