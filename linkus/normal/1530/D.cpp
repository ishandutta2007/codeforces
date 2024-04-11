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

/* #define N 100001 */
#define N 400001

int vis[N];
int assign[N];
vector<int> adj[N];

/* int matchit; //so you dont have to clear vis */
/* //INCREMENT BEFORE EACH SALVE OF AUGS */
/* //2 Grupy musz by oddzielone w oznaczeniu, tzn. np zajmuja miejsca 0..n-1 n..n+m-1 */
/* //Jesli nie potrzeba takiego speeda, mona unikn warunku powuej jak wywalisz */
/* //podwjny assign (tylko zostawiasz dla 2 grupy) */
/* bool aug(int cur){ */
/*     if(vis[cur] == matchit) return 0; */
/*     vis[cur] = matchit; */
/*     FORR(i,adj[cur]){ */
/*         if(assign[i] == -1){ */
/*             assign[i] = cur; */
/*             assign[cur] = i; */
/*             return 1; */
/*         } */
/*     } */
/*     FORR(i,adj[cur]){ */
/*         if(aug(assign[i])){ */
/*             assign[i] = cur; */
/*             assign[cur] = i; */
/*             return 1; */
/*         } */
/*     } */
/*     return 0; */
/* } */

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t,n,tmp;
    sc(t);
    FORE(cas,1,t){
        /* whatis("top") */
        /* sc(n,m); */
        sc(n);
        FOR(i,0,n){
            adj[i].clear();
            /* FOR(x,0,m){ */
            /*     sc(tmp); */
            /*     if(tmp) */
            /*         adj[i].push_back(x+n); */
            /* } */
        }
        int a[n];
        GET(a);
        FOR(i,0,n){
            /* adj[i].pb(n + a[i] - 1); */
            --a[i];
            adj[i].pb(n + a[i]);
        }
        /* memset(assign,-1,(n+m) << 2); */
        memset(assign,-1,(2*n) << 2);
        int mf = 0;
        //pojedyczy aug:
        /* { */
        /*     ++matchit; */
        /*     int i = 5; */
        /*     mf += aug(i); */
        /* } */
        //TURBO MATCHING (SERIA)
        
        // hard overkill w sumie xd.
        set<int> asd;
        FOR(i,0,n){
            if(asd.insert(a[i]).e2){
                assign[i] = a[i] + n;
                ++mf;
            }
            else
                assign[i] = -1;
        }
        /* whatis("ts") */
        /* int bmf = -1; */
        /* while(mf > bmf){ */
        /*     ++matchit; */
        /*     bmf = mf; */
        /*     FOR(i,0,n){ */
        /*         if(vis[i] != matchit && !~assign[i] && aug(i)){ //WANE EBY NIE NATK SI TU NA V Z 2. GRUPY */
        /*             ++mf; */
        /*         } */
        /*     } */
        /* } */
        bool sth = 0;
        /* if(mf == n-1){ */
        if(mf == n-1){
            int ind = -1;
            bool assd[n];
            memset(assd,0,n);
            FOR(i,0,n){
                if(assign[i] == -1)
                    ind = i;
                else
                    assd[assign[i] - n] = 1;
            }
            assert(ind != -1);
            if(!assd[ind]){
                int whomine = -1;
                whatis(ind)
                whatis(a[ind] + n)
                FOR(i,0,n){
                    if(assign[i] == a[ind] + n)
                        whomine = i;
                }
                assert(whomine != -1);
                /* a[whomine] = ind; */
                /* a[ind] = whomine; */
                /* a[whomine] = ind + n; */
                /* a[ind] = whomine + n; */
                assign[whomine] = ind + n;
                assign[ind] = a[ind] + n;
                /* FOR(i,0,n){ */
                /*     if(i != ind) */
                /*         adj[i].pb(ind + n); */
                /* } */
                /* sth = 1; */
                /* memset(assign,-1,(2*n) << 2); */
                /* mf = 0; */
                /* int bmf = -1; */
                /* while(mf > bmf){ */
                /*     ++matchit; */
                /*     bmf = mf; */
                /*     FOR(i,0,n){ */
                /*         if(vis[i] != matchit && !~assign[i] && aug(i)){ //WANE EBY NIE NATK SI TU NA V Z 2. GRUPY */
                /*             ++mf; */
                /*         } */
                /*     } */
                /* } */
            }
            else{
                whatis("assd[ind]")
            }
            /* assert(mf == n); */
        }
        /* whatis("ts2") */
        bool wh[n];
        memset(wh,0,n);
        FOR(i,0,n){
            if(assign[i] != -1)
                wh[assign[i]-n] = 1;
        }
        vi fr;
        FOR(i,0,n){
            if(!wh[i]){
                fr.pb(i);
            }
        }
        set<int> st;
        FOR(i,0,n)
            if(assign[i] == -1)
                st.insert(i);
        set<int> st1, st2;
        FORR(i,fr){
            if(st.count(i))
                st1.insert(i);
            else
                st2.insert(i);
        }
        /* FORR(i,st) */
        /*     if(!st1.count(i)) */
        /*         st2.insert(i); */
        /* whatis(st1) */
        /* whatis(st2) */
        // XXX niezmatchowani != nie maj matcha.
        // fr -> niezmatchowani.
        /* int it = 0; */
        /* int it = fr.size()-1; */
        /* int it = 1; */
        if(sth == 1){
            whatis("sth == 1")
        }
        /* cout << mf << '\n'; */
        cout << mf - sth << '\n';
        /* whatis("ts4") */
        FOR(i,0,n){
            /* whatis(i) */
            if(assign[i] != -1){
                cout << assign[i] + 1 - n << ' ';
            }
            else{
                /* cout << -1 << ' '; */
                /* cout << fr[it++] + 1 << ' '; */
                // bruh xddd in the middle tutaj moze byc meet, 0 iq.
                /* cout << fr[it--] + 1 << ' '; */
                /* if(it == fr.size()) */
                /*     it = 0; */
                /* cout << fr[it++] + 1 << ' '; */
                
                // taktyk -> first try takich, co still te nie zabrali z tego
                // seta (i maj siebie w secie); later z reszty.
                int cr;
                /* if(fr.back() != i){ */
                /*     cr = fr.back(); */
                /*     fr.pop_back(); */
                /* } */
                /* else{ */
                /*     cr = fr[fr.size()-2]; */
                /*     fr.erase(fr.end()-2); */
                /* } */
                bool got = 0;
                if(st1.size()){
                    if(*st1.begin() != i){
                        cr = *st1.begin();
                        st1.erase(st1.begin());
                        got = 1;
                    }
                    /* else if(st2.size() == 2){ */
                    // ?????????????????????????
                    /* else if(st2.size() >= 2){ */
                    else if(st1.size() >= 2){
                        cr = *st1.rbegin();
                        st1.erase(--st1.end());
                        got = 1;
                    }
                }
                if(!got){
                    if(*st2.begin() != i){
                        cr = *st2.begin();
                        st2.erase(st2.begin());
                        got = 1;
                    }
                    /* else if(st2.size() == 2){ */
                    else if(st2.size() >= 2){
                        cr = *st2.rbegin();
                        st2.erase(--st2.end());
                        got = 1;
                    }
                }
                assert(got);
                cout << cr + 1 << ' ';
                /* whatis(cr + 1) */
                if(st1.count(i)){
                    st1.erase(i);
                    assert(st2.insert(i).e2);
                }
                /* if(it == fr.size()) */
                /*     it = 0; */
            }
        }
        cout << '\n';
        /* whatis("ts5") */
        /* cout << "Case " << cas << ": a maximum of " << mf << " nuts and bolts can be fitted together\n"; */
    }
}