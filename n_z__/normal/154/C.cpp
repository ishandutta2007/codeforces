#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000001],h[1000001];
main(){
    int n,m;
    cin>>n>>m;
	h[1]=1;
    for(int x=2;x<=n;x++)h[x]=h[x-1]*3;
    for(int x=1;x<=n;x++)a[n+x]=h[x];
	while(m--){
        int r,l;
        cin>>r>>l;
		a[l]+=h[r];
        a[r]+=h[l];
		a[r+n]+=h[l];
        a[l+n]+=h[r];
	}
	sort(a+1,a+2*n+1);
    int l=1,ans=0;
    for(int r=2;r<=2*n;ans+=r-l,r++)
	if(a[r]!=a[r-1])l=r;
	cout<<ans<<endl;
}