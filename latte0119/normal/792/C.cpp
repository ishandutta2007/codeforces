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

string s;
bool flag[111111];

signed main(){
    cin>>s;
    string ans;
    if(find(all(s),'0')!=s.end())ans="0";
    rep(x,3)rep(y,3){
        memset(flag,0,sizeof(flag));
        int c=0,d=0;
        for(int i=s.size()-1;i>=0;i--){
            int w=(s[i]-'0')%3;
            if(w==1&&c<x){
                flag[i]=true;
                c++;
            }
            if(w==2&&d<y){
                flag[i]=true;
                d++;
            }
        }
        for(int i=0;i<s.size();i++){
            if(flag[i])continue;
            if(s[i]=='0')flag[i]=1;
            else break;
        }
        string t;
        for(int i=0;i<s.size();i++)if(!flag[i])t+=s[i];

        int sum=0;
        rep(i,t.size())sum+=t[i]-'0';
        if(sum%3==0&&ans.size()<t.size())ans=t;
    }

    if(ans=="")cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}