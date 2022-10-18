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
    const string alpha[] = {"Juliusz ","Adam ","Patryk ","Kotelski ","Szymon ","Jarek ","Kotlet ","Cwel ","Wojtek ","Gajda ","Frajda ","Czyz ","Marcel ","Ania ","Anna ","Joanna ","Joasia ","Asia ","Marcelina ","Julek ","Kania ","Lofek ","Natalia ","Rus ","Adi ","Adamek ","Klaudia ","Ola ","Aleksandra ","Budny ","Mikolaj ","Michal ","Szymanski ","Bartek ","Tartek ","Karka ","Tarka ","Karolina ","Loreina ","Lizda ","Pizda ","Loszka ","Dupka ","Ram ","Pam ","Bam ","Le ","Nudes ","Pls ","Send ","Them ","To ","Meh ","Me ","Gwiazdka ","Amper ","Sand ","Sth ","Okay ","That ","Nuff ","Iam ","Thinking ","About ","You ","Babe ","Baby ","Bejbeh ","Love ","Du ","Lessthanthree"};
    int n,k;
    cin >> n >> k;
    int index[n];
    int cur = 0;
    bool repeat[n];
    string tmp;
    for(int i = k-1;i<n;++i){
        cin >> tmp;
        repeat[i] = (tmp=="YES"?0:1);
    }
    for(int i = 0;i<k-1;i++){
        index[i] = ++cur;
    }
    for(int i = k-1;i<n;++i){
        if(repeat[i])
            index[i] = index[i-k+1];
        else
            index[i] = ++cur;
    }
    FORR(i,index)
        //cout << (char)('A' + (i%26)) << (char)('a' + (i%26)) << ' ';
		cout << alpha[i];
}