#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
/* #pragma GCC target("sse4") */
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

// digit dp
// ju jest para lucky digitw w dystansie <= k || jaka pozycja ostatniego lucky digitu
// dp[1000(len)][2(limit)][(done || dystans do lucky digitu) (1000)]

// KURDEEEEEE
// TLE JUST
// A byo tak piknie, dopiero na 17 tecie eh
// Radewoosh te mia TLE najpierw

// wtf this is so slow

// bitset idealnie by wszed XD

constexpr int mod = 1000000007;
/* int dp[1001][2][1002]; */
/* int dp[1001][1002][2]; */
/* ll dp[1001][1002][2]; */
/* int dp[1001][1002][2]; */
ll dp[1001][1002];
// ez O(1e9)
// shit, bardziej 2e10 :c
// 32s maxtest

// kolejnosc ptli/w tablicy wgl?

// do 3s zepchnite, ale WA :c
// overflow ez...
// still rip:c
// ale ll na dp duo czas pogarsza though

// eh :c

// MUCH SPRYTNIEJ;
// wyliczenie penego dp dla liczb postaci 9999...., czyli zawsze unlimited
// i wtedy dla kadego test casu, jest tylko liniowa ilo statw z t = 0 (limitem)
// a tak, to do res += z tego globalnego dla (dla d < n[i])
// i oglnie, tak samo prosto procesujesz, wyliczasz kolejne staty
// -> ez

// Radewoosh jako inaczej to zrobi, bo on ma z k niezalenym na kadym casie

// i guess let's try the dif state then...
/* ll dp2[1001][1002][2]; //[i][posoflucky][isgood] */
// pos == N -> no lucky

// compute global dp
// ja mam dystans zamiast pozycj lucky cyfry (jak w editorialu)
// ale to powinno na to samo wychodzi surely? (bo bijekcja)
// a moze powinienem t oddzieln flag trzyma?
void pre(int k){
    // jaki init?
    dp[0][k+1] = 1;
    for(int i = 0; i < 1000; ++i){
        for(int dist = 0; dist <= k + 1; ++dist){
            // not lucky:
            int ndist1 = dist ? min(dist + 1, k + 1) : 0;
            dp[i+1][ndist1] += 8 * dp[i][dist];
            dp[i+1][ndist1] %= mod;
            // lucky:
            /* int ndist2 = dist != k + 1 ? 0 : 1; */
            int ndist2 = dist <= k ? 0 : 1;
            dp[i+1][ndist2] += 2 * dp[i][dist];
            dp[i+1][ndist2] %= mod;
        }
    }
}

// it works dayum
// ma to sens, bo jakby zliczamy, ile jest drg do dobrego statea, jakim jest
// -> updated digitdp template <3
// dp[0][0] (dist == 0, -> jest lucky pair)
void initother(int k){
    dp[0][0] = 1;
	for (int len = 1; len <= 1000; ++len) {
		for (int lastLucky = 0; lastLucky <= k + 1; ++lastLucky) {
            // let's speed it up for the flex

			/* for (int dig = 0; dig <= 9; ++dig) { */
			/* 	int nextLucky = lastLucky; */
			/* 	if (nextLucky != 0) { */
			/* 		if (dig == 4 || dig == 7) { */
			/* 			if (lastLucky <= k) */
			/* 				nextLucky = 0; */
			/* 			else */
			/* 				nextLucky = 1; */
			/* 		} else { */
			/* 			nextLucky = min(nextLucky + 1, k + 1); */
			/* 		} */
			/* 	} */
			/* 	dp[len][lastLucky] += dp[len - 1][nextLucky]; */
                /* if(dp[len][lastLucky] >= mod) */
                    /* dp[len][lastLucky] -= mod; */
			/* } */
            dp[len][lastLucky] += 8ll * dp[len-1][lastLucky ? min(lastLucky + 1, k + 1) : 0] % mod;
            if(dp[len][lastLucky] >= mod)
                dp[len][lastLucky] -= mod;
            dp[len][lastLucky] += 2ll * dp[len-1][lastLucky <= k ? 0 : 1] % mod;
            if(dp[len][lastLucky] >= mod)
                dp[len][lastLucky] -= mod;
		}
	}
}

