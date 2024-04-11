#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int v[200005];
char c[200005];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie();cout.tie();
    long long n,k,i,j,s=0,m,cnt=0,cur,t,cj;
    cin>>n>>k;
    for(i=1;i<=n;++i)
        cin>>v[i];
    cin>>(c+1);
    for(i=1;i<=n;)
    {
        for(j=i+1;c[j]==c[i];++j){}
        cj=j;
        sort(v+i,v+j);
        cnt=k;
        for(j--;j>=i && cnt>0;--j,--cnt)
            s+=v[j];
        i=cj;
    }
    cout<<s;
    return 0;
}