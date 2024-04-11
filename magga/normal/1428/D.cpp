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
    int n;cin>>n;
    stack<int>a[4];
    vector<pii>ans;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int j = 0;
    for(int i=n-1;i>=0;i--){
        if(arr[i]==0){
            continue;
        }else if(arr[i]==1){
            a[0].push(i);
            a[1].push(j);
            ans.push_back({i,j});
            j++;
        }else if(arr[i]==2){
            if(a[1].size()==0){
                cout<<-1<<"\n";
                return;
            }
            auto y = a[1].top();
            a[1].pop();
            a[0].pop();
            ans.push_back({i,y});
            a[2].push(i);
        }else{
            if(a[2].size()==0 && a[1].size()==0 && a[3].size()==0){
                cout<<-1<<"\n";
                return;
            }
            if(a[3].size()>0){
                auto y = a[3].top();
                a[3].pop();
                ans.push_back({i,j});
                ans.push_back({y,j});
                j++;
                a[3].push(i);
            }else if(a[2].size()>0){
                auto y = a[2].top();
                a[2].pop();
                ans.push_back({i,j});
                ans.push_back({y,j});
                j++;
                a[3].push(i);
            }else{
                auto y = a[0].top();
                a[0].pop();
                a[1].pop();
                ans.push_back({i,j});
                ans.push_back({y,j});
                j++;
                a[3].push(i);
            }
        }
    }
    cout<<ans.size()<<"\n";
    for(auto i:ans){
        cout<<n-i.S<<" "<<i.F+1<<"\n";
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