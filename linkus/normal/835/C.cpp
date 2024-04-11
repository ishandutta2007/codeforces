#include <bits/stdc++.h> //Stack size ~2'000'000(x4)
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x != end(arr); ++x)
#define FORREV(x,plus,arr) for(auto x = rbegin(arr)+(plus); x != rend(arr); ++x)
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
inline int fstoi(const string &str){auto it=str.begin();bool neg=0;int num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getch(char &x){while(x = getchar_unlocked(), x < 33){;}}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}template<typename ...Args> inline void getstr(string &str, Args &...arg){str.clear();char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}getstr(arg...);}
template<typename T> inline bool sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){if(c == EOF) return false;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; return true;}template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,q,c;
    sc(n,q,c);
    /* vi arr[101][101]; */
    int rem = c+1;
    static int res[12][101][101];
    /* vector<pi> arr[101]; */
    int x,y,s;
    while(n--){
        sc(x,y,s);
        /* arr[y][x].pb(s); */
        int i = 0;
        while(i < rem){
            res[i++][y][x] += (s++)%rem;
            /* whatis(res[i-1][y][x]) */
        }
        /* arr[y].pb({x,s}); */
        /* int i = 0; */
        /* while(s <= c) */
        /*     arr[i++][x][y] = s++; */
        /* while(i <= c) */
        /*     arr[i++][x][y] = c; */
    }
    FORR(i,res){
        FORR(x,i){
            FOR(i,1,101){
                x[i] += x[i-1];
            }
        }
    }
    /* FORR(i,arr){ */
    /*     sort(all(i)); */
    /* } */
    int x1,x2,y1,y2,t;
    while(q--){
        sc(t,x1,y1,x2,y2);
        int sum = 0;
        /* int ox1 = x1; */
        /* t %= c; */
        /* t = min(t,c); */
        int actt = t%rem;
        while(y1 <= y2){
            /* cout << "sth1" << endl; */
            /* auto it = lower_bound(all(arr[y1]),x1,[](pi &el, auto &cmp){return el.e1 < cmp;}); */
            /* cout << "sth2" << endl; */
            if(x1)
                sum += res[actt][y1][x2]-res[actt][y1][x1-1];
            else
                sum += res[actt][y1][x2];
            /* whatis(sum) */
            /* while(it != arr[y1].end() && it->e1 <= x2){ */
            /*     sum += (it->e2+t)%rem; */
            /*     ++it; */
            /* } */
            /* while(x1 <= x2){ */
            /*     FORR(i,arr[y1][x1]) */
            /*         sum += (i+t)%rem; */
            /*     /1* if(arr[y1][x1]){ *1/ */
            /*         /1* whatis(arr[y1][x1]) *1/ */
            /*         /1* int add = (arr[y1][x1]+t-1)%rem; *1/ */
            /*         /1* sum += (arr[y1][x1]+t-1)%rem; *1/ */
            /*         /1* whatis((arr[y1][x1]+t-1)%rem) *1/ */
            /*         /1* sum += add; *1/ */
            /*     /1* } *1/ */
            /*     ++x1; */
            /* } */
            /* x1 = ox1; */
            ++y1;
        }
        cout << sum << '\n';
    }
}