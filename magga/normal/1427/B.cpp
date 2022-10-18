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
void solve(){
    int n,k;cin>>n>>k;
    bool flag = 0;
    long long int points = 0;
    string s;cin>>s;
    multiset<int>ms;
    int start = 0;
    while(start<n && s[start]=='L')
        start++;
    if(start == n){
        cout<<max(2*k-1,0)<<"\n";
        return;
    }
    int end = n-1;
    while(end>=0 && s[end]=='L')
        end--;
    int a = start;
    int b = n-end-1;
    int count = 0;
    for(int i=start;i<=end;i++){
        if(s[i]=='W' && flag){
            points+=2;
        }else if(s[i]=='W' && !flag){
            flag=1;
            if(count!=0)
                ms.insert(count);
            count=0;
            points+=1;
        }
        if(s[i]=='L' && flag){
            flag = 0;
            count = 1;
        }else if(s[i]=='L' && !flag){
            count++;
        }
    }
    while(ms.size()>0 && k>0){
        int a = *ms.begin();
        //cout<<a<<" ";
        ms.erase(ms.find(a));
        if(k>=a){
            points++;
        }
        int b = min(a,k);
        points+=2*b;
        k-=b;
    }
    //cout<<"\n";
    a+=b;
    points+= min(2*k,2*a);
    cout<<points<<"\n";
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