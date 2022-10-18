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
#define GET(vec,amount) copy_n(istream_iterator<int>(cin),(n),back_inserter((vec)))
#define INPUT(arr) for(auto &i: (arr)) cin>>i
#define MEMSET_INF 127 //2139062143 (USE FOR MEMSET)
#define INF 2139062143 //for comparison
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    cin >> s;
    int bal = 0;
    int cnh = 0;
    int pos = 0;
    FOR(i,0,s.size()){
        if(s[i] == '(') ++bal;
        else if(--bal < 0) REE(-1)
        if(s[i] == '#') ++cnh, pos = i;
    }
    int b2 = 0;
    FOR(i,0,s.size()){
        if(s[i] == '(') ++b2;
        else if(s[i] == ')') --b2;
        else{
            if(i == pos) b2 -= bal+1;
            else --b2;
        }
        if(b2 < 0) REE(-1);
    }
    FOR(i,1,cnh) cout << "1\n";
    cout << bal+1 << '\n';
}