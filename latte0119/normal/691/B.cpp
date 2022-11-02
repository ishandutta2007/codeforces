#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

string lis="aBCcDEeFfGghiJjKkLlmNnPQRrSstuyZz";

signed main(){
    string s;
    cin>>s;


    bool ok=true;
    for(int i=0;i<s.size();i++){
        char a=s[i];
        char b=s[s.size()-1-i];
        if(find(all(lis),a)!=lis.end())ok=false;

        if(a=='b')ok&=b=='d';
        else if(a=='d')ok&=b=='b';
        else if(a=='p')ok&=b=='q';
        else if(a=='q')ok&=b=='p';
        else ok&=a==b;
    }
    if(ok)cout<<"TAK"<<endl;
    else cout<<"NIE"<<endl;

    return 0;
}