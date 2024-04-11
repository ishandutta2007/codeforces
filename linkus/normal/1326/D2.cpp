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
#define whatis(x) cerr << #x << " is " << (x) << endl;
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

#ifdef ONLINE_JUDGE
#define whatis(x) ;
#endif
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class L, class R> ostream& operator<<(ostream &os, map<L, R> P) { for(auto const &vv: P)os<<"("<<vv.first<<","<<vv.second<<")"; return os; }
template<class T> ostream& operator<<(ostream &os, set<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define N 1000001

//can also solve with hashes in nlogn

//half-length of maximum odd palindrome with center in i, to get even,
//separators are added
vector<int> pal_array(string ss){
    string s = ".";
    FOR(i,0,ss.size()){
        s += ss[i];
        s += '.';
    }
    int n = s.size();
    whatis(s)
    vector<int> len(n);
    for (int i = 0, l = 0, r = -1; i < n; i++) {
        int k = (i > r) ? 1 : min(len[l + r - i], r - i);
        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
            k++;
        }
        len[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }
        // subpalindome count
    /* int ret = 0; */
    /* FOR(i,0,n){ */
    /*     ret += len[i]/2; */
    /* } */
    /* whatis(ret) */
        // dodaj wyliczanie original left-most indexow i dugoci max
        // palindromu od rodka
    return len;
}

int main(){
    // do i need dots on boundaries wsm?
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    sc(t);
    while(t--){
        /* string s = "aab"; */
        string s;
        getstr(s);
        if(s == string(s.rbegin(),s.rend())){
            cout << s << '\n';
            continue;
        }
        int n = s.size();
        /* int res = 0; */
        string res;
        int reslen = 0;
        FOR(_,0,2){
            vi d1 = pal_array(s);
            /* FOR(i,0,2*n+1) */
            /*     cout << d1[i] << ' '; */
            /* cout << '\n'; */
            int mxpal[n]; // max pal len std na prawo
            memset(mxpal, 0, n << 2);
            /* FOR(i,0,2*n+1){ */
            vector<int> vec[n];
            // nice, passes))
            FOR(i,0,2*n){
                /* int ind = i / 2 - d1[i] / 2 + 1; */
                int ind = i / 2 - (d1[i] + 1) / 2 + 1;
                assert(ind >= 0);
                /* mxpal[ind] = max(mxpal[ind], d1[i] - 1); */
                vec[ind].push_back(d1[i] - 1);
            }
            // O(n^2)
            // still wa hmmm
            // bcs of intersections. the code just below is good.
            /* for(int c = 0; c < n; ++c){ */
            /*     int l = c, r = c + 1; */
            /*     /1* if(l >= 0 && r < n && s[l] == s[r]){ *1/ */
            /*     while(l >= 0 && r < n && s[l] == s[r]){ */
            /*         vec[l].push_back(r - l + 1); */
            /*         mxpal[l] = max(mxpal[l], r - l + 1); */
            /*         /1* while(l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]) *1/ */
            /*         --l, ++r; */
            /*         /1* mxpal[l] = max(mxpal[l], r - l + 1); *1/ */
            /*     } */
            /*     l = c, r = c; */
            /*     // while not if */
            /*     /1* if(l >= 0 && r < n && s[l] == s[r]){ *1/ */
            /*     while(l >= 0 && r < n && s[l] == s[r]){ */
            /*         vec[l].push_back(r - l + 1); */
            /*         mxpal[l] = max(mxpal[l], r - l + 1); */
            /*         /1* while(l-1 >= 0 && r+1 < n && s[l-1] == s[r+1]) *1/ */
            /*         --l, ++r; */
            /*     } */
            /*     /1* mxpal[l] = max(mxpal[l], r - l + 1); *1/ */
            /* } */
            /* FOR(i,1,n) */
            /*     mxpal[i] = max(mxpal[i], mxpal[i-1] - 2); */
            /* string res; */
            /* int l = 0, r = s.size() - 1; */
            /* pair<l,r> posres; */
            int l = -1, r = s.size();
            // z reva -> musze zrewowac na koncu
            // xd jak to palindrom jest ziom, nie trzeba revowac palindroma
            /* sort(all(vec)); */
            set<int> st;
            int coeff = -2;
            pair<int,int> respos;
            bool chgres = 0;
            do{
                ++l,--r;
                coeff += 2;
                while(st.size() && *st.begin() <= coeff)
                    st.erase(st.begin());
                FORR(i,vec[l])
                    st.insert(i + coeff);
                // good -> update max mid palindrome
                int cres = 2 * l;
                int mx = n - cres;
                auto it = st.upper_bound(mx + coeff);
                int whmid = 0;
                if(it != st.begin()){
                    --it;
                    whmid = max(0,*it - coeff);
                    cres += whmid;
                }
                /* cres += mxpal[l]; */
                /* res = max(res, cres); */
                /* if(cres > res.size()){ */
                if(cres > reslen){
                    // moze nachodziz wewntrzny palindrom na suffix -> that was the bug
                    /* res = string(s.begin(),s.begin()+l+mxpal[l]) + string(s.begin()+r+1,s.end()); */
                    /* res = string(s.begin(),s.begin()+min(l+mxpal[l],r+1)) + string(s.begin()+r+1,s.end()); */
                    // but the fix is not as simple as that... can't take max anymore on mxpal
                    // set z coeffem :? (-2 all co ture -> largest not
                    // intersecting suffix -> lower_bound ?)

                    /* res = string(s.begin(),s.begin()+l+whmid) + string(s.begin()+r+1,s.end()); */
                    // NICE, that set z coeffem passed D1 ez

                    // ez only change for D2 ac
                    reslen = cres;
                    respos = {l+whmid,r+1};
                    chgres = 1;
                }
                /* whatis(l) */
                /* whatis(mxpal[l]) */
            }while(s[l] == s[r]);
            if(chgres){
                res = string(s.begin(),s.begin()+respos.e1) + string(s.begin()+respos.e2,s.end());
                // ez only change for D2 ac
            }
            reverse(all(s));
        }
        // damnn
        /* assert(res.size() < n); */
        cout << res << '\n';
    }
}