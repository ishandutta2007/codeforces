#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = (arr).rbegin()+(plus); x !=(arr).rend(); ++x)
#define REE(s_) {cout<<s_<<'\n';exit(0);}
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 0x7F7F7F7F //2139062143 | 127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef int64_t ll;
#define umap unordered_map
#define uset unordered_set
using namespace std;

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

struct sth{
    int l,r;
    int val;
};
inline bool operator<(const sth &f, const sth &s){
    return f.l < s.l;
}
ostream& operator<<(ostream &os, const sth &V) { os<<"[";os<<V.l<<','<<V.r<<","<<V.val; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }

int ans;

class linkustree{
        public:
    set<sth> s;
    void init(int l, int r, int val){
        s = {{l,r,val}};
    }
    linkustree(int l, int r, int val){
        init(l,r,val);
    }
    void insert(int l, int r, int val){
        set<sth>::iterator it = prev(s.upper_bound({l,0,0}));
        /* whatis(*it) */
        if(it->r >= r){ //inside element
            if(it->val != val){
                //(r-l+1) elements exchange
                ans += (r-l+1)*(val?1:-1);
                int origl = it->l, origr = it->r, origval = it->val;
                ++it;
                s.erase(prev(it));
                if(origl <= l-1)
                    s.insert({origl,l-1,origval});
                s.insert({l,r,val});
                if(r+1 <= origr)
                    s.insert({r+1,origr,origval});
            }
            return;
        }
        if(it->val == val){
            int origl = it->l;
            ++it;
            s.erase(prev(it));
            s.insert({origl,r,val});
        }
        else{
            //(it->r-l+1) elements change
            ans += (it->r-l+1)*(val?1:-1);
            int origl = it->l, origval = it->val;
            ++it;
            s.erase(prev(it));
            if(origl <= l-1)
                s.insert({origl,l-1,origval});
            s.insert({l,r,val});
        }
        while(it != s.end() && it->l <= r){
            if(it->r > r){
                if(it->val == val){ //could not do anything just as well tbh but merging never hurts
                    int origr = it->r;
                    ++it;
                    s.erase(prev(it));
                    int actuall = prev(it)->l;
                    s.erase(prev(it));
                    s.insert({actuall,origr,val});
                }
                else{
                    int origr = it->r, origval = it->val;
                    //(r-it->l+1) elements change
                    ans += (r-it->l+1)*(val?1:-1);
                    ++it;
                    s.erase(prev(it));
                    if(r+1 <= origr)
                        s.insert({r+1,origr,origval});
                }
            }
            else{
                if(it->val != val){
                    //(it->r-it->l-1) elements change
                    ans += (it->r-it->l+1)*(val?1:-1);
                }
                ++it;
                s.erase(prev(it));
            }
        }
    }
};


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q;
    sc(n,q);
    linkustree t(1,n,1);
    int f,s,mod;
    ans = n;
    while(q--){
        /* whatis(t.s) */
        sc(f,s,mod);
        --mod;
        t.insert(f,s,mod);
        cout << ans << '\n';
    }
}