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
    string s;
    cin>>s;
    int cur=0;
    while(cur<s.size()&&s[cur]=='a')cur++;
    if(cur==s.size()){
        s[s.size()-1]='z';
    }
    else{
        while(cur<s.size()){
            if(s[cur]=='a')break;
            s[cur]--;
            cur++;
        }
    }
    cout<<s<<endl;
    return 0;
}