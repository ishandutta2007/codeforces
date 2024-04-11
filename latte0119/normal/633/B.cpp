#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef long long ll;
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

signed main(){
    int m;cin>>m;
    int sum=0;
    for(int i=5;true;i+=5){
        int cnt=0;
        int tmp=i;
        while(tmp%5==0){cnt++;tmp/=5;}
        sum+=cnt;
        if(sum==m){
            puts("5");
            rep(j,5)printf("%d ",i+j);
            puts("");
            return 0;
        }
        else if(sum>m){
            puts("0");
            return 0;
        }
    }
    return 0;
}