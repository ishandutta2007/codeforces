#include <bits/stdc++.h>
using namespace std;
int ik[200003];
int val[200003],n;
int lsb(int x)
{
    return x&-x;
}
int get0s (int pz)
{
    if(ik[pz])
        return val[pz];
    cout<<"? "<<pz-lsb(pz)+1<<' '<<pz<<'\n';
    cout.flush();
    int a;
    cin>>a;
    a=lsb(pz)-a;
    ik[pz]=1;
    val[pz]=a;
    return a;
}
int query (int cnt)
{
    int sc=0,pzc=0,pas=1<<20;
    while(pas)
    {
        if(pzc+pas<=n)
        {
            if(sc+get0s(pzc+pas)<cnt)
            {
                pzc+=pas;
                sc+=get0s(pzc);
            }
        }
        pas>>=1;
    }
    return pzc+1;
}
void upd (int pz)
{
    for(int i=pz;i<=n;i+=lsb(i))
        if(ik[i])
            --val[i];
}
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>n>>t;
    while(t--)
    {
        int x;
        cin>>x;
        int pz=query(x);
        cout<<"! "<<pz<<'\n';
        cout.flush();
        upd(pz);
    }
}