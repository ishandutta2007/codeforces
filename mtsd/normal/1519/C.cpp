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
#define int long long
signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        vector<int> b(n);
        rep(i,n) cin >> b[i];
        vector<vector<int> > p(n);
        rep(i,n){
            p[a[i]-1].push_back(b[i]);
        }
        vector<int> res(n);
        rep(i,n){
            sort(all(p[i]));
            reverse(all(p[i]));
            vector<int> s((int)p[i].size()+1);
            rep(j,p[i].size()){
                s[j+1] += p[i][j];
                s[j+1] += s[j];
            }
            rep(k,n){
                if(k+1>p[i].size())break;
                int c = k+1;
                for(int x = 0;x+c<=(int)p[i].size();x += c){
                    res[k] += s[x+c]-s[x];
                }
            }
        }
        rep(i,n){
            cout << res[i];
            if(i!=n-1)cout << " ";
        }
        cout << "\n";
    }
    return 0;
}