#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
using ll = long long;
int n,m, x[maxn];
ll pre[maxn] , f[maxn];


int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d",&x[i]);
    }
    for(int i=1;i< m; i++){
        if(x[i] == x[i+1])continue;
        bool sw = false;
        if(x[i] > x[i+1]){
            swap(x[i] , x[i+1]);
            sw = true;
        }
        int val = abs(x[i+1] - x[i]);

        pre[1] += val;
        pre[x[i]] -= val;

        pre[x[i+1] + 1] += (val );

        f[x[i]] += x[i+1] - 1;
        f[x[i+1]] += x[i] ;

        pre[x[i] + 1] += val - 1;
        pre[x[i+1]] -= val -1;

        if(sw)
            swap(x[i] , x[i+1]);
    }
    for(int i=1;i<=n;i++){
        pre[i] += pre[i-1];
        printf("%lld ",f[i] + pre[i]);
    }
}