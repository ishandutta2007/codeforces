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
    cin >> t;
    rep(zz,t){
        int n,m;
        cin >> n >> m;
        vector<string > s(n);
        rep(i,n)cin >> s[i];
        rep(i,n){
            if(i%3==0){
                rep(j,m){
                    s[i][j] = 'X';
                }
            }else if(i%3==1){
                if(i==n-2){
                    rep(j,m){
                        if(s[i+1][j]=='X'){
                            s[i][j] = 'X';
                        }
                    }
                    continue;
                }
                int id = 0;
                rep(j,m){
                    if(s[i][j]=='X')id = j;
                    if(i!=n-1){
                        if(s[i+1][j]=='X')id = j;
                    }
                }
                rep(k,2){
                    if(i+k<n){
                        s[i+k][id] = 'X';
                    }
                }
            }
        }
        rep(i,n)cout << s[i] << "\n";
        // cerr << endl;
    }
    return 0;
}