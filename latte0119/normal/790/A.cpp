#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

string getname(int n){
    string res;
    for(int i=0;i<3;i++){
        res+='a'+n%26;
        n/=26;
    }
    res[0]=toupper(res[0]);
    return res;
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<string>ans;

    int cur=0;
    rep(i,k-1){
        ans.pb(getname(cur++));
    }

    for(int i=k-1;i<n;i++){
        string str;
        cin>>str;
        if(str=="NO"){
            ans.pb(ans[i-k+1]);
        }
        else{
            ans.pb(getname(cur++));
        }
    }

    rep(i,n)cout<<ans[i]<<" ";cout<<endl;
    return 0;
}