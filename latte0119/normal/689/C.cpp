#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

int C(int x){
    int sum=0;
    for(int i=2;;i++){
        int t=i*i*i;
        if(t>x)break;
        sum+=x/t;
    }
    return sum;
}

int M;

signed main(){
    cin>>M;

    int lb=0,ub=20000000000000000ll;
    while(ub-lb>1){
        int mid=(ub+lb)/2;
        if(C(mid)<M)lb=mid;
        else ub=mid;
    }

    if(C(ub)!=M)cout<<-1<<endl;
    else cout<<ub<<endl;

    return 0;
}