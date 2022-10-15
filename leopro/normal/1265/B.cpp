#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pri;
typedef pair<ll,ll>prl;
typedef vector<int>veci;
typedef vector<ll>vecl;
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
template<class T>T
gcd(T a,T b){while(a&&b)if(a>b)a%=b;else b%=a;return a+b;}template<class T>void
sortf(vector<T>&v){stable_sort(v.begin(),v.end());}template<class T>void sortb(
vector<T>&v){stable_sort(v.rbegin(),v.rend());}template<class T>T max3(T a,T b,
T c){return max(a,max(b,c));}template<class T>T min3(T a,T b,T c){return min(a,
min(b,c));}template<typename T>istream&operator>>(istream&in,vector<T>&v){for(T&
t:v)in>>t;return in;}ostream&operator<<(ostream&out,const vector<char>&v){for(
const char&t:v)out<<t;out<<endl;return out;}template<typename T>ostream&operator
<<(ostream&out,const vector<T>&v){for(const T&t:v)out<<t<<' ';out<<endl;return 
out;}static void init_iostream_speed(){/*cin.tie(nullptr);cout.tie(nullptr);*/ios::
sync_with_stdio(false);}template<typename T>T lcm(T a,T b){return a*b/gcd(a,b);}
template<class T>void swap(T*a,T*b){T c=*a;*a=*b;*b=c;}template<typename T>class
vector2:public vector<T>{public:int min_ind(){return min_element(this->begin(),
this->end())-this->begin();}int max_ind(){return max_element(this->begin(),this
->end())-this->begin();}T min(){return*min_element(this->begin(),this->end());}T
max(){return*max_element(this->begin(),this->end());}void sortf(){::sortf(*this)
;}void sortb(){::sortb(*this);}vector2():vector<T>(){}vector2(vector<T>__v):
vector<T>(__v){}vector2(initializer_list<T>__i_l):vector<T>(__i_l){}vector2(
size_t __n,size_t __val=0):vector<T>(__n,__val){}};template<class T>T sum(vector
<T>&vc){T ans=0;for(T&v:vc)ans+=v;return ans;}int nextInt(){int t;cin>>t;return
t;}ll nextLong(){ll t;cin>>t;return t;}constexpr ll MOD=1000000007;
bool operator<<(const string&a,const string&b){//compare strings as integers
if(a==b)return true;if(a.size()!=b.size())return a.size()<b.size();return a<b;}
int intlen(ll x){int res=1;while(x/=10)res++;return res;}
//#define __OL_DEBUG

#define mod(a) ((a)%(MOD))

inline void __main_task();
signed main() {
    init_iostream_speed();
    #ifdef __OL_DEBUG
    for (;;) {
        __main_task();
        cout << endl;
    }
	#else
    int t;cin>>t;while(t--)
    __main_task();
	#endif
    return 0;
}

inline void __main_task() {
    int n, m; cin >> n;
    veci a(n), pos(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pos[--a[i]] = i;
    }
    int l = pos[0];
    int r = pos[0];
    for (int i = 0; i < n; ++i) {
        l = min(l, pos[i]);
        r = max(r, pos[i]);
        cout << char('0' + (r - l <= i));
	}    
    cout << '\n';
}