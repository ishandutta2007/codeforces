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

signed main(){
    int N;cin>>N;
    string S;
    cin>>S;
    S=S.substr(0,2)+S.substr(3,2);

    string ans;
    int num=1001001001;

    rep(i,100){
        rep(j,60){
            if(N==12){
                if(i<1||i>12)continue;
            }
            else{
                if(i>=24)continue;
            }
            stringstream ss,tt;
            ss<<i;
            tt<<j;
            string hoge,piyo;
            hoge=ss.str();piyo=tt.str();
            if(hoge.size()==1)hoge="0"+hoge;
            if(piyo.size()==1)piyo="0"+piyo;

            string s=hoge+piyo;
            int cnt=0;
            rep(k,4)if(s[k]!=S[k])cnt++;
            if(cnt<num){
                ans=s;
                num=cnt;
            }
        }
    }

    cout<<ans.substr(0,2)+":"+ans.substr(2,2)<<endl;
    return 0;
}