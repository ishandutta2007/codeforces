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

char str[1111111];

signed main(){
    scanf("%s",str);
    int len=strlen(str);

    vector<pint>v;
    int cur=0;
    while(cur<len){
        int nex=cur;
        while(nex<len&&str[cur]==str[nex])nex++;
        v.pb({str[cur]-'a',nex-cur});
        cur=nex;
    }

    for(int t=0;;t++){
        if(v.size()<=1){
            cout<<t<<endl;
            return 0;
        }

        vpint vv;
        rep(i,v.size()){
            pint p=v[i];
            if(i==0||i+1==v.size())p.se--;
            else p.se-=2;
            if(p.se<=0)continue;
            if(vv.size()&&vv.back().fi==p.fi)vv.back().se+=p.se;
            else vv.pb(p);
        }
        v=vv;
    }
    return 0;
}