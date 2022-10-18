#include <bits/stdc++.h> //Stack size ~2'000'000(x4)
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) begin(a),end(a)
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORS(x,plus,arr) for(auto x = begin(arr)+(plus); x < end(arr); ++x)
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
#define getcor cin >> pos.e1 >> pos.e2; --pos.e1, --pos.e2
#define isend if(adj[pos.e1][pos.e2] == 'F') exit(0)

int main(){
    ios_base::sync_with_stdio(0);
    int n,m;
    cin >> n >> m;
    string adj[n];
    FORR(i,adj)
        cin >> i;
    if(adj[0][0] == 'F')
        return 0;
    bool reslr = 0, resud = 0;
    char l = 'L';
    char r = 'R';
    char u = 'U';
    char d = 'D';
    pi pos = {0,0};
    if(adj[0][1] != '*'){
        cout << 'R' << endl;
        getcor;
        isend;
        reslr = 1;
        if(pos.e2 == 0){
            swap(l,r);
        }
        while(1){
            if(adj[1][pos.e2] != '*'){
                cout << 'D' << endl;
                getcor;
                isend;
                resud = 1;
                if(pos.e1 == 0)
                    swap(u,d);
                break;
            }
            if(pos.e2 + 1 == m || adj[pos.e1][pos.e2+1] == '*')
                break;
            cout << r << endl;
            getcor;
            isend;
        }
    }
    if(!resud)
    if(adj[1][0] != '*'){
        while(pos.e2){
            cout << l << endl;
            getcor;
        }
        cout << 'D' << endl;
        getcor;
        isend;
        resud = 1;
        if(pos.e1 == 0)
            swap(u,d);
        if(!reslr)
        while(1){
            if(adj[pos.e1][1] != '*'){
                cout << 'R' << endl;
                getcor;
                isend;
                reslr = 1;
                if(pos.e2 == 0)
                    swap(l,r);
                break;
            }
            if(pos.e1 + 1 == n || adj[pos.e1+1][pos.e2] == '*')
                break;
            cout << d << endl;
            getcor;
            isend;
        }
    }
    bool visited[n][m];
    memset(visited,0,sizeof visited);
    /* visited[pos.e1][pos.e2] = 1; */
    FOR(i,0,n){
        FOR(x,0,m){
            if(adj[i][x] == '*')
                visited[i][x] = 1;
        }
    }
    struct st{
        int e1;
        int e2;
        string nxt;
    };
    queue<st> qu;
    qu.push({pos.e1,pos.e2,string()});
    /* string paths[n][m]; */
    string finpath;
    while(1){
        st cur = qu.front(); qu.pop();
        if(cur.e1 < 0 || cur.e1 == n || cur.e2 < 0 || cur.e2 == m || visited[cur.e1][cur.e2])
            continue;
        visited[cur.e1][cur.e2] = 1;
        /* paths[cur.e1][cur.e2] += cur.nxt; */
        /* whatis(cur.e1) */
        /* whatis(cur.e2) */
        /* whatis(paths[cur.e1][cur.e2]) */
        if(adj[cur.e1][cur.e2] == 'F'){
            /* finpath = paths[cur.e1][cur.e2]; */
            finpath = cur.nxt;
            break;
        }
        qu.push({cur.e1-1,cur.e2,cur.nxt+u});
        qu.push({cur.e1,cur.e2+1,cur.nxt+r});
        qu.push({cur.e1+1,cur.e2,cur.nxt+d});
        qu.push({cur.e1,cur.e2-1,cur.nxt+l});
        /* if(cur.e1 && !visited[cur.e1-1][cur.e2]){ */
        /*     visited[cur.e1-1][cur.e2] = 1; */
        /*     paths[cur.e1-1][cur.e2] = paths[cur.e1][cur.e2] + u; */
        /*     qu.push({cur.e1-1,cur.e2}); */
        /* } */
        /* if(cur.e2 && !visited[cur.e1][cur.e2-1]){ */
        /*     visited[cur.e1][cur.e2-1] = 1; */
        /*     paths[cur.e1][cur.e2-1] = paths[cur.e1][cur.e2] + l; */
        /*     qu.push({cur.e1,cur.e2-1}); */
        /* } */
        /* if(cur.e1 + 1 < n && !visited[cur.e1+1][cur.e2]){ */
        /*     visited[cur.e1+1][cur.e2] = 1; */
        /*     paths[cur.e1+1][cur.e2] = paths[cur.e1][cur.e2] + d; */
        /*     qu.push({cur.e1+1,cur.e2}); */
        /* } */
        /* if(cur.e2 + 1 < m && !visited[cur.e1][cur.e2+1]){ */
        /*     visited[cur.e1][cur.e2+1] = 1; */
        /*     paths[cur.e1][cur.e2+1] = paths[cur.e1][cur.e2] + r; */
        /*     qu.push({cur.e1,cur.e2+1}); */
        /* } */
    }
    /* queue<pi> qu; */
    /* qu.push(pos); */
    /* string paths[n][m]; */
    /* string finpath; */
    /* while(1){ */
    /*     pi cur = qu.front(); qu.pop(); */
    /*     if(adj[cur.e1][cur.e2] == 'F'){ */
    /*         finpath = paths[cur.e1][cur.e2]; */
    /*         break; */
    /*     } */
    /*     if(cur.e1 && !visited[cur.e1-1][cur.e2]){ */
    /*         visited[cur.e1-1][cur.e2] = 1; */
    /*         paths[cur.e1-1][cur.e2] = paths[cur.e1][cur.e2] + u; */
    /*         qu.push({cur.e1-1,cur.e2}); */
    /*     } */
    /*     if(cur.e2 && !visited[cur.e1][cur.e2-1]){ */
    /*         visited[cur.e1][cur.e2-1] = 1; */
    /*         paths[cur.e1][cur.e2-1] = paths[cur.e1][cur.e2] + l; */
    /*         qu.push({cur.e1,cur.e2-1}); */
    /*     } */
    /*     if(cur.e1 + 1 < n && !visited[cur.e1+1][cur.e2]){ */
    /*         visited[cur.e1+1][cur.e2] = 1; */
    /*         paths[cur.e1+1][cur.e2] = paths[cur.e1][cur.e2] + d; */
    /*         qu.push({cur.e1+1,cur.e2}); */
    /*     } */
    /*     if(cur.e2 + 1 < m && !visited[cur.e1][cur.e2+1]){ */
    /*         visited[cur.e1][cur.e2+1] = 1; */
    /*         paths[cur.e1][cur.e2+1] = paths[cur.e1][cur.e2] + r; */
    /*         qu.push({cur.e1,cur.e2+1}); */
    /*     } */
    /* } */
    FORR(i,finpath){
        cout << i << endl;
        char c;
        while(c = cin.get(), c != '\n');
        /* getcor; */
    }
}