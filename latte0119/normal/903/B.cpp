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
    int h,a,c;
    int hh,aa;
    cin>>h>>a>>c>>hh>>aa;
    vector<string>x;
    int cur=h;
    rep(t,111111111){
        if(hh<=0)break;
        if(hh-a<=0||cur-aa>0){
            hh-=a;
            x.pb("STRIKE");
        }
        else{
            cur+=c;
            x.pb("HEAL");
        }
        cur-=aa;

    }

    cout<<x.size()<<endl;
    rep(i,x.size())cout<<x[i]<<endl;
}