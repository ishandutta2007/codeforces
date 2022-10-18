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
#define FORRC(x,arr) for(auto const &x: arr)
#define PRINT(arr) {copy((arr).begin(), (arr).end(), ostream_iterator<int>(cout, " "));cout<<'\n';}
#define REE(s_) {cout<<s_<<'\n';return 0;} //print s_ and terminate program
#define GETVEC(vec,amount) copy_n(istream_iterator<int>(cin),(n),back_inserter((vec)))
#define GET(arr) for(auto &i: (arr)) cin>>i
#define MEMSET_INF 127 //2139062143 (USE FOR MEMSET) - memset(arr,MEMSET_INF,size*4!!!!)
#define INF 2139062143 //for comparison
#define ULL_INF 18446744073709551614 //for comparison
#define f first
#define s second
#define wtf(x) cerr << #x << " is " << x << endl;
#define whatis wtf
#define alive cerr << "STH" << endl;
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
using namespace std;

template<class T> ostream& operator<<(ostream &os, vector<T> V) {
  os<<"[";for(auto const &vv:V)os<<vv<<","; os<<"]";
  return os;
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L, R> P) {
  os<<"("<<P.first<<","<<P.second<<")";
  return os;
}





const int N = 100002;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    int tmp;
    int arr[N];
    memset(arr,0,N*4);
    ll dp[N];
    while(n--){
        cin >> tmp;
        arr[tmp]++;
    }
    arr[0] = 0;
    FOR(i,1,N){
        dp[i] = (ll)i * arr[i];
        if(i > 1){
            dp[i] += dp[i-2];
        }
        if(dp[i-1] > dp[i]){
            dp[i] = dp[i-1];
        }
    }
    cout << dp[100001] << '\n';
    return 0;
}
















/*int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    int n;
    cin >> n;
    vector<pair<int,int>> mp(100003,{0,0});
    int tmp;
    ll ans = 0;
    int maxe = -2000000000;
    int mine = INF;
    while(n--){
        cin >> tmp;
        mp[tmp].second+=tmp;
        mine = min(mine, tmp);
        maxe = max(maxe, tmp);
    }
    for(auto i=mp.begin();i!=mp.end()-1;++i){
        (*i).first += (*i).second;
        (*(i-1)).first -= (*i).second;
        (*(i+1)).first -= (*i).second;
    }
    FORR(i,mp){
        if(i.second == 0)
            i.first = -1'000'000'000;
    }
    auto mpbeg = mp.begin()+mine;
    auto mpend = mp.begin()+maxe+1;
    FORRC(i,mp)
        cout << i << " ";
    cout << endl;
    while(true){
        auto cur = max_element(mpbeg,mpend); //bottlenack
        //auto cur = max_element(all(mp)); //bottlenack
        //whatis(*cur);
        if(*cur == pair<int,int>{0,0})
            break;
        ans += (*cur).second;
        if(cur - mp.begin() > 1)
            (*(cur-2)).first += (*(cur-1)).second;
        (*(cur+2)).first += (*(cur+1)).second;
        *(cur-1) = {0,0};
        *(cur+1) = {0,0};
        *cur = {0,0};
    }
    //FORRC(i,mp)
        //cout << i << " ";
    cout << ans;
}
*/