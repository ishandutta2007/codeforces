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

bool xorr(bool n1, bool n2){
    if(n1){
        if(n2)
            return 0;
        else
            return 1;
    }
    else{
        if(n2)
            return 1;
        else
            return 0;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    string str;
    bool n1,n2,n3,n4;
    cin >> n1 >> n2 >> n3 >> n4;
    bool fl1,fl2,fr1,fr2,sl,sr,fin;
    fl1 = xorr(n1,n2);
    fl2 = n3||n4;
    fr1 = n2&&n3;
    fr2 = xorr(n1,n4);
    sl = fl1&&fl2;
    sr = fr1||fr2;
    fin = xorr(sl,sr);
    cout << fin << '\n';
    /*wtf(fl1)
    wtf(fl2)
    wtf(fr1)
    wtf(fr2)
    wtf(sl)
    wtf(sr)*/
}