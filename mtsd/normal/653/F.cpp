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

class suffixarray{
public:
    int sz,index1,index2;
    vector<int> rnk,tmp,sa,lcp;
    string recs;
    suffixarray(string s){
        recs = s;
        sz = (int)s.size();
        rnk.resize(sz+1),tmp.resize(sz+1);
        make_sa();
        make_lcp();
    }
    void make_sa(){
        index1 = sz;
        sa.resize(index1+1);
        for(int i = 0; i < index1+1; i++){
            sa[i] = i;
            rnk[i] = i<index1?recs[i]:-1;
        }
        auto comp = [&](int i,int j){
            if(rnk[i] != rnk[j]){
                return rnk[i] < rnk[j];
            }else{
                int ri = (i+index2<=index1)?rnk[i+index2]:-1;
                int rj = (j+index2<=index1)?rnk[j+index2]:-1;
                return ri < rj;
            }
        };
        for(index2=1;index2<=index1;index2*=2){
            sort(sa.begin(),sa.end(),comp);
            tmp[sa[0]] = 0;
            for(int i=1;i<=index1;i++){
                tmp[sa[i]] = tmp[sa[i-1]]+(comp(sa[i-1],sa[i])?1:0);
            }
            for(int i = 0; i < index1+1; i++){
                rnk[i] = tmp[i];
            }
        }
    }
    void make_lcp(){
        lcp.resize(sz+1);
        for(int i = 0; i < sz+1; i++){
            rnk[sa[i]] = i;
        }
        int h = 0;
        lcp[0] = 0;
        for(int i = 0; i < sz; i++){
            int j = sa[rnk[i]-1];
            if(h > 0){
                h--;
            }
            for(;j+h<sz&&i+h<sz;h++){
                if(recs[j+h] != recs[i+h]){
                    break;
                }
            }
            lcp[rnk[i]-1] = h;
        }
    }
};

int a[500010];
vector<int> p[1000010];
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    cin >> s;
    a[0] = 500005;
    rep(i,n){
        if(s[i]=='('){
            a[i+1] = a[i]+1;
        }else{
            a[i+1] = a[i]-1;
        }
    }
    rep(i,n+1){
        p[a[i]].push_back(i);
    }
    suffixarray saa(s);
    vector<int> &sa = saa.sa;
    vector<int> &lcp = saa.lcp;
    // rep(i,n){
    //     // cerr << sa[i] << " " << lcp[i] << endl;
    //     for(int j=sa[i];j<n;j++){
    //         cout << s[j];
    //     }
    //     cout << endl;
    // }
    // cerr << endl;
    ll res = 0;
    for(int i=1;i<n;i++){
        if(s[sa[i]]!='(')break;
        int L = lcp[i];
        int id = sa[i];
        auto X = lower_bound(p[a[id]-1].begin(),p[a[id]-1].end(),id);
        int nxt;
        if(X!=p[a[id]-1].end()){
            nxt = (*X)-1;
        }else{
            nxt = n;
        }
        // cerr << id << " " << L << " " << nxt << endl;
        res += upper_bound(p[a[id]].begin(),p[a[id]].end(),nxt) - upper_bound(p[a[id]].begin(),p[a[id]].end(),min(nxt,id+L));
        // cerr << sa[i] << " " << res << endl;
    }
    cout << res << endl;
    return 0;
}