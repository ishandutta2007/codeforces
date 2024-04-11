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

ll dp[21][1<<20];
bool flag[21][1<<20];
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n) cin >> v[i];
    sort(all(v));
    reverse(all(v));
    int m;
    cin >> m;
    vector<pair<int,int> > p;
    rep(i,m){
        char c;
        int s;
        cin >> c >> s;
        if(c=='p'){
            p.push_back(MP(s,0));
        }else{
            p.push_back(MP(s,1));
        }
    }
    auto dfs = [&](auto && f,int Qid,int bit) -> ll{
        if(Qid==m)return 0;
        if(flag[Qid][bit])return dp[Qid][bit];
        flag[Qid][bit] = 1;
        if(p[Qid].second==0){
            // pick
            if(p[Qid].first==1){
                ll ma = -inf;
                rep(i,m){
                    if((bit>>i)&1){

                    }else{
                        chmax(ma, v[i] + f(f,Qid+1,bit^(1<<i)) );
                    }
                }
                return dp[Qid][bit] = ma;
            }else{
                ll mi = inf;
                rep(i,m){
                    if((bit>>i)&1){

                    }else{
                        chmin(mi, -v[i] + f(f,Qid+1,bit^(1<<i)) );
                    }
                }
                return dp[Qid][bit] = mi;
            }
        }else{
            if(p[Qid].first==1){
                ll ma = -inf;
                rep(i,m){
                    if((bit>>i)&1){

                    }else{
                        chmax(ma, f(f,Qid+1,bit^(1<<i)) );
                    }
                }
                return dp[Qid][bit] = ma;
            }else{
                
                ll mi = inf;
                rep(i,m){
                    if((bit>>i)&1){

                    }else{
                        chmin(mi, f(f,Qid+1,bit^(1<<i)) );
                    }
                }
                return dp[Qid][bit] = mi;
            }
        }
    };
    cout << dfs(dfs,0,0) << endl;
    return 0;
}