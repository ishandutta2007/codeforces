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
#define PRINT(arr) copy((arr).begin(), (arr).end(), ostream_iterator<int>(cout, " "))
#define REE(s_) {cout<<s_<<'\n';return 0;} //print s_ and terminate program
#define GETVEC(vec,amount) copy_n(istream_iterator<int>(cin),(n),back_inserter((vec)))
#define GET(arr) for(auto &i: (arr)) cin>>i
#define MEMSET_INF 127 //2139062143 (USE FOR MEMSET) - memset(arr,MEMSET_INF,size)
#define INF 2139062143 //for comparison
#define ULL_INF 18446744073709551614 //for comparison
#define F first
#define S second
typedef std::pair<int,int> pi;
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k;
    cin >> n >> k;
    int sz = sqrt(n);
    vector<int> vec;
    //vec.reserve(sz);
    for(int i=1;i<=sz;i++){
        if(n%i == 0)
            vec.pb(i);
    }
    vector<ll> deq;
    //deq.reserve(sz);
    for(auto i=vec.rbegin(); i!=vec.rend(); i++){
        ll cur = (ll)n/(ll)(*i);
        if(cur < 2'147'483'647){
            if(!binary_search(all(vec),cur))
                deq.pb(cur);
        }
        else
            deq.pb(cur);
    }
    //move(deq.rbegin(), deq.rend(), back_inserter(vec));
    /*PRINT(vec);
    cout << string(5,'\n');
    PRINT(deq);
    cout << '\n';*/
    k--;
    if(k<vec.size()){
        cout << vec[k];
    }
    else{
        if(k>=vec.size()+deq.size())
            cout << -1;
        else
            cout << deq[k-vec.size()];
    }

}