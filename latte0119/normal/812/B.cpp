#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

int N,M;

signed main(){
    cin>>N>>M;
    vector<string>S(N);
    rep(i,N)cin>>S[i];
    reverse(all(S));
    while(S.size()&&count(all(S[S.size()-1]),'1')==0)S.pop_back();

    int l=0,r=INT_MAX;

    for(int t=0;t<S.size();t++){
        string s=S[t];
        int ll=r+M+1;
        int rr=l+M+1;

        int pos=0;
        rep(i,s.size())if(s[i]=='1')pos=i;
        chmin(ll,l+pos*2);

        if(t+1==S.size())chmin(ll,l+pos);

        pos=M+1;
        for(int i=s.size()-1;i>=0;i--)if(s[i]=='1')pos=i;
        chmin(rr,r+(M+1-pos)*2);

        if(t+1==S.size())chmin(rr,r+M+1-pos);

        l=ll;r=rr;
        if(t+1!=S.size()){
            l++;r++;
        }
    }

    cout<<min(l,r)<<endl;
    return 0;
}