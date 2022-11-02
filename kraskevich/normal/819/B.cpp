#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
const int N = 3000 * 1000 + 10;

ll cnt[2 * N];

ll mabs(ll a) {
    return a > 0 ? a : -a;
}

ll calc(const vector<int>& p, int k) {
    ll res = 0;
    int n = p.size();
    for (int i = 0; i < n; i++)
        res += mabs(p[i] - (i + k) % n);
    return res;
}


int main() {
    //freopen("input", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i]--;
    }
    ll cnt_pos = 0;
    ll cnt_neg = 0;
    ll cur = 0;
    for (int i = 0; i < n; i++) {
        cur += mabs(p[i] - i);
        if (p[i] > i)
            cnt_pos++;
        else
            cnt_neg++;
        cnt[p[i] - i + N]++;
    }
    ll ans = cur;
    int ans_i = 0;
    int k = N;
    for (int i = 0; i < n - 1; i++) {
       k++; 
       cur += cnt_neg;
       cur -= cnt_pos;
       cnt_neg += cnt[k];
       cnt_pos -= cnt[k];
       cnt[p[n - i - 1] - (n - i - 1) + N]--;
       cnt[p[n - i - 1] + k]++;
       cur -= mabs(p[n - i - 1] - n);
       cur += p[n - i - 1];
       if (p[n - i - 1] > 0) {
           cnt_pos++;
           cnt_neg--;
       }
       if (cur < ans) {
           ans = cur;
           ans_i = i + 1;
       }
    }
    cout << ans << " " << ans_i << "\n";
}