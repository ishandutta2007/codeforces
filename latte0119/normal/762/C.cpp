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
#define fi first
#define se second
template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

void calc(string &S,string &T,vint &v,string &s){
    v.resize(T.size()+1);
    v[0]=0;
    int cur=0;
    rep(i,T.size()){
        while(cur<S.size()&&S[cur]!=T[i])cur++;
        v[i+1]=cur+1;
        if(cur<S.size())s+=S[cur];
        cur++;
    }
}

signed main(){
    string S,T;
    cin>>S>>T;

    vint pre,suf;
    string s,t;
    calc(S,T,pre,s);
    reverse(all(S));reverse(all(T));
    calc(S,T,suf,t);
    reverse(all(t));

    int cur=suf.size()-1;
    int ans=LLONG_MIN,mav=-1;
    for(int i=0;i<pre.size();i++){
        while(cur>=0&&(pre[i]+suf[cur]>S.size()||i+cur>T.size()))cur--;
        if(cur==-1)break;
        if(ans<i+cur){
            mav=i;
            ans=i+cur;
        }
    }

    if(ans==0)cout<<"-"<<endl;
    else cout<<s.substr(0,mav)<<t.substr(t.size()-(ans-mav),ans-mav)<<endl;
    return 0;
}