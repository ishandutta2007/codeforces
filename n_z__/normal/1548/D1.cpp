#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[101];
main(){
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    {
        int y,z;
        cin>>y>>z;
        s[(y&2)+((z>>1)&1)]++;
    }
    int ans=0;
	for(int x=3;x>=0;x--)
    ans+=s[x]*(s[x]-1)*((s[x]-2)+3*(n-s[x]))/6;
	cout<<ans<<endl;
}