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
int visited[100001]{0};
bool parity[100001]{0};
int succ[100001]{0};
int pred[100001]{0};
bool child[100001]{0};
vector<int>arr[100001];
vector<pair<ll,ll>>bd;
ll n,u,v,w,m;
bool draw = 0;
vector<int>path;
bool found = 0;
bool dfs(int i,int from){
    if(visited[i]!=0){
        if(parity[i]==parity[from]){
            bd.push_back({from,i});
        }
    }
    if(visited[i]==1){
        draw = 1;
        return false;
    }else if(visited[i]==2){
        return false;
    }
    visited[i] = 1;
    pred[i] = from;
    parity[i] = !parity[from];
    bool ret = 0;
    if(arr[i].size()==0){
        succ[i] = -1;
    }
    child[i] = (arr[i].size()==0);
    for(auto to:arr[i]){
        bool oo = (visited[to]==0);
        ret|=dfs(to,i);
        if(oo){
            if(child[to]){
                succ[i] = to;
            }
            child[i] |= child[to];
        }
    }
    if(!found){
        ret |= (arr[i].size()==0 && parity[i]);
        if(ret){
            found = 1;
        }
    }
    if(ret){
        path.push_back(i);
    }
    visited[i] = 2;
    return ret;
}
void pre(){}
void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>w;
        for(int j=0;j<w;j++){
            cin>>u;
            arr[i+1].push_back(u);
        }
    }
    ll si;cin>>si;
    parity[0] = 1;
    dfs(si,0);
    if(path.size()==0){
        for(auto i:bd){
            if(child[i.S]){
                vector<int>forward;
                int a = i.S ;
                while(a!=-1){
                    forward.push_back(a);
                    a = succ[a];
                } 
                vector<int>backward;
                a = i.F;
                while(a!=0){
                    backward.push_back(a);
                    a = pred[a];
                }
                reverse(backward.begin(),backward.end());
                for(auto i:backward){
                    path.pb(i);
                }
                for(auto i:forward){
                    path.pb(i);
                }
                reverse(path.begin(),path.end());
                break;
            }
        }
    }
    if(path.size()!=0){
        cout<<"Win"<<"\n";
        reverse(path.begin(),path.end());
        for(auto i:path){
            cout<<i<<" "; 
        }
        cout<<"\n";
    }else  if(draw){
        cout<<"Draw"<<"\n";
    }else{
        cout<<"Lose"<<"\n";
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