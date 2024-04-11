#include <bits/stdc++.h>
using namespace std;
#define int long long
const int z=1e6+5;
int aa[z];
signed main(){
    int n,m,c;
    cin>>n>>c;
    while(n--){
        int u,v,w;
        cin>>u>>v>>w;
        aa[u]=max(aa[u],v*w);
    }
    for(int i=1;i<z;i++){
        int ee=2;
        for(int j=i*2;j<z;j+=i)aa[j]=max(aa[j],aa[i]*ee++);
    }
    for(int i=1;i<z;i++)aa[i]=max(aa[i],aa[i-1]);
    cin>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        int oo=a*b,l=0,r=c+1;
        while(l+1<r){
            int mid=(l+r)>>1;
            if(aa[mid]>oo)r=mid;
            else l=mid;
        }
        cout<<(r==c+1?-1:r)<<" ";
    }
}