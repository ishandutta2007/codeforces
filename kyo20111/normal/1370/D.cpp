#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, k, a[200200];
int main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);

    int l = 1, r = 1e9;
    while(l <= r){
        int m = (l + r) >> 1, f = 0;
        int c = 0, d = 0;
        for(int u=1;u+c<=n;u+=2){
            while(u+c <= n && a[u+c] > m) c++;
        }
        if(c <= n-k) f = 1;

        c = 0, d = 0;
        for(int u=2;u+c<=n;u+=2){
            while(u+c <= n && a[u+c] > m) c++;
        }
        if(c <= n-k) f = 1;

        if(f) r = m - 1;
        else l = m + 1;
    }
    printf("%d",l);
}