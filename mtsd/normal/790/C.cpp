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

int dp[76][76][76][2];

int main(){
    int n;
    string s;
    cin >> n >> s;
    int a,b,c;
    a = b = c = 0;
    rep(i,n){
        if(s[i]=='V'){
            a++;
        }else if(s[i]=='K'){
            b++;
        }else{
            c++;
        }
    }
    Fill(dp,inf);
    dp[0][0][0][0] = 0;
    rep(i,a+1){
        rep(j,b+1){
            rep(k,c+1){
                rep(zz,2){
                    if(dp[i][j][k][zz]!=inf){
                        vector<bool> used(n);
                        int p = i;
                        int q = j;
                        int r = k;
                        rep(i,n){
                            if(s[i]=='V'){
                                if(p!=0){
                                    p--;
                                    used[i] = 1;
                                }
                            }else if(s[i]=='K'){
                                if(q!=0){
                                    q--;
                                    used[i] = 1;
                                }
                            }else{
                                if(r!=0){
                                    r--;
                                    used[i] = 1;
                                }
                            }
                        }
                        // V, K , otherwise
                        int C = 0;
                        if(i!=a){
                            rep(i,n){
                                if(s[i]=='V'){
                                    if(!used[i])break;
                                }else{
                                    if(!used[i])C++;
                                }
                            }
                            chmin(dp[i+1][j][k][1],dp[i][j][k][zz] + C); 
                        }
                        if(j!=b){
                            if(zz!=1){
                                C = 0;
                                rep(i,n){
                                    if(s[i]=='K'){
                                        if(!used[i])break;
                                    }else{
                                        if(!used[i])C++;
                                    }
                                }
                                chmin(dp[i][j+1][k][0],dp[i][j][k][zz] + C); 
                            }
                        }
                        if(k!=c){
                            C = 0;
                            rep(i,n){
                                if(s[i]!='K'&&s[i]!='V'){
                                    if(!used[i])break;
                                }else{
                                    if(!used[i])C++;
                                }
                            }
                            chmin(dp[i][j][k+1][0],dp[i][j][k][zz] + C); 
                        }
                    }
                }
            }
        }
    }
    cout << min(dp[a][b][c][0],dp[a][b][c][1]) << endl;
    return 0;
}