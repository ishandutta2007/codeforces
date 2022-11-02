#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    string s;cin>>s;
    int ans=0;
    for(auto c:s){
        if(isdigit(c)){
            int d=c-'0';
            if(d%2)ans++;
        }
        else{
            if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}