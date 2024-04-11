# include <iostream>
# include <cstdio>
# include <cstring>

using namespace std;

long long solve(long long l,long long r) {
    int sz = 0;
    long long ans = 0;
    while(l <= r) {
        int tmp = __builtin_popcountll(l);
        if(tmp > sz) {
            sz = tmp;
            ans = l;
        }
        l = l | (l + 1);
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    while(n--) {
        long long l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
}