#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int pc(int x, ld p){
    return (int)(0.1+ceil((ld)x*p));
}

vector<int> g[101010];
int c[101010];
int ok[101010];
int ft[101010];

int n;

int test(ld x, int pr){
    queue<int> rem;
    for (int i=1;i<=n;i++){
        if (ft[i]==0){
            ok[i]=1;
            c[i]=0;
            for (int nx:g[i]){
                if (ft[nx]==0){
                    c[i]++;
                }
            }
            if (c[i]<pc(g[i].size(), x)){
                rem.push(i);
                ok[i]=0;
            }
        }
    }
    while (!rem.empty()){
        int xx=rem.front();
        rem.pop();
        for (int nx:g[xx]){
            if (ft[nx]==0){
                c[nx]--;
                if (ok[nx]==1&&c[nx]<pc(g[nx].size(), x)){
                    rem.push(nx);
                    ok[nx]=0;
                }
            }
        }
    }
    int f=0;
    for (int i=1;i<=n;i++){
        if (ok[i]){
            f++;
        }
    }
    if (pr){
        cout<<f<<endl;
        for (int i=1;i<=n;i++){
            if (ok[i]){
                cout<<i<<" ";
            }
        }
    }
    return f>0;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m,k;
    cin>>n>>m>>k;
    for (int i=0;i<k;i++){
        int a;
        cin>>a;
        ft[a]=1;
    }
    for (int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    ld mi=0;
    ld ma=1;
    for (int i=0;i<100;i++){
        ld mid=(mi+ma)/(ld)2;
        if (test(mid, 0)){
            mi=mid;
        }
        else{
            ma=mid;
        }
    }
    test(ma-1e-10, 1);
}