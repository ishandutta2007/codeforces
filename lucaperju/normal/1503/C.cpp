#include <bits/stdc++.h>
using namespace std;
struct ura
{
    long long a,c,pz;
}v[100003];
bool cmp (ura a, ura b)
{
    return a.a<b.a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,d,i,j,m;
    long long s=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i].a>>v[i].c;
        v[i].pz=i;
        s+=v[i].c;
    }
    sort(v+1,v+n+1,cmp);
   // int ok=0;
    long long mxc=v[1].a;
    for(i=1;i<=n;++i)
    {
        if(v[i].a>mxc)
            s+=v[i].a-mxc;
        mxc=max(mxc,v[i].a+v[i].c);
    }
    cout<<s;
	return 0;
}