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

long long mod_pow(long long a,long long b,long long MOD)
{
    a %= MOD;
    long long res = 1;
    while(b){
        if(b & 1){
            res = res * a % MOD;
        }
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int n,m,seed,vmax;
int rnd(){
    int p = seed;
    seed = ((ll)seed*7+13) %1000000007;
    return p;
}
ll a[100010];
int main(){
    cin >> n >> m >> seed >> vmax;
    set<pair<pair<int,int>,ll> > st;
    for(int i=0;i<n;i++){
        a[i] = (rnd()%vmax)+1;
        st.insert(MP(MP(i+1,i+1),a[i]));
    }
    int sm = 0;
    for(int zz=0;zz<m;zz++){
        int op = rnd()%4;
        op++;
        int l = rnd()%n;
        l++;
        int r = rnd()%n;
        r++;
        if(r<l)swap(l,r);
        if(op==1){
            int x = (rnd()%(vmax)) + 1;
            // for(int i=l;i<=r;i++){
            //     a[i] += x;
            // }
            auto p = st.lower_bound(MP(MP(l+1,0),0));
            p--;
            while(1){
                if(p==st.end())break;
                if((*p).first.first > r)break;
                int L = (*p).first.first;
                int R = (*p).first.second;
                ll V = (*p).second;
                if(L<l){
                    st.erase(p);
                    st.insert({{L,l-1},V});
                    if(R>r){
                        st.insert({{l,r},V+x});
                        st.insert({{r+1,R},V});
                        break;
                    }else{
                        st.insert({{l,R},V+x});
                        p = st.lower_bound({{R+1,0},0});
                    }
                }else{
                    st.erase(p);
                    if(R>r){
                        st.insert({{L,r},V+x});
                        st.insert({{r+1,R},V});
                        break;
                    }else{
                        st.insert({{L,R},V+x});
                        p = st.lower_bound({{R+1,0},0});
                    }
                }
            }
        }else if(op==2){
            int x = (rnd()%(vmax)) + 1;
            // for(int i=l;i<=r;i++){
            //     a[i] = x;
            // }
            auto p = st.lower_bound(MP(MP(l+1,0),0));
            p--;
            while(1){
                if(p==st.end())break;
                if((*p).first.first > r)break;
                int L = (*p).first.first;
                int R = (*p).first.second;
                ll V = (*p).second;
                if(L<l){
                    st.erase(p);
                    st.insert({{L,l-1},V});
                    if(R>r){
                        st.insert({{r+1,R},V});
                        break;
                    }else{
                        p = st.lower_bound({{R+1,0},0});
                    }
                }else{
                    st.erase(p);
                    if(R>r){
                        st.insert({{r+1,R},V});
                        break;
                    }else{
                        p = st.lower_bound({{R+1,0},0});
                    }
                }
            }
            st.insert({{l,r},x});
        }else if(op>=3){
            int x;
            if(op==3)x = (rnd()%(r-l+1)) + 1;
            else x = (rnd()%(vmax)) + 1;
            map<ll,int> mp;
            auto p = st.lower_bound(MP(MP(l+1,0),0));
            p--;
            while(1){
                if(p==st.end())break;
                if((*p).first.first > r)break;
                int L = (*p).first.first;
                int R = (*p).first.second;
                ll V = (*p).second;
                if(L<l){
                    if(R>r){
                        mp[V] += (r-l+1);
                        break;
                    }else{
                        mp[V] += (R-l+1);
                    }
                }else{
                    if(R>r){
                        mp[V] += (r-L+1);
                        break;
                    }else{
                        mp[V] += (R-L+1);
                    }
                }
                p++;
            }
            if(op==3){
                int cc = 0;
                for(auto X:mp){
                    cc += X.second;
                    if(cc >=x){
                        cout << X.first << "\n";
                        break;
                    }
                }
            }else{
                int y = (rnd()%(vmax)) + 1;
                ll res = 0;
                for(auto X:mp){
                    // cerr << X.first << " " << X.second  << " " << x << endl;
                    res += (ll)X.second*(mod_pow(X.first,x,y))%y;
                    // cerr << res << endl;
                    res %= y;
                }
                cout << res << "\n";
            }
        }
        // cerr << "test" << endl;
        // for(auto x:st){
            // cerr << x.first.first << " " << x.first.second << " " << x.second << endl;
        //     rep(i,x.first.second-x.first.first + 1){
        //         cerr << x.second << " ";
        //     }
        // }
        // cerr << endl;
        // if(zz%10){
        //     rep(i,n){
        //         cerr << a[i] << " ";
        //     }
        //     cerr << endl;
        // }
    }
    // cerr << sm << endl;
    return 0;
}