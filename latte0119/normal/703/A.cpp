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
#define mp make_pair
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int n;cin>>n;
    int a=0,b=0;
    rep(i,n){
        int x,y;
        cin>>x>>y;
        if(x<y)b++;
        else if(x>y)a++;
    }
    if(a>b)cout<<"Mishka"<<endl;
    else if(a<b)cout<<"Chris"<<endl;
    else cout<<"Friendship is magic!^^"<<endl;
    return 0;
}