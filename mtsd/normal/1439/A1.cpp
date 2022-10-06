#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
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
        vector<string> s(n);
        rep(i,n)cin >> s[i];
        vector<pair<int,int> > res;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m-1;j++){
                if(i==n-2&&j==m-2){
                    for(int bit=0;bit<(1<<4);bit++){
                        int a[2][2]={};
                        vector<pair<int,int> > p;
                        if((bit>>0)&1){
                            p.push_back({0,0});
                            p.push_back({0,1});
                            p.push_back({1,0});
                            a[0][0]++;
                            a[0][1]++;
                            a[1][0]++;
                        }
                        if((bit>>1)&1){
                            p.push_back({0,0});
                            p.push_back({0,1});
                            p.push_back({1,1});
                            a[0][0]++;
                            a[0][1]++;
                            a[1][1]++;
                        }
                        if((bit>>2)&1){
                            p.push_back({0,0});
                            p.push_back({1,0});
                            p.push_back({1,1});
                            a[0][0]++;
                            a[1][0]++;
                            a[1][1]++;
                        }
                        if((bit>>3)&1){
                            p.push_back({1,0});
                            p.push_back({0,1});
                            p.push_back({1,1});
                            a[1][0]++;
                            a[0][1]++;
                            a[1][1]++;
                        }
                        bool ok = 1;
                        rep(x,2){
                            rep(y,2){
                                if((s[n-2+x][m-2+y]-'0')!=a[x][y]%2){
                                    ok = 0;
                                }
                            }
                        }
                        if(ok){
                            for(auto xx:p){
                                res.push_back({n-2+xx.first,m-2+xx.second});
                                s[n-2+xx.first][m-2+xx.second] = '1'-s[n-2+xx.first][m-2+xx.second] + '0';
                            }
                            break;
                        }
                    }
                    continue;
                }
                if(s[i][j]=='1'){
                    if(j==m-2&&s[i][j+1]=='1'){
                        s[i][j] = '1'-s[i][j] + '0';
                        res.push_back(MP(i,j));
                        s[i][j+1] = '1'-s[i][j+1] + '0';
                        res.push_back(MP(i,j+1));
                        s[i+1][j] = '1'-s[i+1][j] + '0';
                        res.push_back(MP(i+1,j));
                    }else{
                        if(j==m-2&&s[i][j+1]=='0'){
                            s[i][j] = '1'-s[i][j] + '0';
                            res.push_back(MP(i,j));
                            s[i+1][j+1] = '1'-s[i+1][j+1] + '0';
                            res.push_back(MP(i+1,j+1));
                            s[i+1][j] = '1'-s[i+1][j] + '0';
                            res.push_back(MP(i+1,j));
                        }else if(i==n-2&&s[i+1][j]=='1'){
                            s[i][j] = '1'-s[i][j] + '0';
                            res.push_back(MP(i,j));
                            s[i+1][j+1] = '1'-s[i+1][j+1] + '0';
                            res.push_back(MP(i+1,j+1));
                            s[i+1][j] = '1'-s[i+1][j] + '0';
                            res.push_back(MP(i+1,j));
                        
                        }else{
                            s[i][j] = '1'-s[i][j] + '0';
                            res.push_back(MP(i,j));
                            s[i+1][j+1] = '1'-s[i+1][j+1] + '0';
                            res.push_back(MP(i+1,j+1));
                            s[i][j+1] = '1'-s[i][j+1] + '0';
                            res.push_back(MP(i,j+1));
                        }
                    }
                }else{
                    if(j==m-2){
                        if(s[i][j+1]=='1'){
                            s[i][j+1] = '1'-s[i][j+1] + '0';
                            res.push_back(MP(i,j+1));
                            s[i+1][j+1] = '1'-s[i+1][j+1] + '0';
                            res.push_back(MP(i+1,j+1));
                            s[i+1][j] = '1'-s[i+1][j] + '0';
                            res.push_back(MP(i+1,j));
                        }
                    }else if(i==n-2){
                        if(s[i+1][j]=='1'){
                            s[i][j+1] = '1'-s[i][j+1] + '0';
                            res.push_back(MP(i,j+1));
                            s[i+1][j+1] = '1'-s[i+1][j+1] + '0';
                            res.push_back(MP(i+1,j+1));
                            s[i+1][j] = '1'-s[i+1][j] + '0';
                            res.push_back(MP(i+1,j));
                        }
                    }
                }
                // rep(a,n){
                //     rep(b,m){
                //         cerr << s[a][b];
                //     }
                //     cerr << endl;
                // }
            }
            
        }
        
        int sss = (int)res.size()/3;
        if(sss>n*m)assert(0);
        cout << sss << "\n";
        rep(i,res.size()){
            cout << res[i].first+1 << " " << res[i].second+1 << " ";
            if(i%3==2)cout << "\n";
        }
        // rep(i,n){
        //     rep(j,m){
        //         cerr << s[i][j];
        //     }
        //     cerr << endl;
        // }
    }

    return 0;
}