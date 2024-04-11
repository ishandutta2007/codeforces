#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int par[505050],sz[505050],n,m;
int f(int a){
    if(par[a] == a) return a;
    return par[a] = f(par[a]);
}
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) par[i] = i;
    for(int i=1;i<=n;i++) sz[i] = 1;
    for(int i=1;i<=m;i++){
        int a,b,c=0; scanf("%d",&a);
        for(int j=1;j<=a;j++){
            scanf("%d",&b);
            if(c != 0){
                b = f(b);
                c = f(c);
                if(c != b){
                    par[b] = c;
                    sz[c] += sz[b];
                }
            }
            c = b;
        }
    }

    for(int i=1;i<=n;i++) printf("%d ",sz[f(i)]);
}