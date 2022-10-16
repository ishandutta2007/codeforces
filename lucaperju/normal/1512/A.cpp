#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int a,pz;
};
ura v[103];
bool cmp (ura a, ura b)
{
    return a.a<b.a;
}
int main()
{
    ios_base::sync_with_stdio(false);
    long long i,t,n,p;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
        {
            cin>>v[i].a;
            v[i].pz=i;
        }
        sort(v+1,v+n+1,cmp);
        if(v[1].a!=v[2].a)
            cout<<v[1].pz<<'\n';
        else
            cout<<v[n].pz<<'\n';
    }
	return 0;
}