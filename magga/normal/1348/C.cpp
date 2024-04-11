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
void pre(){}
int val(char c){
    return int(c)-'a';
}
void solve(){
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    map<char,int>arr;
    sort(s.begin(),s.end());
    if(s[0]!=s[k-1]){
        cout<<s[k-1]<<"\n";
        return;
    }
    for(auto i:s) arr[i]++;
    cout<<s[0];
    arr[s[0]]-=k;
    if(arr[s[0]]==0){
        arr.erase(s[0]);
    }
    bool flag = 1;
    for(auto i:arr){
        if(i.second%k!=0){
            flag = 0;
        }
    }
    if(arr.size()==1){
        for(auto j:arr){
            for(int i=0;i<((j.second+k-1)/k);i++){
                cout<<j.first;
            }
        }
        cout<<"\n";
    }else{
        cout<<s.substr(k)<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}