#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

set<int> s;
int pr[max_n];
int nxt[max_n];
int m[max_n];


int main()
{
    //freopen("input.txt", "r", stdin);
    int T;
    cin >> T;
    while(T--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
            pr[i] = (i - 1 + n) % n;
            nxt[i] = (i + 1) % n;
        }
        s.clear();
        for (int i = 0; i < n; ++i) {
            if (__gcd(m[i], m[pr[i]]) == 1) {
                s.insert(i);
            }
        }
        vector<int> ans;
        int lst = 1;
        while(!s.empty()) {
            auto it = s.lower_bound(lst);
            if (it == s.end()) {
                lst = 0;
                continue;
            }
            int pos = *it;
            s.erase(it);
            ans.push_back(pos);
            if (ans.size() == n) {
                break;
            }
            nxt[pr[pos]] = nxt[pos];
            pr[nxt[pos]] = pr[pos];
            if (s.find(nxt[pos]) != s.end()) {
                s.erase(nxt[pos]);
            }
            int k = nxt[pos];
            if (__gcd(m[k], m[pr[k]]) == 1) {
                s.insert(k);
            }
            k = (k + 1) % n;
            lst = k;
        }
        cout << ans.size() << " ";
        for (int a : ans){
            printf("%d ", a + 1);
        }
        printf("\n");
    }

    return 0;
}