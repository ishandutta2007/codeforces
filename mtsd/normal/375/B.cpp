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

int a[5010][5010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<string> s(n);
    rep(i,n)cin >> s[i];
    rep(i,n){
        int L = -100;
        rep(j,m){
            if(s[i][j]=='1'){
                if(L==-100){
                    L = j;
                }
            }else{
                if(L!=-100){
                    a[L][L]++;
                    a[L][j]--;
                    a[j][L]--;
                    a[j][j]++;
                }
                L = -100;
            }
        }
        if(L!=-100){
            a[L][L]++;
            a[L][m]--;
            a[m][L]--;
            a[m][m]++;
        }
    }
    rep(i,m){
        rep(j,m){
            a[i][j+1] += a[i][j];
        }
    }
    rep(i,m){
        rep(j,m){
            a[i+1][j] += a[i][j];
        }
    }
    // rep(i,m){
    //     rep(j,m){
    //         cerr << a[i][j];
    //     }
    //     cerr << endl;
    // }
    int mx = 0;
    rep(i,m){
        rep(j,i+1){
            chmax(mx,(i-j+1) * a[i][j]);
        }
    }
    cout << mx << endl;
    return 0;
}