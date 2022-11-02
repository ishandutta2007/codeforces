#include<bits/stdc++.h>
using namespace std;


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
    int N;scanf("%d",&N);
    set<int>s;
    rep(i,N){
        int a;
        scanf("%d",&a);
        while(a%2==0)a/=2;
        while(a%3==0)a/=3;
        s.insert(a);
    }

    if(s.size()==1)puts("Yes");
    else puts("No");
    return 0;
}