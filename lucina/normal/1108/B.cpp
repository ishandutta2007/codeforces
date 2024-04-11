#include<bits/stdc++.h>
using namespace std;
long long n,a[300];
bool vis[int(1e4+10)];
long long lcm(long long u,long long v){
    return u*v/(__gcd(u,v));
}
int main(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    long long x=a[n],y=1;
    for(int i=1;i<=n;i++){
        if(x%a[i]==0){
            if(!vis[a[i]]){
                vis[a[i]]=true;
            }
            else{
                y=a[i];
            }
        }
        else{
            y=a[i];
        }
    }
    printf("%lld %lld",x,y);
}
//10 2 8 1 2 4 1 20 4 5
//1 1 2 2 4 4 5 8 10 20
//20 8