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

signed main(){
    int n,x;cin>>n>>x;

    pair<int,int>st(x,n%2);
    map<pint,int>mem;
    mem[st]=0;
    int cur=0;
    while(true){
        if(st.se){
            if(st.fi<=1)st.fi=1-st.fi;
        }
        else{
            if(st.fi>=1)st.fi=3-st.fi;
        }
        st.se^=1;
        cur++;
        if(cur==n){
            n=0;
            break;
        }
        if(mem.find(st)==mem.end())mem[st]=cur;
        else{
            n-=mem[st];
            n%=(cur-mem[st]);
            break;
        }
    }
    rep(i,n){
        if(st.se){
            if(st.fi<=1)st.fi=1-st.fi;
        }
        else{
            if(st.fi>=1)st.fi=3-st.fi;
        }
        st.se^=1;
    }
    cout<<st.fi<<endl;
    return 0;
}