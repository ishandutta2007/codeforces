/*input
2 500000
499999 499999


10 5
4 3 2 1 4 3 2 4 3 4


7 8
7 7 7 7 7 7 7


8 3
3 2 2 2 2 2 1 1


6 4
3 2 2 2 3 3
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
const int N = 5e5+5;

int n,m;
vector<int> a;
int cnt[N];
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    loop(i,0,n-1){
        int x; cin >> x;
        if (x<m) cnt[x]++;
    }
    loop(i,1,N-5){
        while(cnt[i]>=(i+1)){
            cnt[i]-=(i+1);
            cnt[i+1]++;
        }
    }
    loop(i,1,m-1) if (cnt[i]){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
}