#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
#ifdef LOCAL
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << H;
    debug_out(T...);
}
#define dbg(...) \
    cerr << __LINE__ << " [" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else
#define dbg(...) (void(0))
#define dump(x) (void(0))
#endif
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
int a[100010][3];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n,q;
    n = s.size();
    rep(i,n){
        a[i+1][s[i]-'x']++;
    }
    rep(i,n){
        rep(k,3){
            a[i+1][k] += a[i][k];
        }
    }
    cin >> q;
    rep(i,q){
        int l,r;
        cin >> l >> r;
        bool f = 0;
        if(r-l<2){
            cout << "YES\n";
            continue;
        }
        vector<int> c(3);
        rep(k,3){
            c[k] = a[r][k] - a[l-1][k];
        }
        dbg(c[0],c[1],c[2]);
        if(*max_element(all(c)) - *min_element(all(c)) > 1){
            cout << "NO\n";
        }else{
            cout << "YES\n";
        }
    }
    return 0;
}