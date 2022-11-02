#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define all(v) (v).begin(),(v).end()
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
#define pb push_back
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int cnt[1000010];

signed main(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;

    int z=0,o=0;
    for(;z*(z-1)/2<a;z++);
    for(;o*(o-1)/2<d;o++);

    if(a==0&&d==0){
        rep(i,2)rep(j,2)if(i*j==b+c)tie(z,o)=tie(i,j);
    }
    else if(a==0){
        rep(i,2)if(i*o==b+c)z=i;
    }
    else if(d==0){
        rep(j,2)if(z*j==b+c)o=j;
    }

    if(z*(z-1)/2!=a||o*(o-1)/2!=d||b+c!=z*o){
        cout<<"Impossible"<<endl;
        return 0;
    }

    int cur=b;
    for(int i=0;i<o;i++){
        cnt[min(cur,z)]++;
        cur=max(cur-z,0ll);
    }
    string ans;
    for(int i=0;i<=z;i++){
        if(i)ans+='0';
        ans+=string(cnt[i],'1');
    }
    cout<<ans<<endl;
}