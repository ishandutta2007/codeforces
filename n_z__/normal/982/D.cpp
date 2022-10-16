#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<int,int>a[100001];
int l[100001],r[100001];
main(){
    int n;
    cin>>n;
    for(int x=1;x<=n;x++)
    cin>>a[x].first,a[x].second=x;
    memset(l,0,sizeof(l));
    memset(r,0,sizeof(r));
    sort(a+1,a+1+n);
    int ans=0;
    for(int x=1,q=0,w=0,e=0,g=0;x<=n;x++)
    {
        l[a[x].second+r[a[x].second]+1]=r[a[x].second-l[a[x].second]-1]=l[a[x].second]+r[a[x].second]+1;
        g+=1-(r[a[x].second]>0)-(l[a[x].second]>0);
        if(l[a[x].second]+r[a[x].second]+1>=q){
            if(l[a[x].second]+r[a[x].second]+1>q)q=l[a[x].second]+r[a[x].second]+1,e=0;
            e++;
            if(e>w&&e==g)w=e,ans=a[x].first+1;
        }
    }
    cout<<ans<<endl;
}