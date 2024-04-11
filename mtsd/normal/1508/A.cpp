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
        int n;
        cin >> n;
        string s[3];
        rep(i,3)cin >> s[i];
        int a[3][2]={};
        rep(i,3){
            rep(j,2*n){
                a[i][s[i][j]-'0']++;
            }
        }
        bool f = 0;
        rep(i,3){
            if(f)break;
            rep(j,i){
                if(f)break;
                rep(k,2){
                    if(f)break;
                    if(a[i][k]>=n&&a[j][k]>=n){
                        // cerr << i << " " << j << " " << k << endl;
                        char p = '0'+k;
                        char q = '0'+(1-k);
                        string t;
                        int jid = 0;
                        rep(z,2*n){
                            // cerr << z << " " << t << " " << jid << endl;
                            if(jid<2*n){
                                while(s[j][jid]==q){
                                    t.push_back(q);
                                    jid++;
                                }
                            }
                            t.push_back(s[i][z]);
                            if(s[i][z]==p){
                                jid++;
                            }
                        }
                        while(jid<2*n){
                            t.push_back(s[j][jid]);
                            jid++;
                        }
                        while(t.size()<3*n){
                            t.push_back(p);
                        }
                        cout << t << "\n";
                        f = 1;
                    }
                }
            }
        }
    }
    return 0;
}