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

int v[2010][2010];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<string> s;
    string tt;
    {
        rep(i,m+2){
            tt.push_back('*');
        }
    }    
    s.push_back(tt);
    rep(i,n){
        string pp;
        pp.push_back('*');
        string ss;
        cin >> ss;
        rep(i,m){
            pp.push_back(ss[i]);
        }
        pp.push_back('*');
        s.push_back(pp);
    }
    map<char,int> mp;
    
    s.push_back(tt);
    queue<pair<int,int>  > q;
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i][j]=='*')continue;
            int t = 0;
            rep(z,4){
                if(s[i+dx[z]][j+dy[z]]=='.')t++;
            }
            if(t!=0){
                v[i][j] = t;
                if(t==1)q.push(MP(i,j));
            }
        }
    }
    bool ng = 0;
    while(!q.empty()){
        auto x = q.front();
        q.pop();
        int i = x.first;
        int j = x.second;
        if(v[i][j]!=1)continue;
        
        if(v[i][j+1]>0){
            s[i][j] = '<';
            s[i][j+1] = '>';
            v[i][j+1]=0;
            rep(z,4){
                v[i+dx[z]][j+1+dy[z]]--;
                if(v[i+dx[z]][j+1+dy[z]]==1){
                    q.push(MP(i+dx[z],j+1+dy[z]));
                }
            }
        }else if(v[i][j-1]>0){
            
            s[i][j-1] = '<';
            s[i][j] = '>';
            v[i][j-1]=0;
            
            rep(z,4){
                v[i+dx[z]][j-1+dy[z]]--;
                if(v[i+dx[z]][j-1+dy[z]]==1){
                    q.push(MP(i+dx[z],j-1+dy[z]));
                }
            }
        }else if(v[i-1][j]>0){
            
            s[i-1][j] = '^';
            s[i][j] = 'v';
            v[i-1][j]=0;
            rep(z,4){
                v[i-1+dx[z]][j+dy[z]]--;
                if(v[i-1+dx[z]][j+dy[z]]==1){
                    q.push(MP(i-1+dx[z],j+dy[z]));
                }
            }
        }else if(v[i+1][j]>0){
            s[i][j] = '^';
            s[i+1][j] = 'v';
            v[i+1][j]=0;
            rep(z,4){
                v[i+1+dx[z]][j+dy[z]]--;
                if(v[i+1+dx[z]][j+dy[z]]==1){
                    q.push(MP(i+1+dx[z],j+dy[z]));
                }
            }
        }else{
            ng = 1;
            break;
        }
    }
    if(ng){
        cout << "Not unique" << endl;
        return 0;
    
    }
    rep(i,n){
        rep(j,m){
            if(s[i+1][j+1]=='.'){
                cout << "Not unique" << endl;
                return 0;
            }
        }
    }
    rep(i,n){
        rep(j,m){
            cout << s[i+1][j+1];
        }
        cout << "\n";
    }
    return 0;
}