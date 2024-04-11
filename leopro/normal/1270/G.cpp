#include <bits/stdc++.h>
using namespace std;
/////////////////
  #define int ll
//  #define ll unsigned ll
typedef long long ll;
typedef long double ld;
typedef long long var;
typedef pair<int,int>pri;
typedef pair<ll,ll>prl;
typedef vector<int>veci;
typedef vector<ll>vecl;
typedef vector<veci> graph;
typedef map<int,int> mapi;
#define WHITE 0
#define GRAY  1
#define BLACK 2
#define psh push_back
#define pp pop_back
#define all(a) a.begin(),a.end()
#define binser binary_search
#define qsort sort
#define msort stable_sort
#define hsort heap_sort
#define vec vector
#define forn(i,n) for(int i=0;i<(n);i++)
#define mod(a) ((a)%(MOD))
#define $ '\n'
#define coutop(type, code) \
    ostream &operator << (ostream &out, const type &__##type) { \
        {code}\
        return out;\
    } 
#define cinop(type, code) \
    istream &operator >> (istream &in, type &__##type) { \
        {code}\
        return in;\
    }
template<class T>T gcd(T a,T b){while(a&&b)if(a>b)a%=b;else b%=a;return a+b;}
template<class T>void sortf(vector<T>&v){stable_sort(v.begin(),v.end());}
template<class T>void sortb(vector<T>&v){stable_sort(v.rbegin(),v.rend());}
template<class T>T max3(T a,T b,T c){return max(a,max(b,c));}template<class T>T
min3(T a,T b,T c){return min(a,min(b,c));}template<typename T>istream&operator>>
(istream&in,vector<T>&v){for(T&t:v)in>>t;return in;}ostream&operator<<(ostream&
out,const vector<char>&v){for(const char&t:v)out<<t;out<<endl;return out;}
template<typename T>ostream&operator<<(ostream&out,const vector<T>&v){for(const
T&t:v)out<<t<<' ';return out;}static void init_iostream_speed(){cin.tie(nullptr)
;cout.tie(nullptr);ios::sync_with_stdio(false);}template<typename T>T lcm(T a,T
b){return a*b/gcd(a,b);}template<class T>void swap(T*a,T*b){T c=*a;*a=*b;*b=c;}
template<typename T>class vector2:public vector<T>{public:int min_ind(){return
min_element(this->begin(),this->end())-this->begin();}int max_ind(){return
max_element(this->begin(),this->end())-this->begin();}T min(){return*min_element
(this->begin(),this->end());}T max(){return*max_element(this->begin(),this->end(
));}void sortf(){::sortf(*this);}void sortb(){::sortb(*this);}vector2():vector<T
>(){}vector2(vector<T>__v):vector<T>(__v){}vector2(initializer_list<T>__i_l):
vector<T>(__i_l){}vector2(size_t __n,size_t __val=0):vector<T>(__n,__val){}};
template<class T>T sum(vector<T>&vc){T ans=0;for(T&v:vc)ans+=v;return ans;}int
nextInt(){int t;cin>>t;return t;}ll nextLong(){ll t;cin>>t;return t;}constexpr 
ll MOD=1000000007;bool operator<<(const string&a,const string&b){if(a==b)return
true;if(a.size()!=b.size())return a.size()<b.size();return a<b;}int intlen(ll x)
{int res=1;while(x/=10)res++;return res;}string operator*(const string&s,int x){
string a;while(x--)a+=s;return a;}ll factorial(int x){ll a=1;for(int i=1;i<=x;i
++)a*=i;return a;}template<class T>void reverse(vector<T>&a){for(int i=0;i<(int)
a.size()/2;i++)swap(a[i],a[a.size()-1-i]);}class TaskAnswer{};template<class T>
void answer(const T&a){cout<<a<<'\n';throw TaskAnswer();}
 
inline void __main_task();
signed main() {
    init_iostream_speed();
//    for(;;){try{__main_task();}catch(TaskAnswer){}cout<<endl;}
    int t;cin>>t;while(t--)
    try{__main_task();}catch(TaskAnswer){}
    cout.flush();
    return 0;
}
inline void __main_task() {
    int n, cyc, cnt = 0, v;
    cin >> n;
    veci g(n);
    for (int i = 0, a; i < n; i++) {
        cin >> a;
        g[i] = i - a;
    }
    cyc = 0;
    for (int i = 0; i < n; i++) cyc = g[cyc];
    v = cyc;
    do {
        v = g[v];
        cnt++;
    } while (v != cyc);
    cout << cnt << $;
    for (int i = 0; i < cnt; i++) {
        cout << v + 1 << ' ';
        v = g[v];
    }
    cout << $;
}