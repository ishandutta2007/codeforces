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

string a,b;
int cnt[10];
stack<char> st;

int f(int i){
    if(i == (int)b.size()) return -2;
    if(cnt[b[i]-48]){
        --cnt[b[i]-48];
        st.push(b[i]);
        int r = f(i+1);
        /* whatis(i+1) */
        /* whatis(r) */
        if(r == -1){
            st.pop();
            ++cnt[b[i]-48];
            for(int x = b[i]-49; ~x; --x){
                if(cnt[x]){
                    --cnt[x];
                    st.push(x+48);
                    return -2;
                    /* goto g; */
                }
            }
            return -1;
        }
        else if(r == -2){
            return -2;
        }
    }
    for(int x = b[i]-48; ~x; --x){
        if(cnt[x]){
            --cnt[x];
            st.push(x+48);
            return -2;
            /* goto g; */
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> a >> b;
    if(b.size() > a.size()){
        sort(all(a));
        reverse(all(a));
        REE(a)
    }
    FORR(i,a){
        ++cnt[i-48];
    }
    f(0);
    stack<char> st2;
    while(st.size()){
        st2.push(st.top()), st.pop();
    }
    while(st2.size()){
        cout.put(st2.top()), st2.pop();

    }
    for(int x = 9; ~x; --x){
        while(cnt[x]){
            --cnt[x];
            cout.put(x+48);
        }
    }
    /* FOR(i,0,b.size()){ */
    /*     if(cnt[b[i]-48]){ */
    /*         --cnt[b[i]-48]; */
    /*         cout.put(b[i]); */
    /*         continue; */
    /*     } */
    /*     for(int x = b[i]-48; ~x; --x){ */
    /*         if(cnt[x]){ */
    /*             --cnt[x]; */
    /*             cout.put(x+48); */
    /*             /1* c = 1; *1/ */
    /*             goto g; */
    /*         } */
    /*     } */
    /* } */
    /* g: */
    /* for(int x = 9; ~x; --x){ */
    /*     while(cnt[x]){ */
    /*         --cnt[x]; */
    /*         cout.put(x+48); */
    /*     } */
    /* } */
}