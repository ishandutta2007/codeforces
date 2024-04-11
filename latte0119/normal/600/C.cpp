#include<bits/stdc++.h>
using namespace std;

//#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

string S;
int cnt[26];

int main(){
    cin>>S;
    rep(i,S.size())cnt[S[i]-'a']++;

    rep(i,26){
        if((cnt[i]&1)==0)continue;
        for(int j=25;j>=0;j--)if(cnt[j]&1){
            cnt[i]++;
            cnt[j]--;
            break;
        }
    }
    int c;
    string ans;
    rep(i,26){
        if(cnt[i]&1)c=i;
        rep(j,cnt[i]/2)ans+=(char)(i+'a');
    }

    cout<<ans;
    if(S.size()&1)cout<<(char)(c+'a');
    reverse(all(ans));
    cout<<ans<<endl;
    return 0;
}