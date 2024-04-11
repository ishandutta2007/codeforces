#include<bits/stdc++.h>
using namespace std;
const int N=100005;
typedef long long ll;
int n,m;
int a[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    ll ans=0,j=0;
    for(int i=1;i<n;i++){
        if(a[i]>j) j++;
        ans+=a[i]-1;
    }
    cout<<ans+(j==a[n]?j-1:j);
    return 0;
}