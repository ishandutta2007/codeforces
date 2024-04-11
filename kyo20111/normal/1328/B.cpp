#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()
int t, n, k;
char s[100100];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) s[i] = 'a';
        s[n+1] = 0;

        int u = 1;
        while(u < k){
            k -= u;
            u++;
        }
        s[n-u] = 'b';
        u = n;
        k--;
        while(k) u--, k--;
        s[u] = 'b';

        printf("%s\n",s+1);
    }
}