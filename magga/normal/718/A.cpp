#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define filei freopen("input.txt", "r", stdin);
#define fileo freopen("output.txt", "w", stdout);
#define gooi cout<<"Case #"<<i+1<<" :";
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
#define F first
#define S second
typedef long long ll;
using namespace std;
void pre(){}
string add(string a){
    string ret = '0' + a;
    for(int i = a.size();i>=0;i--){
        if(ret[i]=='9'){
            ret[i] = '0';
        }else{
            ret[i]++;
            break;
        }
    }
    if(ret[0]=='0'){
        ret = ret.substr(1);
    }
    return ret;
}
void solve(){
    ll n,t;cin>>n>>t;
    string s;cin>>s;
    string og = s;
    string fo,de;
    bool flag = false;
    for(auto i:s){
        if(i=='.'){
            flag = 1;
        }else if(flag){
            de += i;
        }else{
            fo+=i;
        }
    }
    s = "0" + de;
    int oo = -1;
    for(int i=0;i<s.size();i++){
        if( (s[i] - '0')<5 ){
            continue;
        }
        oo = i - 1;
        for(int j = i;j<s.size();j++){
            s[j] = '0';
        }
        s[oo]++;
    }
    if(oo==-1){
        cout<<og<<"\n";
        return;
    }
    t--;
    for(int i=oo;i>0;i--){
        if(t==0){
            break;
        }
        if(s[i]=='5'){
            s[i] = '0';
            s[i-1]++;
            t--;
        }else{
            break;
        }
    }
    if(s[0]=='1'){
        cout<<add(fo)<<"\n";
    }else{
        string ans = fo + '.';
        while(s.back()=='0'){
            s.pop_back();
        }
        ans += s.substr(1);
        cout<<ans<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}