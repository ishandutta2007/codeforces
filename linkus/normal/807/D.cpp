#include <bits/stdc++.h> //Stack size ~2'000'000(x4)
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define PRINT(arr) {copy(begin((arr)), end((arr)), ostream_iterator<int>(cout, " "));cout<<'\n';}
#define REE(s_) {cout<<s_<<'\n';exit(0);} //print s_ and terminate program
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 2139062143 //127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
#define umap unordered_map
#define uset unordered_set
using namespace std;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }//prnt vec
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }//prnt pair
template<typename T> inline void print_128(T num){ if(!num) return; print_128(num / 10); cout.put((num % 10) + '0'); }
template<typename T> inline T fstoi(const string &str){auto it=str.begin();bool neg=0;T num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}template<typename ...Args> inline void getstr(string &str, Args &...arg){str.clear();char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}getstr(arg...);}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

int n;
int arr[2][5];
int subm[5];

inline bool ok(int cur){
    ll svas = 0, spet = 0;
    long double cont = n+cur;
    int val;
    long double per;
    for(int i = 0; i < 5; ++i){
        if(arr[0][i] != -1 && (arr[0][i] > arr[1][i] && arr[1][i] != -1)){
            per = (subm[i] + cur) / cont;
            if(per > 0.5)
                val = 500;
            else if(per > 0.25)
                val = 1000;
            else if(per > 0.125)
                val = 1500;
            else if(per > 0.0625)
                val = 2000;
            else if(per > 0.03125)
                val = 2500;
            else
                val = 3000;
            if(arr[0][i] != -1){
                svas += val*(1-arr[0][i]/250.0);
            }
            if(arr[1][i] != -1){
                spet += val*(1-arr[1][i]/250.0);
            }
        }
        else{
            per = subm[i] / cont;
            if(per > 0.5)
                val = 500;
            else if(per > 0.25)
                val = 1000;
            else if(per > 0.125)
                val = 1500;
            else if(per > 0.0625)
                val = 2000;
            else if(per > 0.03125)
                val = 2500;
            else
                val = 3000;
            if(arr[0][i] != -1){
                svas += val*(1-arr[0][i]/250.0);
            }
            if(arr[1][i] != -1){
                spet += val*(1-arr[1][i]/250.0);
            }
        }
        /* whatis(val) */
    }
    /* cout << svas << ' '<< spet << '\n'; */
    return svas > spet ? 1 : 0;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n);
    FOR(i,0,2){
        sc(arr[i][0],arr[i][1],arr[i][2],arr[i][3],arr[i][4]);
        FOR(e,0,5){
            if(arr[i][e] != -1)
                ++subm[e];
        }
    }
    int t;
    for(int q = n-2; q; --q){
        for(int i = 0 ;i < 5; ++i){
            sc(t);
            if(t != -1)
                ++subm[i];
        }
    }
    /* int dest = 1e9 + 7; */
    /* if(!ok(dest+1)) */
    /*     REE(-1) */
    FORE(i,0,1e7){
        if(ok(i))
            REE(i);
    }
    cout << "-1\n";
    /* ll low = 0; */
    /* ll high = 1100000000; */
    /* ll mid; */
    /* ll ans = INF; */
    /* int cnt = 50; */
    /* while(low != high && cnt--){ */
    /*     mid = (low+high)/2; */
    /*     if(ok(mid)){ */
    /*         ans = mid; */
    /*         high = mid; */
    /*     } */
    /*     else */
    /*         low = mid; */
    /* } */
    /* ans <= (1e9+7) ? cout << ans << '\n' : cout << "-1\n"; */
}