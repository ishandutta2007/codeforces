#include<bits/stdc++.h>
using namespace std;

#define int long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define each(i,c) for(auto i=(c).begin();i!=(c).end();i++)
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    string s;cin>>s;
    int cnt=0;

    rep(i,s.size()){
        if((s[i]-'0')%4==0)cnt++;
        if(i==0)continue;
        int d=(s[i-1]-'0')*10+s[i]-'0';
        if(d%4)continue;
        cnt+=i;
    }
    cout<<cnt<<endl;
    return 0;
}