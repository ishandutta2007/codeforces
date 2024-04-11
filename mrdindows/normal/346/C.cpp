#include <bits/stdc++.h>
#define rep(x,n) for(int x=0;x<int(n);++x)
#define print(x) cout<<x<<endl
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define pv(x,y) {for(auto z=(x);z!=(y);z++)cerr<<*z<<" ";cerr<<endl;}
#define _ <<" , "<<
#define mp make_pair
#define x first
#define y second
using namespace std;
typedef pair<int,int> pt;

#define N (1<<20)

int f[N];
vector<vector<int>> process(N,vector<int>(32));
int x[111111], n;
int a,b;

int main() {
    if(true) cin.sync_with_stdio(false);
    cin>>n;
    rep(i,n)cin>>x[i];
    sort(x,x+n);
    n=unique(x,x+n)-x;
    reverse(x,x+n);
    cin>>a>>b;
    rep(i,N) process[i].resize(0);
    for(int i=0;i<n;i++) {
        int bb = b;
        if(bb%x[i]) bb -= bb%x[i], bb += x[i];
        if(bb<=a) process[bb-b].push_back(x[i]);
    }
    rep(i,N) f[i] = i;
    for(int pos=b,last=b;pos<=a;pos++) {
        int &at = f[pos-b];
        at = min(at, f[pos-b-1] + 1);
        for(int dx : process[pos-b]) {
            int ini=pos+1, fim=min(pos+dx,a+1); // [ini,fim)
            for(last=max(last,ini);last<fim;last++) {
                f[last-b] = at + 1;
            }
            if(pos+dx<=a) process[pos+dx-b].push_back(dx);
        }
        process[pos-b].clear();
    }
    cout<<(f[a-b])<<endl;
    return 0;
}