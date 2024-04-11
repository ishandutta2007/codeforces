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

int B=400;

string S,T;
int N;
int A[222222];

bool used[222222];

bool ok(string &s){
    int cur=0;
    rep(i,s.size()){
        if(cur<T.size()&&T[cur]==s[i])cur++;
    }
    return cur==T.size();
}

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>S>>T;

    if(!ok(S)){
        cout<<0<<endl;
        return 0;
    }

    N=S.size();
    rep(i,N)cin>>A[i],A[i]--;

    int idx;
    for(int i=0;;i++){
        for(int j=0;j<B&&i*B+j<N;j++)used[A[i*B+j]]=1;
        string s;
        for(int j=0;j<N;j++)if(!used[j])s+=S[j];
        if(ok(s))continue;
        for(int j=0;j<B&&i*B+j<N;j++)used[A[i*B+j]]=0;
        idx=i*B;break;
    }

    while(true){
        used[A[idx]]=1;
        string s;
        for(int j=0;j<N;j++)if(!used[j])s+=S[j];
        if(ok(s)){
            idx++;
            continue;
        }
        cout<<idx<<endl;
        return 0;
    }
    return 0;
}