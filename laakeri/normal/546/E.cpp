#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

vector<int> g[404];
int f[404][404];
int fr[404];
int used[404];

int inf=1e6;

int a[101];
int b[101];

int s=401;
int t=402;

int out[101];

int flow(){
    queue<pair<pair<int, int>, int> > bfs;
    bfs.push({{0, s}, 1e9});
    int fl=0;
    while (!bfs.empty()){
        auto x=bfs.front();
        bfs.pop();
        if (used[x.F.S]==0){
            used[x.F.S]=1;
            fr[x.F.S]=x.F.F;
            if (x.F.S==t){
                fl=x.S;
            }
            for (int nx:g[x.F.S]){
                if (f[x.F.S][nx]>0){
                    bfs.push({{x.F.S, nx}, min(x.S, f[x.F.S][nx])});
                }
            }
        }
    }
    for (int i=1;i<=t;i++) used[i]=0;
    if (fl>0){
        int x=t;
        while (x>1){
            f[x][fr[x]]+=fl;
            f[fr[x]][x]-=fl;
            x=fr[x];
        }
        return fl;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    int s1=0;
    int s2=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        s1+=a[i];
    }
    for (int i=1;i<=n;i++){
        cin>>b[i];
        s2+=b[i];
    }
    if (s1!=s2){
        cout<<"NO"<<endl;
        return 0;
    }
    int so=0;
    for (int i=1;i<=n;i++){
        if (a[i]>b[i]){
            g[s].push_back(i*2);
            g[i*2].push_back(s);
            f[s][i*2]=a[i]-b[i];
            so+=a[i]-b[i];
        }
        if (a[i]<b[i]){
            g[i*2].push_back(t);
            g[t].push_back(i*2);
            f[i*2][t]=b[i]-a[i];
        }
        g[i*2].push_back(i*2+1);
        g[i*2+1].push_back(i*2);
        f[i*2][i*2+1]=a[i];
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a*2+1].push_back(b*2);
        g[b*2].push_back(a*2+1);
        g[b*2+1].push_back(a*2);
        g[a*2].push_back(b*2+1);
        f[a*2+1][b*2]=inf;
        f[b*2+1][a*2]=inf;
    }
    int v=0;
    while (1){
        int asd=flow();
        if (asd==0){
            break;
        }
        v+=asd;
    }
    if (v==so){
        cout<<"YES"<<endl;
        for (int i=1;i<=n;i++){
            for (int ii=1;ii<=n;ii++){
                if (i!=ii){
                    out[i]+=f[ii*2][i*2+1];
                }
            }
        }
        for (int i=1;i<=n;i++){
            for (int ii=1;ii<=n;ii++){
                if (i!=ii){
                    cout<<f[ii*2][i*2+1]<<" ";
                }
                else{
                    cout<<a[i]-out[i]<<" ";
                }
            }
            cout<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
    }
}