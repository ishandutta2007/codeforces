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
#define REE(s_) {cout<<s_<<'\n';return 0;} //print s_ and terminate program
#define GETCIN(arr) for(auto &i: (arr)) cin>>i
#define GET(arr) for(auto &i: (arr)) sc(i)
#define GETSTR(arr) for(auto &i: (arr)) getstr(i)
#define INF 2139062143 //127 in memset -> memset(arr,127,size)
#define SINF 1061109567 //Safe INF, for graphs or 2d arrays 63 in memset(arr,63,size)
#define LL_INF 7234017283807667300 //100 in memset(arr,100,size) !!!must be LL
#define whatis(x) cerr << #x << " is " << x << endl;
#define e1 first
#define e2 second
typedef std::pair<int,int> pi; typedef std::vector<int> vi; typedef std::vector<std::string> vs;
using namespace std;

#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }//prnt vec
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }//prnt pair
template<typename T> inline T fstoi(const string &str){auto it=str.begin();bool neg=0;T num=0;if(*it=='-')neg=1;else num=*it-'0';++it;while(it<str.end()) num=num*10+(*it++-'0');if(neg)num*=-1;return num;}
inline void getstr(string &str){str.clear(); char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}}template<typename ...Args> inline void getstr(string &str, Args &...arg){str.clear();char cur;while(cur=getchar_unlocked(),cur<33){;}while(cur>32){str+=cur;cur=getchar_unlocked();}getstr(arg...);}
template<typename T> inline void sc(T &num){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; }template<typename T, typename ...Args> inline void sc(T &num, Args &...args){ bool neg=0; int c; num=0; while(c=getchar_unlocked(),c<33){;} if(c=='-'){ neg=1; c=getchar_unlocked(); } for(;c>47;c=getchar_unlocked()) num=num*10+c-48; if(neg) num*=-1; sc(args...); }

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    vector<string> vec(n);
    GETSTR(vec);
    vector<string> perm(vec[0].size());
    perm[0] = vec[0];
    for(int i = 1; i < (int)vec[0].size(); ++i){
        string cur = perm[i-1];
        cur.push_back(cur.front());
        cur.erase(0,1);
        perm[i] = cur;
    }
    int dist[n][perm.size()];
    int index = 0;
    for(auto i = vec.begin(); i < vec.end(); ++i){
        auto ind = find(all(perm),*i);
        if(ind == perm.end())
            REE("-1\n");
        int cr = distance(perm.begin(),ind);
        int x = cr;
        cr += perm.size();
        int cdist = 0;
        for(;x < cr;++cdist,++x){
            dist[index][x%perm.size()] = cdist;
        }
        ++index;
    }
    for(auto i = perm.begin()+1; i < perm.end(); ++i){
        auto it = find(perm.begin(),i,*i);
        if(it != i){
            int sndind = distance(perm.begin(),it);
            int index = distance(perm.begin(),i);
            for(int x = 0; x < n; ++x){
                if(dist[x][index] < dist[x][sndind]){
                    dist[x][sndind] = dist[x][index];
                }
                else
                    dist[x][index] = dist[x][sndind];
            }
        }
    }
    ll ans = INF;
    for(size_t i = 0; i < perm.size(); ++i){
        ll csize = 0;
        for(size_t x = 0; x < (size_t)n; ++x){
            csize += dist[x][i];
        }
        ans = min(ans,csize);
    }
    cout << ans << '\n';
}