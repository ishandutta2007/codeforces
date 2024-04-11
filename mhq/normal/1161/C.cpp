    #pragma optimize "-O3"
    #include <bits/stdc++.h>
    using namespace std;
    typedef long double ld;
    typedef long long ll;
    int f[55];
    int n;
    int grundy(vector < int > f) {
        int cnt = 0;
        for (int i = 0; i < 4; i++) {
            if (f[i] != 0) cnt++;
        }
        if (cnt < 2) return 0;
        set < int > grun;
        for (int i1 = 0; i1 < 4; i1++) {
            for (int j1 = i1 + 1; j1 < 4; j1++) {
                for (int a = 1; a <= f[i1]; a++) {
                    for (int b = 1; b <= f[j1]; b++) {
                        vector < int > t = f;
                        t[i1] = f[i1] - a;
                        t[j1] = f[j1] - b;
                        grun.insert(grundy(t));
                    }
                }
            }
        }
        int s = 0;
        while (grun.find(s) != grun.end()) s++;
        return s;
    }
    int a[55];
    int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
       // freopen("input.txt", "r", stdin);
        vector < int > f(4);
       // for (int i = 0; i < 4; i++) cin >> f[i];
        //cout << grundy(f) << " " << ((f[0] ^ f[1]) ^ (f[2] ^ f[3]));
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int k = n / 2;
        for (int i = 1; i <= 51; i++) {
            int cnt = 0;
            for (int j = 1; j <= n; j++) {
                if (a[j] < i) cnt++;
            }
            if (cnt <= k && cnt > 0) {
                cout << "Alice";
                return 0;
            }
        }
        cout << "Bob";
        return 0;
    }