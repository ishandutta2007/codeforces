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
    ll n,m;cin>>n>>m;
    string brr[n];
    bool arr[n][m];
    pair<int,int>val[n+1][m+1];
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++){
            val[i][j] = {i,j};
            if(i==n){
                val[i][j].F-=2;
            }
            if(j==m){
                val[i][j].S-=2;
            }
        }
    for(int i=0;i<n;i++)
        cin>>brr[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(brr[i][j]=='1'){
                arr[i][j]=1;
            }else{
                arr[i][j]=0;
            }
        }
    }
    vector<pair<int,int>>ans;
    for(int j=0;j<m-2;j++){
        for(int i=0;i<n;i++){
            if(arr[i][j]==0){
                continue;
            }
            ans.push_back(val[i][j]); //a
            ans.push_back(val[i][j+1]); //c
            ans.push_back(val[i+1][j+1]); //d
            arr[val[i][j].F][val[i][j].S] = !arr[val[i][j].F][val[i][j].S]; // a flip
            arr[val[i][j+1].F][val[i][j+1].S] = !arr[val[i][j+1].F][val[i][j+1].S]; //c flip
            arr[val[i+1][j+1].F][val[i+1][j+1].S] = !arr[val[i+1][j+1].F][val[i+1][j+1].S]; // d flip
            // arr[val[i+1][j].F][val[i+1][j].S] = !arr[val[i+1][j].F][val[i+1][j].S]; // b flip
            // arr[val[i][j].F][val[i][j].S] = !arr[val[i][j].F][val[i][j].S]; // a flip
        }

    }
    for(int i=0;i<n-2;i++){
        int j = m-2;
        if(arr[i][m-2]==0 && arr[i][m-1]==0){
            //cout<<i<<"a\n";
            continue;
        }else if(arr[i][m-2]==1 && arr[i][m-1]==0){
            //cout<<i<<"b\n";
            ans.push_back(val[i][j]); //a
            ans.push_back(val[i+1][j+1]); //d
            ans.push_back(val[i+1][j]); //b
            arr[val[i][j].F][val[i][j].S] = !arr[val[i][j].F][val[i][j].S]; // a flip
            arr[val[i+1][j].F][val[i+1][j].S] = !arr[val[i+1][j].F][val[i+1][j].S]; // b flip
            arr[val[i+1][j+1].F][val[i+1][j+1].S] = !arr[val[i+1][j+1].F][val[i+1][j+1].S]; // d flip
        }else if(arr[i][m-2]==0 && arr[i][m-1]==1){
            //cout<<i<<"c\n";
            ans.push_back(val[i][j+1]); //c
            ans.push_back(val[i+1][j+1]); //d
            ans.push_back(val[i+1][j]); //b
            arr[val[i][j+1].F][val[i][j+1].S] = !arr[val[i][j+1].F][val[i][j+1].S]; //c flip
            arr[val[i+1][j].F][val[i+1][j].S] = !arr[val[i+1][j].F][val[i+1][j].S]; // b flip
            arr[val[i+1][j+1].F][val[i+1][j+1].S] = !arr[val[i+1][j+1].F][val[i+1][j+1].S]; // d flip
        }else if(arr[i][m-2]==1 && arr[i][m-1]==1){
            //cout<<i<<"d\n";
            ans.push_back(val[i][j]); //a
            ans.push_back(val[i][j+1]); //c
            ans.push_back(val[i+1][j+1]); //d
            arr[val[i][j].F][val[i][j].S] = !arr[val[i][j].F][val[i][j].S]; // a flip
            arr[val[i][j+1].F][val[i][j+1].S] = !arr[val[i][j+1].F][val[i][j+1].S]; //c flip
            arr[val[i+1][j+1].F][val[i+1][j+1].S] = !arr[val[i+1][j+1].F][val[i+1][j+1].S]; // d flip
        }
    }
    vector<pii>on;
    vector<pii>off;
    for(int i=n-2;i<n;i++){
        for(int j=m-2;j<m;j++){
            if(arr[i][j]){
                on.push_back(val[i][j]);
            }else{
                off.push_back(val[i][j]);
            }
        }
    }
    
    if(on.size()==3){
        for(auto i:on){
            ans.push_back(i);
        }
        on.clear();
    }else if(on.size()==4){
        for(int i=3;i>0;i--){
            off.push_back(on[i]);
            ans.push_back(on[i]);
            on.pop_back();
        }
    }else if(on.size()==2){
        for(auto i:on){
            ans.push_back(i);
        }
        ans.push_back(off[0]);
        on.push_back(off.back());
        off.pop_back();
        auto i = on;
        on = off;
        off = i;
    }
    if(on.size()==1){
        ans.push_back(on[0]);
        ans.push_back(off[1]);
        ans.push_back(off[2]);

        ans.push_back(on[0]);
        ans.push_back(off[0]);
        ans.push_back(off[2]);

        ans.push_back(on[0]);
        ans.push_back(off[0]);
        ans.push_back(off[1]);
    }
    cout<<ans.size()/3<<"\n";
    for(int i=0;i<ans.size();i+=3){
        for(int j=0;j<3;j++){
            cout<<ans[i+j].F+1<<" "<<ans[i+j].S+1<<" ";
        }
        cout<<"\n";
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