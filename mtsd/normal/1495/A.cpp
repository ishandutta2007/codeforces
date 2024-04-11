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

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    int n;
    cin >> t;
    rep(zz,t){
        int n;
        cin >> n;
        vector<ll> a,b;
        rep(i,2*n){
            int p,q;
            cin >> p >> q;
            if(p==0){
                a.push_back(abs(q));
            }else{
                b.push_back(abs(p));
            }
        }
        sort(all(a));
        sort(all(b));
        double res = 0;
        rep(i,n){
            res += sqrt(a[i]*a[i]+b[i]*b[i]);
        }
        cout << fixed << setprecision(20) << res << "\n";
    }
    return 0;
}