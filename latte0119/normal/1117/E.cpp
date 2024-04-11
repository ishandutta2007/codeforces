#include<bits/stdc++.h>
using namespace std;


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
    string S;cin>>S;

    string T[3];
    rep(i,3){
        string q(S.size(),'a');
        rep(j,S.size()){
            int k=j;
            rep(l,i)k/=26;
            q[j]=k%26+'a';
        }
        cout<<"? "<<q<<endl;
        fflush(stdout);
        cin>>T[i];
    }

    string ans(S.size(),'a');
    rep(i,S.size()){
        int k=((T[2][i]-'a')*26+T[1][i]-'a')*26+T[0][i]-'a';
        ans[k]=S[i];
    }
    cout<<"! "<<ans<<endl;
}