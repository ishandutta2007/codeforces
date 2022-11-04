#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, m, k;
pair<int, int> p[111];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d %d",&n,&k,&m);
        int l = k, r = k;
        for(int i=1;i<=m;i++){
            int a, b; scanf("%d %d",&a,&b);
            if((a <= l && l <= b) || (a <= r && r <= b)){
                l = min(l, a);
                r = max(r, b);
            }
        }
        printf("%d\n",r - l + 1);
    }
}