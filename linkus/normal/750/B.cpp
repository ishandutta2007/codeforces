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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    int n;
    int ans=0;
    cin >> n;
    int dist;
    ll pos=20000;
    while(n--){
        cin>>dist>>str;
        if(str=="West"||str=="East"){
            if(pos==20000||pos==0)
                REE("NO")
            else
                continue;
        }
        if(str=="North")
            pos+=dist;
        else
            pos-=dist;
        if(pos>20000||pos<0)
            REE("NO")
    }
    if(pos==20000)
        cout<<"YES";
    else
        cout<<"NO";
}