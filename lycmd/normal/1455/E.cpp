#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,ans,x[4],y[4],c[4];
signed main(){
	ios::sync_with_stdio(0);
	cin>>t;
    while(t--){
        for(int i=0;i<4;i++)
        	cin>>x[i]>>y[i],c[i]=i;
        ans=LLONG_MAX;
        do
            if(max(x[c[1]],x[c[3]])>=min(x[c[0]],x[c[2]])&&max(y[c[0]],y[c[1]])>=min(y[c[2]],y[c[3]]))
                ans=min(ans,abs(x[c[0]]-x[c[2]])+abs(x[c[1]]-x[c[3]])+abs(y[c[0]]-y[c[1]])+abs(y[c[2]]-y[c[3]])+2*max(0ll,max(min(x[c[1]],x[c[3]])-max(x[c[0]],x[c[2]]),min(y[c[0]],y[c[1]])-max(y[c[2]],y[c[3]]))-min(max(x[c[1]],x[c[3]])-min(x[c[0]],x[c[2]]),max(y[c[0]],y[c[1]])-min(y[c[2]],y[c[3]]))));
        while(next_permutation(c,c+4));
        cout<<ans<<"\n";
    }
}