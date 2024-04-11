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
using namespace __gnu_pbds;

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
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; //s.find_by_order(), s.order_of_key() <- works like lower_bound
template<typename T> using ordered_map = tree<T, int, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void finish(string &s){
    size_t ind = s.find_first_not_of('\0');
    if(ind == s.npos)
        cout << "0\n";
    else
        for(size_t i = ind; i < s.size(); ++i)
            cout.put(s[i]+48);
    exit(0);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    getstr(s);
    int sum = 0;
    FORR(i,s) sum += (i -= 48);
    int des = sum%3; //desired minus%3
    vi r1,r2;
    if(!des)
        finish(s);
    if(s.size() == 1) REE(-1)
    if(des == 1){ //{1} or {2,2}
        int c1 = INF,c2 = INF;
        int i;
        for(i = s.size(); ~--i;){
            if(s[i]%3 == 1){
                break;
            }
        }
        whatis(i)
        if(~i){
            r1 = {i};
            if(i == 0){ //could produce lead 0s
                for(c1 = 1; c1 < (int)s.size(); ++c1)
                    if(s[c1]) break;
            }
            else{
                c1 = 1;
            }
        }
        //{2,2}
        if(s.size() > 2){
            int fir = -1,sec = -1;
            for(fir = s.size();~--fir;){
                if(s[fir]%3 == 2) break;
            }
            for(sec = fir; ~--sec;){
                if(s[sec]%3 == 2) break;
            }
            if(fir >= 0 && sec >= 0){
                r2 = {fir,sec};
                if(fir == 0){
                    for(c2 = 1; c2 < (int)s.size(); ++c2)
                        if(s[c2]) break;
                    if(c2 == sec){
                        for(; c2 < (int)s.size(); ++c2){
                            if(s[c2]) break;
                        }
                    }
                }
                else if(sec == 0){
                    for(c2 = 1; c2 < (int)s.size(); ++c2)
                        if(s[c2]) break;
                    if(c2 == fir){
                        for(; c2 < (int)s.size(); ++c2){
                            if(s[c2]) break;
                        }
                    }
                }
                else{
                    c2 = 2;
                }
            }
        }
        whatis(c1)
        whatis(c2)
        if(min(c1,c2) == 0x7f7f7f7f) REE(-1);
        if(c1 < c2){
            s.erase(s.begin()+r1[0]);
            finish(s);
        }
        else{
            sort(all(r2));
            s.erase(s.begin()+r2[1]);
            s.erase(s.begin()+r2[0]);
            finish(s);
        }
    }
    else{ //{2} or {1,1}
        int c1 = INF,c2 = INF;
        int i;
        for(i = s.size(); ~--i;){
            if(s[i]%3 == 2){
                break;
            }
        }
        if(~i){
            r1 = {i};
            if(i == 0){ //could produce lead 0s
                for(c1 = 1; c1 < (int)s.size(); ++c1)
                    if(s[c1]) break;
            }
            else{
                c1 = 1;
            }
        }
        //{1,1}
        if(s.size() > 2){
            int fir = -1,sec = -1;
            for(fir = s.size();~--fir;){
                if(s[fir]%3 == 1) break;
            }
            for(sec = fir; ~--sec;){
                if(s[sec]%3 == 1) break;
            }
            if(fir >= 0 && sec >= 0){
                r2 = {fir,sec};
                if(fir == 0){
                    for(c2 = 1; c2 < (int)s.size(); ++c2)
                        if(s[c2]) break;
                    if(c2 == sec){
                        for(; c2 < (int)s.size(); ++c2){
                            if(s[c2]) break;
                        }
                    }
                    else
                        ++c2;
                }
                else if(sec == 0){
                    for(c2 = 1; c2 < (int)s.size(); ++c2)
                        if(s[c2]) break;
                    if(c2 == fir){
                        for(; c2 < (int)s.size(); ++c2){
                            if(s[c2]) break;
                        }
                    }
                    else
                        ++c2;
                }
                else{
                    c2 = 2;
                }
            }
        }
        if(min(c1,c2) == 0x7f7f7f7f) REE(-1);
        whatis(c1)
        whatis(c2)
        if(c1 < c2){
            s.erase(s.begin()+r1[0]);
            finish(s);
        }
        else{
            sort(all(r2));
            s.erase(s.begin()+r2[1]);
            s.erase(s.begin()+r2[0]);
            finish(s);
        }
    }
}