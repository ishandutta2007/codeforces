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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

signed main(){
    string s;cin>>s;
    for(char c='a';c<='z'&&s.size();c++){
        string t;
        if(s[0]!=c){
            cout<<"NO"<<endl;
            return 0;
        }
        rep(i,s.size())if(s[i]!=c)t+=s[i];
        s=t;
    }
    cout<<"YES"<<endl;
    return 0;
}