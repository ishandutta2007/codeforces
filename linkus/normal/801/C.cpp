#include <bits/stdc++.h> //Stack size ~2'000'000(x4)
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) (begin((a)),end((a)))
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORRC(x,arr) for(auto const &x: arr)
#define PRINT(arr) {copy(begin((arr)), end((arr)), ostream_iterator<int>(cout, " "));cout<<'\n';}
#define REE(s_) {cout<<s_<<'\n';return 0;} //print s_ and terminate program
#define GET(arr) for(auto &i: (arr)) cin>>i
#define GETSC(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 2139062143 //127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
typedef std::pair<int,int> pi; typedef std::vector<int> vi; typedef std::vector<std::string> vs;
using namespace std;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }//prnt vec
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }//prnt pair
template<typename T> inline T fstoi(const string &str){auto it=str.begin();bool neg=0;T num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getstr(string &str){char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}template<typename ...Args> inline void getstr(string &str, Args &...arg){char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}getstr(arg...);}
template<typename T> inline void sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; }template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

vector<long double> power;
vector<long double> prad;
int n,p;

bool ok(long double cur){
    long double pnow = p*cur;
    FOR(i,0,n){
        if(prad[i] < power[i]*cur){
            pnow -= power[i]*cur - prad[i];
            if(pnow < 0)
                return 0;
        }
    }
    return 1;
}

/* int ok(long double cur){ */
/*     long double pnow = p*cur; */
/*     FOR(i,0,n){ */
/*         if(prad[i] < power[i]*cur){ */
/*             pnow -= power[i]*cur - prad[i]; */
/*             if(pnow < 0) */
/*                 return 0; */
/*         } */
/*     } */
/*     if(pnow < 0.0001 && pnow > -0.0001) */
/*         return -1; */
/*     return 1; */
/* } */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(12);
    sc(n,p);
    power.resize(n);
    prad.resize(n);
    FOR(i,0,n){
        sc(power[i],prad[i]);
    }
    ll allpower = accumulate(power.begin(),power.end(),0LL);
    //ll allprad = accumulate(prad.begin(),prad.end(),0);
    long double ans;
    long double low = 0.0;
    long double high = 10010510063.0;
    long double mid;
    whatis(low) whatis(high)
    if(allpower <= p)
        REE("-1");
    while(fabs(high - low) > 0.00001){
        whatis(high)
        whatis(low)
        mid = (low+high)/2.0;
        if(ok(mid)){
            ans = mid;
            low = mid;
        }
        else
            high = mid;
    }
    /* for(long double x = 0.00001;; x*=2){ */
    /*     /1* cout << x << '\n'; *1/ */
    /*     while(1){ */
    /*         int ret = ok(ans - x); */
    /*         if(ret == -1){ */
    /*             ans -= x; */
    /*             goto done; */
    /*         } */
    /*         if(ret == 1) */
    /*             break; */
    /*         ans -= x; */
    /*     } */
    /* } */
    /* done: */
    cout << ans;
}