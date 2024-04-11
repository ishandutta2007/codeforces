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
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int> >a(n,vector<int>(n)),b(n,vector<int>(n));
    rep(i,n){
        string s;
        cin >> s;
        rep(j,n){
            a[i][j] = s[j]-'0';
        }
    }
    rep(i,n){
        string s;
        cin >> s;
        rep(j,n){
            b[i][j] = s[j]-'0';
        }
    }
    vector<int> v(n);
    string s;
    cin >> s;
    rep(i,n) v[i] = s[i]-'0';
    int c = -1;
    rep(i,n){
        if(v[i]==1){
            c = i;
        }
    }
    if(c==-1){
        rep(i,n){
            rep(j,n){
                if(a[i][j]!=b[i][j]){
                    cout << -1 << endl;
                    return 0;
                }
            }
        }
        cout << 0 << endl;
        return 0;
    }
    vector<pair<int,int> > res,res2;
    vector<vector<int> > d = a;
    res.push_back(MP(0,c));// 0 ha row
    rep(i,n){
        d[c][i] ^=v[i];
    }
    rep(i,n){
        if(d[c][i]!=b[c][i]){
            res.push_back(MP(1,i));
            rep(j,n){
                d[j][i] ^= v[j]; 
            }
        }
    }
    
    bool ng = 0;
    rep(i,n){
        bool flag =0;
        rep(j,n){
            if(d[i][j]!=b[i][j]){
                flag = 1;
            }
        }
        if(flag){
            res.push_back(MP(0,i));
            rep(j,n){
                d[i][j]^=v[j];
            }
            rep(j,n){
                if(d[i][j]!=b[i][j]){
                    ng = 1;
                }
            }
        }
        if(ng)break;
    }
    if(!ng){
        cout << res.size() << "\n";
        for(auto x:res){
            if(x.first==0){
                cout << "row " << x.second << "\n"; 
            }else{
                cout << "col " << x.second << "\n";    
            }
        }

        return 0;   
    }
    d = a;
    rep(i,n){
        if(d[c][i]!=b[c][i]){
            res.push_back(MP(1,i));
            rep(j,n){
                d[j][i] ^= v[j]; 
            }
        }
    }
    ng = 0;
    rep(i,n){
        bool flag =0;
        rep(j,n){
            if(d[i][j]!=b[i][j]){
                flag = 1;
            }
        }
        if(flag){
            res.push_back(MP(0,i));
            rep(j,n){
                d[i][j]^=v[j];
            }
            rep(j,n){
                if(d[i][j]!=b[i][j]){
                    ng = 1;
                }
            }
        }
        if(ng)break;
    }
    if(!ng){
        cout << res.size() << "\n";
        for(auto x:res){
            if(x.first==0){
                cout << "row " << x.second << "\n"; 
            }else{
                cout << "col " << x.second << "\n";    
            }
        }

        return 0;   
    }
    cout << -1 << endl;
    return 0;
}