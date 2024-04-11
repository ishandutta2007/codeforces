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
#define MEMSET_INF 127 //2139062143 (USE FOR MEMSET) - memset(arr,MEMSET_INF,size)
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

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    cin >> str;
    //int ans=str[0]-'0';
    auto index = find_if(str.begin(),str.end(),[](auto &cr){return cr=='+'||cr=='-';});
    int ans = stoi(str.substr(0,index-str.begin()));
    bool add;
    for(int i=index-str.begin();i<(int)str.size();){
        if(str[i]=='+'){
            add=true;
            ++i;
        }
        else if(str[i]=='-'){
            add=false;
            ++i;
        }
        else{
            auto index = find_if(str.begin()+i+1,str.end(),[](auto &cr){return cr=='+'||cr=='-';});
            string cur;
            if(index == str.end()){
                cur = str.substr(i);
                if(add)
                    ans += stoi(cur);
                else
                    ans -= stoi(cur);
                break;
            }
            else
                cur = str.substr(i,(index-str.begin())-i);
            if(add)
                ans += stoi(cur);
            else
                ans -= stoi(cur);
            i += (index-str.begin())-i;
        }
    }
    //cout << ans;
    cout << "-[----->+<]>";
    string res = to_string(ans);
    //whatis(res);
    int cur = 3;
    FORRC(i,res){
        int delta = (i-'0')-cur;
        if(delta>0)
            while(delta--)
                cout << '+';
        else if(delta<0)
            while(delta++)
                    cout << '-';
        cout << '.';
        cur = i-'0';
    }
}