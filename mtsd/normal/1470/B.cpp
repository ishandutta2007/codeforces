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
#define MAX_N 1000010

//2MAX_N-1(O(MAX_N log(MAX_N)))
vector<int> pr[MAX_N],id[MAX_N];
bool is_prime[MAX_N];

void all_fac()
{
    fill(is_prime,is_prime+MAX_N,true);
    for(int i=2;i<MAX_N;i++){
        if(is_prime[i]){
            pr[i].push_back(i);
            id[i].push_back(1);
            for(int j=2*i;j<MAX_N;j+=i){
                is_prime[j] = false;
                int cnt = 0;
                int nw = j;
                while(nw % i == 0){
                    nw /= i;
                    cnt++;
                }
                if(cnt%2==1){
                    pr[j].push_back(i);
                    id[j].push_back(cnt);
                }
            }
        }
    }
}

int d[MAX_N];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    all_fac();
    for(int i=1;i<MAX_N;i++){
        int k = 1;
        for(auto x:pr[i]){
            k *= x;
        }
        d[i] = k;
    }
    rep(zz,t){
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i,n) cin >> a[i];
        unordered_map<int,int> mp;
        rep(i,n){
            mp[d[a[i]]]++;
        }
        int mx = 0;
        int sm = 0;
        for(auto &x:mp){
            chmax(mx,x.second);
            if(x.second%2==0){
                sm += x.second;
            }else if(x.first==1){
                sm += x.second;
            }
        }
        int q;
        cin >> q;
        rep(zz,q){
            ll k;
            cin >> k;
            if(k==0){
                cout << mx << "\n";
            }else{
                cout << max(mx,sm) << "\n";
            }
        }
    }
    return 0;
}