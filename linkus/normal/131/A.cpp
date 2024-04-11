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
#define PRINT(arr,type) copy((arr).begin(), (arr).end(), ostream_iterator<(type)>(cout, " ")
#define REE(s_) {cout<<s_<<'\n';return 0;} //print s_ and terminate program
#define GET(vec,type,amount) copy_n(istream_iterator<(type)>(cin),(n),back_inserter((vec)))
#define MEMSET_INF 127 //2139062143 (USE FOR MEMSET)
#define INF 2139062143 //for comparison
typedef std::vector<int> vi;
typedef std::vector<std::string> vs;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
using namespace std;

int sth(string &str){
for(auto i=str.begin()+1;i!=str.end();i++){
if(islower(*i))
    return false;
}
return true;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    cin >> str;
    if(str.size()>1){
        if(sth(str)){
            if(isupper(str[0]))
                str[0]=tolower(str[0]);
            else
                str[0]=toupper(str[0]);
            transform(str.begin()+1, str.end(), str.begin()+1, ::tolower);
        }
    }
    else{
        if(isupper(str[0]))
            str[0]=tolower(str[0]);
        else
            str[0]=toupper(str[0]);
    }

    cout << str;
}