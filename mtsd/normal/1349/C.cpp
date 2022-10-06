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

int a[1001][1001];
int p[1001][1001];
bool used[1001][1001];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,t;
    cin >> n >> m >> t;
    rep(i,n){
        string s;
        cin >> s;
        rep(j,m){
            a[i][j] = s[j]-'0';
        }
    }
    queue<pair<int,int> > q;
    rep(i,n){
        rep(j,m){
            if(j!=m-1){
                if(a[i][j]==a[i][j+1]){
                    if(!used[i][j]){
                        q.push(MP(i,j));
                        used[i][j] = 1;
                    }
                    if(!used[i][j+1]){
                        q.push(MP(i,j+1));
                        used[i][j+1] = 1;
                    }
                }
            }
            if(i!=n-1){
                if(a[i][j]==a[i+1][j]){
                    if(!used[i][j]){
                        q.push(MP(i,j));
                        used[i][j] = 1;
                    }
                    if(!used[i+1][j]){
                        q.push(MP(i+1,j));
                        used[i+1][j] = 1;
                    }
                }
            }
        }
    }
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int i = x.first;
        int j = x.second;
        
        if(i!=0){
            if(!used[i-1][j]){
                used[i-1][j]=1;
                q.push(MP(i-1,j));
                p[i-1][j] = p[i][j] + 1;
            }
        }
        if(i!=n-1){
            if(!used[i+1][j]){
                used[i+1][j]=1;
                q.push(MP(i+1,j));
                p[i+1][j] = p[i][j] + 1;
            }
        }
        if(j!=0){
            if(!used[i][j-1]){
                used[i][j-1]=1;
                q.push(MP(i,j-1));
                p[i][j-1] = p[i][j] + 1;
            }
        }
        if(j!=m-1){
            if(!used[i][j+1]){
                used[i][j+1]=1;
                q.push(MP(i,j+1));
                p[i][j+1] = p[i][j] + 1;
            }
        }
    }
    rep(zz,t){
        int i,j;
        ll c;
        cin >> i >> j >> c;
        i--;j--;
        if(!used[i][j]){
            cout << a[i][j] << "\n";
            continue;
        }
        if(c<=p[i][j]){
            cout << a[i][j] << "\n";
        }else{
            c -= p[i][j];
            c %= 2;
            cout << (a[i][j]+c)%2 << "\n";
        }
    }
    return 0;
}