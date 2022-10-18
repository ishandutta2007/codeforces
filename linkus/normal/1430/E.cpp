#include <bits/stdc++.h>
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
#define INF 0x7F7F7F7F //2139062143 | 127 in memset -> memset(arr,127,size)
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
template<typename T> inline T mod(T i, T n) { return (i % n + n) % n; }

ll ans;

inline void merge_sort(pair<char,int> *beg, pair<char,int> *end){
    if(beg + 1 == end) return;
    int32_t allsize = end-beg;
    int32_t size1 = allsize >> 1;
    int32_t size2 = size1 + (allsize&1);
    pair<char,int> *middle = beg+size1;
    merge_sort(beg,middle);
    merge_sort(middle,end);
    pair<char,int> vec1[size1];
    pair<char,int> vec2[size2];
    // why no memcpy xd
    copy_n(beg,size1,vec1);
    copy_n(middle,size2,vec2);
    auto it1 = vec1;
    auto it2 = vec2;
    auto end1 = vec1+size1;
    auto end2 = vec2+size2;
    while(beg < end){
        if(it1->e2 <= it2->e2){ //Sortowanie wedle docelowej pozycji
            *beg++ = *it1;
            if(++it1 == end1){
                while(beg < end)
                    *beg++ = *it2++;
                break;
            }
        }
        else{
            *beg++ = *it2;
            ans += end1-it1; //Zliczanie zamian
            if(++it2 == end2){
                while(beg < end)
                    *beg++ = *it1++;
                break;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    sc(n);
    string arr1(n,0);
    FORR(i,arr1)
        i = getchar_unlocked();
    /* getchar_unlocked(); */
    pair<char,int> arr2[n];
    FOR(i,0,n){
        arr2[i].e1 = arr1[n-i-1];
    }
    /* FORR(i,arr2){ */
    /*     i.e1 = getchar_unlocked(); */
    /* } */

        //Nadanie kademu znaku w drugim nazwisku docelowej pozycji
    queue<int> qu1[128];
    queue<int> qu2[128];
    for(int i = 0; i < n; ++i){
        if(qu2[arr1[i]].empty()){
            qu1[arr1[i]].push(i);
        }
        else{
            arr2[qu2[arr1[i]].front()].e2 = i;
            qu2[arr1[i]].pop();
        }
        if(qu1[arr2[i].e1].empty()){
            qu2[arr2[i].e1].push(i);
        }
        else{
            arr2[i].e2 = qu1[arr2[i].e1].front();
            qu1[arr2[i].e1].pop();
        }
    }
    merge_sort(arr2,arr2+n);
    cout << ans << '\n';
}