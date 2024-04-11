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
vector<set<int> > g;
vector<set<int> > rev;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string>a(n);
    rep(i,n)cin >> a[i];
    g.resize(27);
    rev.resize(27);
    set<int> st;
    bool ng = 0;
    rep(i,n){
        int m = a[i].size();
        set<int>ss;
        rep(j,m-1){
            int c = a[i][j]-'a';
            int d = a[i][j+1]-'a';
            g[c].insert(d);
            rev[d].insert(c);
            st.insert(c);
            st.insert(d);
            if(ss.count(c)!=0||ss.count(d)!=0){
                ng = 1;
            }
            ss.insert(c);
            if(c==d)ng = 1;
        }
        st.insert(a[i][m-1]-'a');
        if(ss.count(a[i][m-1]-'a')!=0){
            ng = 1;
        }
    }
    rep(i,26){
        if(g[i].size()>=2||rev[i].size()>=2){
            ng = 1;
        }
    }
    if(ng){
        cout << "NO" << endl;
        return 0;
    }
    vector<string> res;
    rep(i,26){
        if(st.count(i)==1){
            int cnt = 0;
            int dd = i;
            while(rev[dd].size()!=0){
                dd = *rev[dd].begin();
                cnt++;
                if(cnt>30)break;
            }
            if(cnt>30){
                ng = 1;
                break;
            }
            if(rev[i].size()==0){
                int id = i;
                string tmp;
                while(g[id].size()!=0){
                    tmp.push_back('a'+id);
                    id = *g[id].begin();
                }
                tmp.push_back('a'+id);
                res.push_back(tmp);
            }
        }
    }
    if(ng){
        cout << "NO" << endl;
        return 0;
    }
    sort(res.begin(),res.end());
    for(auto x:res){
        cout << x;
    }
    cout << endl;
    return 0;
}