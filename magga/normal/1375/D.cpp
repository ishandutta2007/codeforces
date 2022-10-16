#include<bits/stdc++.h>
#pragma GCC target ("avx2")
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
multiset<int>s;
ll mex(){
    int i = 0;
    while(true){
        if(s.find(i)==s.end()){
            return i;
        }
        i++;
    }
}
void solve(){
    ll n;cin>>n;
    ll arr[n];
    s.clear();
    for(int i=0;i<n;i++){
        cin>>arr[i];
        s.insert(arr[i]);
    }
    vector<int>ans;
    int end = n-1;
    int max = n;
    for(int i=0;i<2*n;i++){
        auto j = mex();
        if(max==0){
            break;
        }
        if(j!=max){
            ans.push_back(j);
            s.erase(s.find(arr[j]));
            arr[j]=j;
            s.insert(j);
        }else if(j==max){
            ans.push_back(end);
            s.erase(s.find(arr[end]));
            arr[end]=j;
            s.insert(j);
            end--;
            max--;
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i : ans){
        cout<<i+1<<" ";
    }
    cout<<"\n";
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