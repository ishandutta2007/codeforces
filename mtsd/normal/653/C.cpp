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

vector<int> a;
bool check(int id){
    if(id%2==0){
        return a[id]<a[id+1];
    }else{
        return a[id]>a[id+1];
    }
}

int main(){
    int n;
    cin >> n;
    a.resize(n);
    rep(i,n) cin >> a[i];
    vector<int> ng;
    rep(i,n-1){
        if(i%2==0){
            if(a[i]>=a[i+1]){
                ng.push_back(i);
            }
        }else{
            if(a[i]<=a[i+1]){
                ng.push_back(i);
            }
        }
    }
    int p = ng[0];
    int q = ng[0]+1;
    set<pair<int,int> > st;
    for(int i=0;i<n;i++){
        bool flag = 1;
        swap(a[i],a[p]);
        // i-1 ,i , ng check
        if(i!=0){
            if(!check(i-1))flag = 0;
        }
        if(i!=n-1){
            if(!check(i))flag = 0;
        }
        for(auto x:ng){
            if(!flag)break;
            if(!check(x))flag = 0;
        }
        if(flag){
            if(i>p){
                st.insert(MP(p,i));
            }else{
                st.insert(MP(i,p));
            }
        }
        swap(a[i],a[p]);   
    }
    p = q;
    for(int i=0;i<n;i++){
        bool flag = 1;
        swap(a[i],a[p]);
        // i-1 ,i , ng check
        if(i!=0){
            if(!check(i-1))flag = 0;
        }
        if(i!=n-1){
            if(!check(i))flag = 0;
        }
        for(auto x:ng){
            if(!flag)break;
            if(!check(x))flag = 0;
        }
        if(flag){
            if(i>p){
                st.insert(MP(p,i));
            }else{
                st.insert(MP(i,p));
            }
        }
        swap(a[i],a[p]);   
    }
    cout << st.size() << endl;
    return 0;
}