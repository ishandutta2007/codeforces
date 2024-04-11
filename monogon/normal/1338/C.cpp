
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll n;

ll findA(ll k) {
    ll sum = 0;
    int i = 0;
    for(i = 0; ; i += 2) {
        if(sum + (1LL << i) <= k) sum += (1LL << i);
        else break;
    }
    return (1LL << i) + (k - sum);
}

ll arr[4] = {0, 3, 1, 2};

ll findB(ll k) {
    ll sum = 0;
    int i = 0;
    for(i = 0; ; i += 2) {
        if(sum + (1LL << i) <= k) sum += (1LL << i);
        else break;
    }
    ll ans = (1LL << i) + (k - sum);
    for(int j = 0; j <= i; j += 2) {
        int x = (ans >> j) % 4;
        ans ^= (arr[x] << j);
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // set<int> se;
    // for(int a = 1; a <= 100; a++) {
    //     if(se.count(a) == 0) {
    //         for(int b = a + 1; b <= 100; b++) {
    //             if(se.count(b) == 0 && se.count(a ^ b) == 0) {
    //                 cout << b << endl;// << " " << bitset<8>(b) << " " << bitset<8>(a^b) << endl;
    //                 se.insert(a);
    //                 se.insert(b);
    //                 se.insert(a ^ b);
    //                 break;
    //             }
    //         }
    //     }
    // }

    cin >> t;
    while(t--) {
        cin >> n;
        n--;
        ll k = (n / 3);
        ll A = findA(k);
        ll B = findB(k);
        if(n % 3 == 0) {
            cout << A << '\n';
        }else if(n % 3 == 1) {
            cout << B << '\n';
        }else {
            cout << (A ^ B) << '\n';
        }
        cout << flush;
    }
}