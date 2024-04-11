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

vector<long long> dev;
vector<int> id;

void prime_factor(long long N){
    for(int i=2;(long long)i*i<=N;i++){
        int cnt = 0;
        while(N%i == 0){
            cnt++;
            N /= i;
        }
        if(cnt){
            dev.push_back(i);
            id.push_back(cnt);
        }
    }
    if(N != 1){
        dev.push_back(N);
        id.push_back(1);
    }
    return;
}
#define int long long

void calc(ll k,int m,int bits,vector<ll> &res){
    if(m==(int)dev.size()){
        res.push_back(k);
        return;
    }
    {
        if((bits>>m)&1){
            rep(i,id[m]){
                k *= dev[m];
                calc(k,m+1,bits,res);
            }
        }else{
            calc(k,m+1,bits,res);
        }
    }
}

void solve(int n){
    dev.clear();
    id.clear();
    prime_factor(n);
    int ans = 0;
    if(dev.size()==1){
        int k = dev[0];
        for(int i=0;i<id[0];i++){
            cout << k ;
            k *= dev[0];
            if(i!=id[0]-1){
                cout << " ";
            }
        }
        cout << "\n";
        cout << ans << "\n";
    }else if(dev.size()==2){
        if(id[0]==1&&id[1]==1){
            ans = 1;
            cout << dev[0] << " " << dev[1] << " " << dev[0]*dev[1] << "\n";
            cout << ans << "\n";
        }else{
            int k = dev[0];
            for(int i=0;i<id[0];i++){
                cout << k << " ";
                k *= dev[0];
                
            }
            cout << dev[0]*dev[1] << " ";
            k = dev[1];
            for(int i=0;i<id[1];i++){
                cout << k << " ";
                k *= dev[1];
            }
            int x = dev[0];
            for(int i=1;i<=id[0];i++){
                int y = dev[1];
                for(int j=1;j<=id[1];j++){
                    if(i==1&&j==1){
                    }else{
                        cout << x*y << " ";
                    }
                    y *= dev[1];
                }
                x *= dev[0];
            }
            cout << "\n";
            cout << ans << "\n";
        }
    }else{
        vector<ll> res;
        int pre = 0;
        for(int i=1;i<=dev.size();i++){
            if(i!=dev.size()){
                int bits = (1<<i)-1;
                for(int j=bits;j>pre;j--){        
                    calc(1,0,j,res);
                }
                pre = bits;
            }else{
                int bits = (1<<i)-2;
                for(int j=bits;j>pre;j--){        
                    calc(1,0,j,res);
                }
                calc(1,0,(1<<i)-1,res);
            }
        }
        
        
        for(auto x:res){
            cout << x << " ";
        }
        cout <<"\n";
        cout << ans << "\n";
    }

}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    rep(zz,t){
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}