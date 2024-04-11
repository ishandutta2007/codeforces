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

bool OK = 0;
int dfs(int id,int pre,vector<vector<int> > &g){
    int d = 0;
    int c = 0;
    for(auto x:g[id]){
        if(x!=pre){
            int k = dfs(x,id,g);
            if(k>=2)c++;
            chmax(d,k);
        }
    }
    d++;
    if(c>=2)OK = 1;
    return d;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        OK = 0;
        int n;
        cin >> n;
        vector<vector<int> > g(n);
        rep(i,n-1){
            int a,b;
            cin >> a >> b;
            a--;b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        string s;
        cin >> s;
        if(n<=2){
            cout << "Draw\n";
            continue;
        }
        if(n==3){
            int c = 0;
            rep(i,n){
                if(s[i]=='W')c++;
            }
            if(c>=2){
                cout << "White\n";
            }else{
                cout << "Draw\n";
            }
            continue;
        }
        bool flag = 0;
        bool fflag = 0;
        rep(i,n){
            if(g[i].size()>=4){
                flag = 1;
            }else if(g[i].size()==3){
                fflag = 1;
            }
            if(s[i]=='W'&&g[i].size()>=2){
                flag = 1;
            }
        }
        if(flag){
            cout << "White\n";
            continue; 
        }
        if(fflag){
            int c3 = 0;
            rep(i,n){
                if(g[i].size()==3){
                    c3++;
                    dfs(i,-1,g);
                    if(OK)break;
                }
            }
            if(OK){
                cout << "White\n";
                continue;
            }
            if(c3==1){
                int cw = 0;
                int num = 0;
                rep(i,n){
                    if(s[i]=='W'){
                        cw++;
                        num = i;
                    }
                }
                if(cw==0){
                    cout << "Draw\n";
                }else if(cw==1){
                    int p = g[num][0];
                    if(g[p].size()==3){
                        cout << "White\n";
                    }else{
                        if((n-3)%2==0){
                            cout << "Draw\n";
                        }else{
                            cout << "White\n";    
                        }
                    }
                }else{
                    cout << "White\n";
                }
            }else{
                rep(i,n){
                    if(s[i]=='W'){
                        OK =1;
                    }
                }
                if(OK){
                    cout << "White\n";
                    continue;
                }
                if((n-6)%2==1){
                    cout << "White\n";
                }else{
                    cout << "Draw\n";
                }
            }
        }else{
            int cc = 0;
            rep(i,n){
                if(g[i].size()==1&&s[i]=='W'){
                    cc++;
                }
            }
            if(cc!=2){
                cout << "Draw\n";
            }else{
                if(n%2==1){
                    cout << "White\n";
                }else{
                    cout << "Draw\n";
                }
            }
        }
    }
    return 0;
}