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

int a[1000000];
int n;

signed main(){
    cin>>n;
    int mi=111111111,ma=0;
    rep(m,6){
        int cnt=0;
        int t=m;
        while(t<n){
            cnt++;
            t++;
            if(t<n)cnt++;
            t+=6;
        }
        chmax(ma,cnt);
        chmin(mi,cnt);
    }
    cout<<mi<<" "<<ma<<endl;
    return 0;
}