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
int n;

bool ok(int x){
    if(x<1||x>n)return false;
    return true;
}

signed main(){
    int a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    int cnt=0;
    for(int i=0;i<4*n;i++){
        int v=i-a-b;
        int w=i-a-c;
        int y=i-b-d;
        int z=i-c-d;
        if(ok(v)&&ok(w)&&ok(y)&&ok(z)){
            cnt+=n;
        }
    }
    cout<<cnt<<endl;
    return 0;
}