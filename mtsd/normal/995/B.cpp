#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <numeric>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <deque>
#include <cmath>
#include <complex>
#include <cassert>
#include <cstring>
#include <functional>
#include <bitset>
#define rep(i,n) for(int i = 0; i < (int)n; ++i)
#define ll long long

using namespace std;

#define  PB push_back
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
template<typename V> class BIT {
private:
    int n; vector<V> bit;
public:
    void add(int i,V x){ i++; while(i < n) bit[i] += x, i += i & -i;}
    V sum(int i){ i++; V s = 0; while(i>0) s += bit[i], i -= i & -i; return s;}
    BIT(){} BIT(int sz){ n = sz + 1, bit.resize(n,0);} //0
    BIT(vector<V> v){ n = (int)v.size()+1; bit.resize(n); rep(i,n-1) add(i,v[i]);}
    void print(){ rep(i,n-1)cout<<sum(i)-sum(i-1)<< " ";cout<<endl;}
    void print_sum(){ rep(i,n)cout<<sum(i-1)<<" ";cout<<endl;}	//-1
};

ll inv_count(vector<int>& u,vector<int>& v)
{
    int n = (int)u.size();
    vector<int> p(n);
    BIT<int> bt(n);
    ll ans = 0;
    rep(i,n){
        p[v[i]] = i;
    }
    rep(i,n){
        ans += i-bt.sum(p[u[i]]);
        bt.add(p[u[i]],1);
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<int>v(2*n);
    set<int>st2;
    rep(i,2*n){
        cin >> v[i];
        v[i]--;
        if(st2.count(v[i])==1){
            v[i]+=n;
        }
        st2.insert(v[i]);
    }
    set<int>st;
    vector<int> u;
    rep(i,2*n){
        if(st.count(v[i])==0){
            u.PB(v[i]);
            u.PB(v[i]+n);
            st.insert(v[i]);
            st.insert(v[i]+n);
        }
    }
    cout << inv_count(u,v) << endl;
    return 0;
}