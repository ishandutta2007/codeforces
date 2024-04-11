#include<bits/stdc++.h>
#define MAXN 300100
using namespace std;
int n,a[MAXN],l[MAXN],r[MAXN];
int main()
{
    cin>>n;for (int i=1;i<=n;i++) cin>>a[i];int ans=0;
    for (int i=1;i<=n;i++)
        if(a[i]!=a[n]) {ans=max(ans,n-i);break;}
    for (int i=n;i;i--) if(a[i]!=a[1]) {ans=max(ans,i-1);break;}
	cout<<ans<<endl;
}