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
        int n;
        cin >> n;
        vector<string> s(n);
        rep(i,n)cin >> s[i];
        int a[2]={};
        rep(i,n){
            rep(j,n){
                if(s[i][j]=='O')a[0]++;
                else if(s[i][j]=='X')a[1]++;
            }
        }
        if(a[0]>a[1]){
            int mi = inf;
            int A = -1;
            rep(k,3){
                int d = 0;
                rep(i,n){
                    rep(j,n){
                        if((i+j)%3==k){
                            if(s[i][j]=='O'){
                                d++;
                            }
                        }else{
                            if(s[i][j]=='X'){
                                d++;
                            }
                        }
                    }
                }   
                if(chmin(mi,d)){
                    A = k;
                }
            }
            rep(i,n){
                rep(j,n){
                    if((i+j)%3==A){
                        if(s[i][j]=='O'){
                            s[i][j] = 'X';
                        }
                    }else{
                        if(s[i][j]=='X'){
                            s[i][j] = 'O';
                        }
                    }
                }
            }
            // cerr << a[0] + a[1] << " " << mi << endl;
        }else{
            int mi = inf;
            int A = -1;
            rep(k,3){
                int d = 0;
                rep(i,n){
                    rep(j,n){
                        if((i+j)%3!=k){
                            if(s[i][j]=='O'){
                                d++;
                            }
                        }else{
                            if(s[i][j]=='X'){
                                d++;
                            }
                        }
                    }
                }   
                if(chmin(mi,d)){
                    A = k;
                }
            }
            rep(i,n){
                rep(j,n){
                    if((i+j)%3!=A){
                        if(s[i][j]=='O'){
                            s[i][j] = 'X';
                        }
                    }else{
                        if(s[i][j]=='X'){
                            s[i][j] = 'O';
                        }
                    }
                }
            }
            
            // cerr << a[0] + a[1] << " " << mi << endl;
        }
        rep(i,n){
            cout << s[i] << "\n";
        }
    }
    return 0;
}