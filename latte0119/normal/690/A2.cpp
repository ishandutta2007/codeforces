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
    int N;
    cin>>N;

    if(N&1){
        cout<<N/2<<endl;
        return 0;
    }
    if(N==2){
        cout<<0<<endl;
        return 0;
    }

    int d=0;
    for(int i=2;;i*=2){
        if(d+i>=N)break;
        d+=i;
    }
    cout<<(N-d)/2-1<<endl;
    return 0;
}