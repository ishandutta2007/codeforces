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
    int n,m;
    cin >> n >> m;
    vector<pair<vector<int>,int> > b(n);
    vector<vector<int> > a(n,vector<int>(m));
    rep(i,n){
        b[i].first.resize(m);
        rep(j,m){
           cin >> b[i].first[j];
        }
        b[i].second = i;
    }
    rep(i,n)rep(j,m)cin >> a[i][j];
    vector<unordered_set<int> > st(m);
    vector<vector<int>> p(m);
    rep(j,m){
        rep(i,n-1){
            if(a[i][j]>a[i+1][j]){
                st[j].insert(i);
            }else if(a[i][j]<a[i+1][j]){
                p[j].push_back(i);
            }
        }
    }
    unordered_set<int> used;
    vector<bool> ok(m);
    vector<int> res;
    while(1){
        int jd = -1;
        rep(j,m){
            // cerr << "test: " <<  j << " " << st[j].size() << endl;
            if(!ok[j]&&(int)st[j].size()==0){
                jd = j;
                break;   
            }
        }
        if(jd==-1)break;
        res.push_back(jd);
        ok[jd] = 1;
        vector<int> nxt;
        for(auto x:p[jd]){
            if(used.count(x)==0){
                used.insert(x);
                nxt.push_back(x);
            }
        }
        rep(j,m){
            if(!ok[j]){
                for(auto x:nxt){
                    st[j].erase(x);
                }
            }
        }
    }
    reverse(all(res));
    for(auto x:res){
        rep(i,n){
            b[i].second = i;
        }
        sort(all(b),[x](auto const& l,auto const& r){
            if(l.first[x]<r.first[x])return true;
            if(l.first[x]>r.first[x])return false;
            return l.second<r.second;
        });
    }
    // rep(i,res.size())cerr << res[i] << " ";
    // cerr << endl;
    // rep(i,n){
    //     rep(j,m){
    //         cerr << b[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    rep(i,n){
        rep(j,m){
            if(a[i][j]!=b[i].first[j]){
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << res.size() << "\n";
    rep(i,(int)res.size()){
        cout << res[i]+1;
        if(i!=(int)res.size()-1)cout << " ";
    }
    cout << "\n";
    return 0;
}