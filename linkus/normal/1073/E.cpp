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
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

//Suma cyfr liczb od 0 do n
pair<ll,ll> dp[20][1024][2][2]; //{index, suma, czy bez limitu} -> ilosc spelniajacych warunki state-a
ll md = 998244353;
int k;
ll pot10[20];

ll qu(string n){
    for(auto &i: n){
        i -= '0';
    }
    memset(dp,0,sizeof dp);
    dp[0][0][0][0].e1 = 1;
    int len = n.size();
    //Gdyz tutaj liczby o mniejszej ilosci cyfr tak naprawde skladaja sie z
    //leading zeros przed nimi, jesli one wplywaja na statey, trzeba dolozyc
    //dodatkowy case - czy byla juz jakas zaczeta liczba, oraz dodatkowo
    //rozwazyc '0'
    /* whatis(len) */
    for(int i = 0; i < len; ++i){
        for(int t = 0; t < 2; ++t){ //t == 1 -> brak limitu
            for(int z = 0; z < 2; ++z){ //t == 1 -> brak limitu
                for(int s = 0; s < 1024; ++s){
                    for(int d = 0; d < 10; ++d){
                        if(!t && n[i] < d) break;
                        int nt = (t | (d < n[i]));
                        int nz = (z | (d != 0));
                        int ns = s;
                        if(nz)
                            ns |= (1 << d);
                        dp[i+1][ns][nt][nz].e1 += dp[i][s][t][z].e1;
                        dp[i+1][ns][nt][nz].e1 %= md;
                        /* dp[i+1][ns][nt][nz].e2 += dp[i][s][t][z].e2+dp[i][s][t][z].e1*d*pow(10,len-i-1); */
                        dp[i+1][ns][nt][nz].e2 += dp[i][s][t][z].e2+dp[i][s][t][z].e1*d*pot10[len-i-1];
                        dp[i+1][ns][nt][nz].e2 %= md;
                    }
                }
            }
        }
    }
    ll ans = 0;
    FOR(i,0,1024){
        if(__builtin_popcount(i) <= k){
            /* if(dp[len][i][1] || dp[len][i][0]){ */
            /*     whatis(i) */
            /*     whatis(dp[len][i][0]) */
            /*     whatis(dp[len][i][1]) */
            /* } */
            ans += dp[len][i][1][0].e2;
            ans += dp[len][i][0][0].e2;
            ans += dp[len][i][1][1].e2;
            ans += dp[len][i][0][1].e2;
            ans %= md;
        }
    }
    /* whatis(ans) */
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    pot10[0] = 1;
    FOR(i,1,20)
        pot10[i] = (pot10[i-1]*10)%md;
    int t = 1;
    string a,b;
    while(t--){
        cin >> a >> b >> k;
        ll res = qu(b);
        if(a.size() > 1 || a[0] > '1'){
            auto it = --a.end();
            while(it != a.begin() && *it == '0'){
                *it = '9';
                --it;
            }
            if(it == a.begin() && *it == '1')
                a.erase(a.begin());
            else
                --*it;
            /* whatis(a) */
            res -= qu(a);
        }
        while(res < 0)
            res += md;
        cout << res << '\n';
    }
}