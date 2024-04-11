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
#define REE(s_) {cout<<s_<<'\n';exit(0);} //print s_ and terminate program
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
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
template<typename T> inline T mod(T i, T n) { return (i % n + n) % n; }

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,p,q,r;
    sc(n,p,q,r);
    ll cur;
    ll INF = -(1ll << 62);
    ll bp,bpq,best;
    bp = bpq = best = INF;
    while(n--){
        sc(cur);
        bp = max(bp,p*cur);
        bpq = max(bpq,bp+q*cur);
        best = max(best,bpq+r*cur);
    }
    cout << best << '\n';
    /* ll arr[n]; */
    /* GET(arr); */
    /* if(p >= 0 && q >= 0 && r >= 0){ */
    /*     int num = *max_element(arr,arr+n); */
    /*     REE(num*p+num*q+num*r); */
    /* } */
    /* if(p < 0 && q < 0 && r < 0){ */
    /*     int num = *min_element(arr,arr+n); */
    /*     REE(num*p+num*q+num*r); */
    /* } */
    /* if(p < 0 && q >= 0 && r >= 0){ */
    /*     ll best = -LL_INF; int curid;// pi bestid; */
    /*     curid = 0; */
    /*     FOR(i,0,n){ */
    /*         if(arr[i] < arr[curid]){ */
    /*             curid = i; */
    /*         } */
    /*         best = max(best,arr[curid]*p+arr[i]*q+arr[i]*r); */
    /*     } */
    /*     REE(best); */
    /* } */
    /* if(p < 0 && q < 0 && r >= 0){ */
    /*     ll best = -LL_INF; int curid;// pi bestid; */
    /*     curid = 0; */
    /*     FOR(i,0,n){ */
    /*         if(arr[i] < arr[curid]){ */
    /*             curid = i; */
    /*         } */
    /*         best = max(best,arr[curid]*p+arr[curid]*q+arr[i]*r); */
    /*     } */
    /*     REE(best); */
    /* } */
    /* if(p >= 0 && q >= 0 && r < 0){ */
    /*     ll best = -LL_INF; int curid;// pi bestid; */
    /*     curid = 0; */
    /*     FOR(i,0,n){ */
    /*         if(arr[i] > arr[curid]){ */
    /*             curid = i; */
    /*         } */
    /*         best = max(best,arr[curid]*p+arr[curid]*q+arr[i]*r); */
    /*     } */
    /*     REE(best); */
    /* } */
    /* if(p >= 0 && q < 0 && r < 0){ */
    /*     ll best = -LL_INF; int curid;// pi bestid; */
    /*     curid = 0; */
    /*     FOR(i,0,n){ */
    /*         if(arr[i] > arr[curid]){ */
    /*             curid = i; */
    /*         } */
    /*         best = max(best,arr[curid]*p+arr[i]*q+arr[i]*r); */
    /*     } */
    /*     REE(best); */
    /* } */
    /* if(p < 0 && q >= 0 && r < 0){ */
    /*     ll best = -LL_INF; int cur1,cur2;// pi bestid; */
    /*     cur1 = cur2 = 0; */
    /*     ll qucur1 = -1; */
    /*     FOR(i,0,n){ */
    /*         if(arr[i] > arr[cur2]){ */
    /*             cur2 = i; */
    /*             if(~qucur1){ */
    /*                 cur1 = qucur1; */
    /*                 qucur1 = -1; */
    /*             } */
    /*         } */
    /*         best = max(best,arr[cur1]*p+arr[cur2]*q+arr[i]*r); */
    /*         if(~qucur1){ */
    /*             ll newb = arr[i]*p+arr[i]*q+arr[i]*r; */
    /*             if(newb > best){ */
    /*                 cur2 = i; */
    /*                 cur1 = qucur1; */
    /*                 qucur1 = -1; */
    /*             } */
    /*         } */
    /*         best = max(best,arr[cur1]*p+arr[cur2]*q+arr[i]*r); */
    /*         if(arr[i] < arr[cur1]){ */
    /*             if(cur2 == i) */
    /*                 cur1 = i; */
    /*             else{ */
    /*                 ll newb = arr[i]*p+arr[i]*q+arr[i]*r; */
    /*                 if(newb > best){ */
    /*                     cur2 = cur1 = i; */
    /*                 } */
    /*                 else{ */
    /*                     qucur1 = i; */
    /*                 } */
    /*             } */
    /*         } */
    /*         whatis(i) */
    /*         whatis(cur1) */
    /*         whatis(cur2) */
    /*         best = max(best,arr[cur1]*p+arr[cur2]*q+arr[i]*r); */
    /*     } */
    /*     REE(best); */
    /* } */
    /* if(p >= 0 && q < 0 && r >= 0){ */
    /*     ll best = -LL_INF; int cur1,cur2;// pi bestid; */
    /*     cur1 = cur2 = 0; */
    /*     ll qucur1 = 01; */
    /*     FOR(i,0,n){ */
    /*         if(arr[i] < arr[cur2]){ */
    /*             cur2 = i; */
    /*             if(~qucur1){ */
    /*                 cur1 = qucur1; */
    /*                 qucur1 = -1; */
    /*             } */
    /*         } */
    /*         best = max(best,arr[cur1]*p+arr[cur2]*q+arr[i]*r); */
    /*         if(~qucur1){ */
    /*             ll newb = arr[i]*p+arr[i]*q+arr[i]*r; */
    /*             if(newb > best){ */
    /*                 cur2 = i; */
    /*                 cur1 = qucur1; */
    /*                 qucur1 = -1; */
    /*             } */
    /*         } */
    /*         best = max(best,arr[cur1]*p+arr[cur2]*q+arr[i]*r); */
    /*         if(arr[i] > arr[cur1]){ */
    /*             cur1 = i; */
    /*             if(cur2 == i) */
    /*                 cur1 = i; */
    /*             else{ */
    /*                 ll newb = arr[i]*p+arr[i]*q+arr[i]*r; */
    /*                 if(newb > best){ */
    /*                     cur2 = cur1 = i; */
    /*                 } */
    /*                 else{ */
    /*                     qucur1 = i; */
    /*                 } */
    /*             } */
    /*         } */
    /*         best = max(best,arr[cur1]*p+arr[cur2]*q+arr[i]*r); */
    /*     } */
    /*     REE(best); */
    /* } */
}