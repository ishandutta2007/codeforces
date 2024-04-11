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
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int A,B,W,X,C;

signed main(){
    cin>>A>>B>>W>>X>>C;

    int lo=-1,hi=1e15;

    while(hi-lo>1){
        int mid=(hi+lo)/2;
        if(C-mid<=A-(max(0ll,mid*X-B)+W-1)/W)hi=mid;
        else lo=mid;
    }

    cout<<hi<<endl;
    return 0;
}