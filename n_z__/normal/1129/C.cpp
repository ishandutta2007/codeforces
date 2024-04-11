#include <bits/stdc++.h>
using namespace std;
int a[3001],c[10000001][2],p[10000001],dp[10000001],ans,m=1;
const int skc=1e9+7;
main(){
    int n;
    cin>>n;
    dp[0]=1,p[0]=-1;
    for(int x=1;x<=n;x++)
    {
        cin>>a[x];
        for(int y=x,z=0;y>=1;z=c[z][a[y]],y--)
        if(!c[z][a[y]]){
            for(int q=0,w=z,e=0;q<4&&w>=0;q++,w=p[w])
            {
                e=(e*2)|a[y+q];
                if(q<3||e!=3&&e!=5&&e<14)dp[m]+=dp[w],dp[m]%=skc;
            }
            ans+=dp[m];
            ans%=skc;
            p[m]=z;
            c[z][a[y]]=m;
            m++;
        }
        cout<<ans<<endl;
    }
}