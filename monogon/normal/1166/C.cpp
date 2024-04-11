
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long
#define VI vector<int>

using namespace std;

int n;

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    vector<LL> a(n);
    FOR(i, n) {
        cin >> a[i];
    }
    sort(all(a));
    LL c = 0;
    FOR(i, n) {
        LL x = a[i];
        if(x <= 0) {
            auto it = lower_bound(all(a), 2 * x);
            auto it2 = upper_bound(all(a), x);
            // for(auto it3 = it; it3 < it2; it3++) {
            //     if(x == *it3) continue;
            //     cout << "case 1: {" << x << " " << *it3 << "}" << endl;
            // }
            if(it < it2) {
                c += (it2 - it) - 1;
            }
            it = lower_bound(all(a), -x);
            it2 = upper_bound(all(a), -2 * x);
            // for(auto it3 = it; it3 < it2; it3++) {
            //     if(x == *it3) continue;
            //     cout << "case 2: {" << x << " " << *it3 << "}" << endl;
            // }
            if(it < it2) {
                c += (it2 - it);
                if(x == 0) {
                    c--;
                }
            }
        }
        if(x >= 0) {
            auto it = lower_bound(all(a), x);
            auto it2 = upper_bound(all(a), 2 * x);
            
            // for(auto it3 = it; it3 < it2; it3++) {
            //     if(x == *it3) continue;
            //     cout << "case 3: {" << x << " " << *it3 << "}" << endl;
            // }
            if(it < it2) {
                c += (it2 - it) - 1;
            }
            it = lower_bound(all(a), -2 * x);
            it2 = upper_bound(all(a), -x);
            // for(auto it3 = it; it3 < it2; it3++) {
            //     if(x == *it3) continue;
            //     cout << "case 4: {" << x << " " << *it3 << "}" << endl;
            // }
            if(it < it2) {
                c += (it2 - it);
                if(binary_search(all(a), -x)) c--;
            }
        }
    }
    cout << c << endl;
    // c = 0;
    // FOR(i, n) {
    //     LL x = a[i];
    //     FOR(j, i) {
    //         LL y = a[j];
    //         if(abs(x - y) <= min(abs(x), abs(y)) && max(abs(x), abs(y)) <= abs(x + y)) {
    //             c++;
    //             cout << "{" << x << " " << y << "}" << endl;
    //         }else if(abs(x + y) <= min(abs(x), abs(y)) && max(abs(x), abs(y)) <= abs(x - y)) {
    //             c++;
    //             cout << "{" << x << " " << y << "}" << endl;
    //         }
    //     }
    // }
    // cout << c << endl;
}