#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>inline void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>inline void chmax(T &t,U f){if(t<f)t=f;}

signed main(){
    int s,t;
    int a,b;
    cin>>s>>t>>a>>b;
    rep(i,1111111){
        int tmp=12;
        if(!i)tmp=8;
        s+=tmp*a;
        if(s>=t){
            cout<<i<<endl;
            return 0;
        }
        s-=12*b;
    }
    cout<<-1<<endl;
    return 0;
}