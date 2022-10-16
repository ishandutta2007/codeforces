#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int v[200005],bst[400005];
int main()
{
    ios_base::sync_with_stdio(0);
    int n,m,i,j,k,s=0,t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        n*=2;
        for(i=1;i<=n;++i)
        {
            cin>>v[i];
            if(v[i]==2)
                v[i]=-1;
            bst[i]=bst[i+200001]=bst[-i+200001]=-1;
        }
        bst[200001]=n/2;
        s=200001;
        for(i=n;i>n/2;--i)
        {
            s+=v[i];
            bst[s]=i-n/2-1;
        }
        s=0;
        int mn=n/2+bst[200001];
        for(i=1;i<=n/2;++i)
        {
            s+=v[i];
            if(bst[-s+200001]!=-1)
            mn=min(mn,n/2-i+bst[-s+200001]);
        }
        cout<<mn<<'\n';
    }
    return 0;
}