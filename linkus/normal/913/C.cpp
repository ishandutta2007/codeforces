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
template<typename T> inline T mod(T i, T n) { return (i % n + n) % n; }

/* ll ans = 0; */
/* ll rem; */
ll n,l;
pair<ll,ll> arr[30]; //{cost,amount};

ll func(int i, ll currem){
    ll am = currem/arr[i].e2;
    ll myrem = am*arr[i].e1;
    ll el = am*arr[i].e2;
    ll newrem = currem-el;
    ll myonlyrem = myrem;
    if(newrem){
        myonlyrem += arr[i].e1;
        int nxt = i+1;
        if(nxt == n)
            return myonlyrem;
        while(arr[nxt].e1 == -1){
            if(++nxt == n)
                return myonlyrem;
        }
        ll prop = func(nxt,newrem);
        return min(myonlyrem,myrem+prop);
    }
    else{
        return myrem;
    }
}

/* for(auto i = arr; i < arr+n; ++i){ */
/*     if(i->e1 == -1) continue; */
/*     if(rem >= i->e2){ */
/*         ll am = (rem/i->e2); */
/*     whatis(rem) */
/*     whatis(am) */
/*         if(bs.empty()){ */
/*             ans += am*i->e1; */
/*             rem -= am*i->e2; */
/*         } */
/*     } */
/* } */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    sc(n,l);
    FOR(i,0,n){
        sc(arr[i].e1);
        arr[i].e2 = 1 << i;
    }
    sort(arr,arr+n,[](auto f, auto s){return f.e2/(double)f.e1 > s.e2/(double)s.e1;});
    /* FORR(i,arr) */
    /*     cout << i << ' '; */
    /* cout << '\n'; */
    /* exit(0); */
    FOR(i,0,n){
        FOR(x,0,i){
            if(arr[x].e1 == -1) continue;
            if(arr[x].e2 >= arr[i].e2 && arr[x].e1 < arr[i].e1){
                whatis(i)
                arr[i].e1 = -1;
                break;
            }
        }
        FOR(x,i+1,n){
            if(arr[x].e1 == -1) continue;
            if(arr[x].e2 >= arr[i].e2 && arr[x].e1 < arr[i].e1){
                whatis(i)
                arr[i].e1 = -1;
                break;
            }
        }
    }
    /* vector<ll> bs; */
    /* for(auto i = arr; i < arr+n; ++i){ */
    /*     if(i->e1 == -1) continue; */
    /*     if(rem >= i->e2){ */
    /*         ll am = (rem/i->e2); */
    /*     whatis(rem) */
    /*     whatis(am) */
    /*         if(bs.empty()){ */
    /*             ans += am*i->e1; */
    /*             rem -= am*i->e2; */
    /*         } */
    /*     } */
    /* } */
    /* if(rem){ */
    /*     ll mn = 0x7f7f7f7f; */
    /*     FORR(i,arr){ */
    /*         if(i.e1 == -1) continue; */
    /*         mn = min(mn,(ll)i.e1); */
    /*     } */
    /*     ans += mn; */
    /*     rem = 0; */
    /* } */
    cout << func(0,l) << '\n';
}