int qu(string n, int k){
    int res = 0;
    /* int res2 = 0; */
    for(auto &i: n){
        i -= '0';
    }
    int len = n.size();
    // who needs recursion
    int i = 0, dist = k + 1;
    /* int last = N, g = 0; */
    // nie czaj, imo mam to samo co merit
    // -> rewrite -> ten sam wynik hmm xd
    // wait, ten sam, e ten sam co miaem, czyli wa still okkay..?
    // wait, moe dlatego,e on to liczy z defaulta exclusive??
    // -> 77 pominite w drugim samplu
    static constexpr int luck0[] = {0,0,0,0,0,1,1,1,2,2};
    static constexpr int luck1[] = {0,0,0,0,1,0,0,1,0,0};
    for(int i = 1; i <= len; ++i){
        // >let's speed it up for the flex
        /* for(int d = 0; d < n[i-1]; ++d){ */
        /*     int nxdist = dist; */
        /*     if(nxdist != 0){ */
        /*         if(d == 4 || d == 7){ */
        /*             nxdist = dist <= k ? 0 : 1; */
        /*         } */
        /*         else{ */
        /*             nxdist = min(nxdist + 1, k + 1); */
        /*         } */
        /*     } */
        /*     /1* assert(ndist == nxdist); *1/ */
        /*     res += dp[len - i][nxdist]; */
        /*     if(res >= mod) */
        /*         res -= mod; */
        /* } */
        res += 1ll * luck0[n[i-1]] * dp[len - i][dist <= k ? 0 : 1] % mod;
        if(res >= mod)
            res -= mod;
        res += 1ll * (n[i-1] - luck0[n[i-1]]) * dp[len - i][dist ? min(dist + 1, k + 1) : 0] % mod;
        if(res >= mod)
            res -= mod;
        // dif with mine
        // -> no assert failures
        if(dist != 0){
            if(n[i-1] == 4 || n[i-1] == 7){
                dist = dist <= k ? 0 : 1;
            }
            else{
                dist = min(dist + 1, k + 1);
            }
        }
        /* assert(dist == ndist); */
    }
    // dodaj 1 jak git, bo bez tego exclusive jest
    if(dist == 0){
        if(++res == mod)
            res = 0;
    }
    /* while(i < len){ */
    /*     whatis(i) */
    /*     for(int d = 0; d < n[i]; ++d){ */
    /*         int ndist = dist ? min(dist + 1, k + 1) : 0; */
    /*         if(d == 4 || d == 7){ */
    /*             ndist = dist <= k ? 0 : 1; */
    /*         } */
    /*         // mam tylko zlicza dobre resy przecie */
    /*         // ale jak hmm */
    /*         /1* whatis(ndist) *1/ */
    /*         /1* if(!ndist) *1/ */
    /*         res += dp[len - i - 1][ndist]; */
    /*         /1* res += dp[len - i - 2][ndist]; *1/ */
    /*         /1* res += dp[len - i + 1][ndist]; *1/ // baad */
    /*         if(res >= mod) */
    /*             res -= mod; */
    /*     } */
    /*     int ndist = dist ? min(dist + 1, k + 1) : 0; */
    /*     if(n[i] == 4 || n[i] == 7){ */
    /*         ndist = dist <= k ? 0 : 1; */
    /*     } */
    /*     dist = ndist; */
    /*     /1* for(int d = 0; d < n[i]; ++d){ *1/ */
    /*     /1*     int ng = g; *1/ */
    /*     /1*     int nlast = last; *1/ */
    /*     /1*     if(d == 4 || d == 7){ *1/ */
    /*     /1*         if(last != N) *1/ */
    /*     /1*             ng = 1; *1/ */
    /*     /1*         nlast = i; *1/ */
    /*     /1*     } *1/ */
    /*     /1*     // mam tylko zlicza dobre resy przecie *1/ */
    /*     /1*     // ale jak hmm *1/ */
    /*     /1*     /2* whatis(ndist) *2/ *1/ */
    /*     /1*     /2* if(!ndist) *2/ *1/ */
    /*     /1*     res2 += dp2[len - i - 1][nlast][ng]; *1/ */
    /*     /1*     if(res2 >= mod) *1/ */
    /*     /1*         res2 -= mod; *1/ */
    /*     /1* } *1/ */
    /*     /1* int ng = g; *1/ */
    /*     /1* int nlast = last; *1/ */
    /*     /1* if(n[i] == 4 || n[i] == 7){ *1/ */
    /*     /1*     if(last != N) *1/ */
    /*     /1*         ng = 1; *1/ */
    /*     /1*     nlast = i; *1/ */
    /*     /1* } *1/ */
    /*     ++i; */
    /* } */
    return res;
    /* return res2; */
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,k;
    sc(t,k);
    /* pre(k); */
    initother(k);
    while(t--){
        whatis(t)
        string a,b;
        getstr(a);
        getstr(b);
        int res = qu(b,k);
        if(a.size() > 1 || a[0] != '0'){
            if(a == "1"){
                a = "0";
            }
            else{
                auto it = --a.end();
                while(it != a.begin() && *it == '0'){
                    *it = '9';
                    --it;
                }
                if(it == a.begin() && *it == '1')
                    a.erase(a.begin());
                else
                    --*it;
            }
            res -= qu(a,k); //IF MODUOLING, DON'T FORGET TO CORRECT IN CASE RES GOES NEGATIVE
            if(res < 0)
                res += mod;
        }
        cout << res << '\n';
    }
}