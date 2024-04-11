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
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        bool flag = 1;
        rep(i,n){
            if(s[i]!='L'){
                flag = 0;
                break;
            }
        }
        if(flag){
            if(k==0){
                cout << 0 << "\n";
            }else{
                cout << 2*k-1 << "\n";
            }
            continue;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> > pq;
        int pre  = -1;
        int c = 0;
        rep(i,n){
            if(s[i]=='L'){
                if(pre==-1){
                    pre = i;
                    c = 1;
                }else{
                    c++;   
                }
            }else{
                if(c!=0){
                    if(pre!=0)pq.push(MP(c,pre));
                    c = 0;
                    pre = -1;
                }
            }
        }
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            if(x.first >k)break;
            k-=x.first;
            for(int i=x.second;i<x.second+x.first;i++){
                s[i]='W';
            }
        }
        rep(i,n){
            if(s[i]=='L'&&s[i+1]=='W'&&k>0){
                int id = i;
                while(k>0&&id>=0){
                    s[id] = 'W';
                    id--;
                    k--;
                }
            }
            if(i!=0&&s[i]=='L'&&s[i-1]=='W'&&k>0){
                s[i] ='W';
                k--;
            }
        }
        int res = 0;
        rep(i,n){
            if(s[i]=='W'){
                if(i!=0&&s[i-1]=='W'){
                    res += 2;
                }else{
                    res += 1;
                }
            }
        }
        // cerr << s << endl;
        cout << res << "\n";
    }
    return 0;
}