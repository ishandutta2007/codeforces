#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GET(arr) for(auto &i: (arr)) sc(i)
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
#define INF 0x7f7f7f7f
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
typedef uint64_t ull;
#define umap unordered_map
#define uset unordered_set
using namespace std;
using namespace __gnu_pbds;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define M 300000
ll t[M<<1];

void modify(int pos, int val){
    t[pos] = val;
    for(int i = pos >> 1; i; i >>= 1){
        t[i] = t[i<<1] + t[i<<1|1];
    }
}

ll query(int l, int r){
    ll sum = 0;
    while(l < r){
        if(l&1){
            sum += t[l++];
        }
        if(r&1){
            sum += t[--r];
        }
        l >>= 1, r >>= 1;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    static int D[1000001];
    set<int> st;
    FOR(i,1,1000001){
        for(int x = i; x <= 1000000; x += i){
            ++D[x];
        }
    }
    /* FOR(i,0,10) */
    /*     cout << i << ": " << D[i] << ' '; */
    /* cout << '\n'; */
    int n,m,typ,f,s;
    sc(n,m);
    int arr[n];
    FOR(i,0,n){
        sc(arr[i]);
        if(arr[i] > 2)
            st.insert(i);
        t[i+n] = arr[i];
    }
    for(int i = n-1; i; --i)
        t[i] = t[i<<1] + t[i<<1|1];
    while(m--){
        sc(typ,f,s);
        --f;
        if(typ == 1){
            auto it = st.lower_bound(f);
            while(it != st.end() && *it < s){
                arr[*it] = D[arr[*it]];
                modify(*it+n,arr[*it]);
                if(arr[*it] <= 2){
                    ++it;
                    st.erase(prev(it));
                }
                else{
                    ++it;
                }
            }
            /* FOR(i,0,n){ */
            /*     cerr << arr[i] << ' '; */
            /* } */
            /* cerr << '\n'; */
        }
        else{
            cout << query(f+n,s+n) << '\n';
        }
    }
}