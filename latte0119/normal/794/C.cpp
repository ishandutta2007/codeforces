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

signed main(){
    string S,T;
    cin>>S>>T;
    deque<char>s,t;
    rep(i,S.size())s.pb(S[i]);
    rep(i,T.size())t.pb(T[i]);
    sort(all(s));
    sort(all(t));

    int N=S.size();
    while(s.size()>(N+1)/2)s.pop_back();
    while(t.size()>N/2)t.pop_front();

    string ans(S.size(),'?');
    int l=0;
    int r=N-1;
    for(int i=0;i<N;i++){
        if(i%2==0){
            if(s.front()<t.back()){
                ans[l++]=s.front();
                s.pop_front();
            }
            else{
                ans[r--]=s.back();
                s.pop_back();
            }
        }
        else{
            if(s.front()<t.back()){
                ans[l++]=t.back();
                t.pop_back();
            }
            else{
                ans[r--]=t.front();
                t.pop_front();
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}