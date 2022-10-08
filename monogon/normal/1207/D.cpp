
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int M = 998244353;
const int MAX_N = 3e5 + 5;
int n, a, b;
vector<pair<int, int> > v;
multiset<int> A, B;
multiset<pair<int, int> > C;
ll fact[MAX_N];

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
        A.insert(a);
        B.insert(b);
    }
    sort(v.begin(), v.end());
    C = multiset<pair<int, int> >(v.begin(), v.end());

    fact[0] = 1;
    for(int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % M;
    }
    unsigned int sz1;
    ll cnt = fact[n];
    ll cnt1 = 1;
    while(sz1 = A.size()) {
        A.erase(*A.begin());
        cnt1 = (cnt1 * fact[sz1 - A.size()]) % M;
    }
    cnt -= cnt1;
    cnt1 = 1;
    while(sz1 = B.size()) {
        B.erase(*B.begin());
        cnt1 = (cnt1 * fact[sz1 - B.size()]) % M;
    }
    cnt -= cnt1;
    
    // check if v is bad in both ways
    bool doublebad = true;
    for(int i = 1; i < n; i++) {
        if(v[i].second < v[i - 1].second) {
            doublebad = false;
            break;
        }
    }
    if(doublebad) {
        cnt1 = 1;
        while(sz1 = C.size()) {
            C.erase(*C.begin());
            cnt1 = (cnt1 * fact[sz1 - C.size()]) % M;
        }
        cnt += cnt1;
    }
    cout << (cnt % M + M) % M << endl;
}