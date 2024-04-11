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
void act(vector<int>&a,vector<int>p){
    vector<vector<int> >v;
    int id = 0;
    for(auto x:p){    
        vector<int> tmp;
        rep(i,x){
            tmp.push_back(a[id]);
            id++;
        }
        v.push_back(tmp);
    }
    reverse(all(v));
    vector<int> pp;
    for(auto& x:v){
        for(auto&y:x){
            pp.push_back(y);
        }
    }
    swap(a,pp);
}
void show(vector<int>&p){
    cout << p.size() << " ";
    rep(i,p.size()){
        cout << p[i];
        if(i!=(int)p.size()-1)cout << " ";
    }
    cout << "\n";
}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<vector<int> > res;
    while(1){
        bool flag = 1;
        int id = 0;
        rep(i,n-1){
            if(a[i]>a[i+1]){
                flag = 0;
                break;
            }
        }
        if(flag)break;
        flag = 1;
        rep(i,n-1){
            if(a[i]<a[i+1]){
                flag = 0;
                break;
            }
        }
        if(flag){
            vector<int> p(n,1);
            act(a,p);
            res.push_back(p);
            continue;
        }
        int k = 0;
        rep(i,n){
            if(a[i]==1){
                k = i;
                break;
            }
        }
        if(k!=0&&a[k-1]==2){
            int R = k;
            int L = k-1;
            int pp = 2;
            while(L>0){
                if(a[L-1]==pp+1){
                    L--;
                    pp++;
                }else{
                    break;
                }
            }
            int nxt = 0;
            rep(i,n){
                if(a[i]==pp+1){
                    nxt = i;
                    break;
                }
            }
            if(R < nxt){
                vector<int> s;
                for(int i=0;i<n;i++){
                    if(i>=L&&i<=R){
                        if(i==R){
                            s.push_back(R-L+1);
                        }
                    }else if(i>=R+1&&i<=nxt){
                        if(i==nxt){
                            s.push_back(nxt-R);
                        }
                    }else{
                        s.push_back(1);
                    }
                }
                act(a,s);
                res.push_back(s);
            }else{
                vector<int> s;
                for(int i=0;i<n;i++){
                    if(i>=L&&i<=R){
                        s.push_back(1);
                    }else if(i<=L-1&&i>=nxt){
                        if(i==L-1){
                            s.push_back(L-1-nxt + 1);
                        }
                    }else{
                        s.push_back(1);
                    }
                }
                act(a,s);
                res.push_back(s);
            }
        }else{
            int R = k;
            int L = k;
            int pp = 1;
            while(R<n-1){
                if(a[R+1]==pp+1){
                    R++;
                    pp++;
                }else{
                    break;
                }
            }
            int nxt = 0;
            rep(i,n){
                if(a[i]==pp+1){
                    nxt = i;
                    break;
                }
            }
            if(R < nxt){
                vector<int> s;
                for(int i=0;i<n;i++){
                    if(i>=L&&i<=R){
                        // if(i==R){
                            s.push_back(1);
                        // }
                    }else if(i>=R+1&&i<=nxt){
                        if(i==nxt){
                            s.push_back(nxt-R);
                        }
                    }else{
                        s.push_back(1);
                    }
                }
                res.push_back(s);
            
                act(a,s);
            }else{
                vector<int> s;
                for(int i=0;i<n;i++){
                    if(i>=L&&i<=R){
                        if(i==R){
                            s.push_back(R-L+1);
                        }
                    }else if(i<=L-1&&i>=nxt){
                        if(i==L-1){
                            s.push_back(L-1-nxt + 1);
                        }
                    }else{
                        s.push_back(1);
                    }
                }
                res.push_back(s);
            
                act(a,s);
            }
        }
        // rep(i,n){
        //     cerr << a[i] << " ";
        // }
        // cerr << endl;
        // int x;
        // cin >> x;
    }
    cout << res.size() << "\n";
    for(auto x:res){
        show(x);
    }
    return 0;
}