#include<bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define rep(i,n) for(int i = 0;  i < n ; ++i)
#define REP(i,a,b) for(int i = a ; i <= b ; ++i)
#define s(n) scanf("%d",&n)
#define rev(i,n) for(int i = n ; i >= 0 ; --i)
#define REV(i,a,b) for(int i = a ; i >= b ; --i)
#define miN(a,b) (((a)<(b))?(a):(b))
#define sc(n) scanf("%c",&n)
#define tr(c,i) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define INF 1000000000
#define pii pair<long long int,long long int>
#define pb(a) push_back(a)
typedef long long ll;
using namespace std;
set<int>arr[3];
bool flag[200001]{1};
string ret;
string s;
ll n;
string re(){
    string ret;
    bool fla = false;
    rep(i,n){
        if(s[i]!='0' && flag[i]){
            fla=1;
        }
        if(flag[i] && fla){
            ret+=s[i];
        }
    }
    return ret;
}
void pre(){}
string check(int a,int b){
    vector<int>a1;
    if(a>arr[1].size() || b>arr[2].size()) return"";
    int j=0;
    for(auto i=arr[1].rbegin();j<a;i++){
        a1.push_back(*i);
        flag[*i]=0;
        j++;
    }
    j=0;
    for(auto i=arr[2].rbegin();j<b;i++){
        a1.push_back(*i);
        flag[*i]=0;
        j++;
    }
    string ret =  re();
    for(auto i:a1){
        flag[i]=1;
    }
    return ret;
}
void solve(){
    cin>>s;
    n = s.size();
    ll a=0;
    for(int i=0;i<=n;i++) flag[i]=1;
    rep(i,n){
        arr[(int(s[i])-'0')%3].insert(i);
        a+=int(s[i])-int('0');
    }
    string a1,b1;
    if(a%3==1){
        a1=check(1,0);
        b1=check(0,2);
        if(a1.size()<b1.size()){
            a1=b1;
        }
    }else if(a%3==2){
        a1=check(2,0);
        b1=check(0,1);
        if(a1.size()<b1.size()){
            a1=b1;
        }
    }else{
        a1=check(0,0);
    }
    if(a1.size()==0 && arr[0].size()>0){
        cout<<0<<"\n";
    }else if(a1.size()==0){
        cout<<-1<<"\n";
    }else{
        cout<<a1<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    //cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}