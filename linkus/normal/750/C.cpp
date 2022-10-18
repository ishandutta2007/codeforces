#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define all(a) (a.begin()),(a.end())
#define ZERO(a) meset(a,0,sizeof(a))
#define FOR(x,val,to) for(int x=(val);x<int((to));x++)
#define FORE(x,val,to) for(auto x=(val);x<=(to);x++)
#define FORR(x,arr) for(auto &x: arr)
#define PRINT(arr) copy((arr).begin(), (arr).end(), ostream_iterator<int>(cout, " "))
#define REE(s_) {cout<<s_<<'\n';return 0;} //print s_ and terminate program
#define GETVEC(vec,amount) copy_n(istream_iterator<int>(cin),(n),back_inserter((vec)))
#define GET(arr) for(auto &i: (arr)) cin>>i
#define MEMSET_INF 127 //2139062143 (USE FOR MEMSET) - memset(arr,MEMSET_INF,size)
#define INF 2139062143 //for comparison
#define ULL_INF 18446744073709551614 //for comparison
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
using namespace std;

#define whatis(x) cerr << #x << " is " << x << endl;


#define getchar_unlocked() getchar()

inline void sc(ll &n){
    int c;
    bool min = 0;
    while(c = getchar_unlocked(), c < 45);
    if(c == '-') min = 1, c = getchar_unlocked();
    n = c-48;
    while(c = getchar_unlocked(), c > 47){
        n = n*10+c-48;
    }
    if(min)
        n = -n;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n;
    sc(n);
    ll ans = 0x6f7f7f7f;
    ll f,s;
    bool inf = 1;
    ll mn = -0x7f7f7f7f;
    while(n--){
        sc(f);
        sc(s);
        if(s == 1){
            if(ans < 1900) REE("Impossible")
            ans += f;
            mn = max(1900ll,mn);
            mn += f;
        }
        else{
            if(mn >= 1900) REE("Impossible")
            inf = 0;
            ans = min(ans,1899ll);
            ans += f;
            mn += f;
        }
    }
    cout << (!inf?to_string(ans):"Infinity") << '\n';
}