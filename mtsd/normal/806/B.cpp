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
    int n;
    cin >> n;
    vector<int> a(5);
    vector<int> b(5);
    vector<int> c(5);
    rep(i,5){
        cin >> a[i];
        if(a[i]!=-1)c[i]++;
    }
    rep(i,5){
        cin >> b[i];
        if(b[i]!=-1)c[i]++;
    }
    rep(i,n-2){
        rep(j,5){
            int k;
            cin >> k;
            if(k!=-1){
                c[j]++;
            }
        }
    }
    int ok = 1<<30;
    for(int mid=0;mid<=5000000;mid++){
        vector<int> cc(5);
        rep(i,5){
            if(a[i]==-1){
                cc[i] = c[i];
            }else{
                if(b[i]!=-1&&a[i]>b[i]){
                    cc[i] = c[i]+mid;
                }else{
                    cc[i] = c[i];
                }
            }
        }
        int N = n + mid;
        int A = 0,B =0;
        rep(i,5){
            int M;
            if(a[i]!=-1){
                if(32*cc[i]<=N){
                    M = 3000;
                }else if(16*cc[i]<=N){
                    M = 2500;
                }else if(8*cc[i]<=N){
                    M = 2000;
                }else if(4*cc[i]<=N){
                    M = 1500;
                }else if(2*cc[i]<=N){
                    M = 1000;
                }else{
                    M = 500;
                }            
                A += M*(250-a[i])/250;
            }
        }
        rep(i,5){
            int M;
            if(b[i]!=-1){
                if(32*cc[i]<=N){
                    M = 3000;
                }else if(16*cc[i]<=N){
                    M = 2500;
                }else if(8*cc[i]<=N){
                    M = 2000;
                }else if(4*cc[i]<=N){
                    M = 1500;
                }else if(2*cc[i]<=N){
                    M = 1000;
                }else{
                    M = 500;
                }
                B += M*(250-b[i])/250;
            }
        }
        if(A>B){
            ok = mid;
            break;
        }
    }
    if(ok==(1<<30)){
        cout << -1 << endl;
    }else{
        cout << ok << endl;
    }
    return 0;
}