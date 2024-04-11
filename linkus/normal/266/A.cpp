#include <bits/stdc++.h> //Stack size ~2'000'000(x4) use "int *arr = new int[n]" above that
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) (a.begin()),(a.end())
#define FOR(x,val,to) for(int x=(val);x<int((to));++x)
#define FORE(x,val,to) for(auto x=(val);x<=(to);++x)
#define FORR(x,arr) for(auto &x: arr)
#define FORRC(x,arr) for(auto const &x: arr)
#define PRINT(arr) {copy((arr).begin(), (arr).end(), ostream_iterator<int>(cout, " "));cout<<'\n';}
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
#define getchar_unlocked() getchar()
//inline int getchar_unlocked() { return getchar(); }
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]"; return os; }//prnt vec
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) { os<<"("<<P.first<<","<<P.second<<")"; return os; }//prnt pair
template<typename T> inline void sc(T &num){bool neg=0;int c;num=0;c=getchar_unlocked();if(c=='-'){neg=1;c=getchar_unlocked();} for(;c>47&&c<58;c=getchar_unlocked()) num=num*10+c-48;if(neg) num*=-1;}
inline void getstr(string &str){char cur=getchar_unlocked();while(cur>32){str+=cur;cur=getchar_unlocked();}}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);//remove if using sc and CIN
    string str;
    int n;
    int ans=0;
    sc(n);getstr(str);
    for(auto i = str.begin(); i != str.end()-1; ++i){
        if(*i == *(i+1)){
            ++ans;
            if(*i == 'R'){
                if(i == str.begin() || *(i-1) == 'B')
                    *i = 'G';
                else
                    *i = 'B';
            }
            else if(*i == 'G'){
                if(i == str.begin() || *(i-1) == 'B')
                    *i = 'R';
                else
                    *i = 'B';
            }
            else{
                if(i == str.begin() || *(i-1) == 'R')
                    *i = 'G';
                else
                    *i = 'R';
            }
        }
    }
    cout << ans << '\n';
}