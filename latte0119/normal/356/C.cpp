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
    int N;
    cin>>N;

    vint cnt(5);

    int sum=0;
    rep(i,N){
        int c;cin>>c;
        cnt[c]++;
        sum+=c;
    }

    int ans=LLONG_MAX;

    for(int x=0;x*3<=sum;x++){
        if((sum-3*x)%4)continue;
        int y=(sum-3*x)/4;

        vint a=cnt;
        int val=0;
        if(a[4]>=y){
            int t=a[4]-y;
            val+=t;
            a[3]+=t;

            if(x-a[3]<=a[2])val+=(a[2]-(x-a[3]))*2+a[1];
            else val+=max(0ll,a[1]-(x-a[3]-a[2]));
        }
        else{
            if(a[4]+a[3]>=x+y){
                val=a[1]+a[2]*2+(a[4]+a[3]-x-y)*3;
            }
            else if(a[4]+a[3]+a[2]>=x+y)val=a[1]+(a[4]+a[3]+a[2]-x-y)*2;
            else val=a[4]+a[3]+a[2]+a[1]-x-y;
        }
        chmin(ans,val);
    }
    if(ans==LLONG_MAX)cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}