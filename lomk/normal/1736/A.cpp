/*input
5
3
1 0 1
0 0 1
4
1 1 0 0
0 1 1 1
2
1 1
1 1
4
1 0 0 1
0 1 1 0
1
0
1
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rloop(i, l, r) for (int i = (int)l; i >= (int)r; --i)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
#endif
// const int N =;

class TestX{
public:
    void operator()(){
        int n;
        cin >> n;
        vector<int> a(n),b(n);
        int cnt[2]; memset(cnt,0,sizeof(cnt));
        for(auto &it:a) cin >> it;
        for(auto &it:b) cin >> it;
        
        int ans1 = 0;
        loop(i,0,n-1) ans1+=(a[i]!=b[i]);
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int ans2 = 1;
        loop(i,0,n-1) ans2+=(a[i]!=b[i]);
        cout << min(ans1,ans2) << endl;
    }
};

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int T; cin >> T;
    while(T--){
        TestX test;
        test();
    }
}