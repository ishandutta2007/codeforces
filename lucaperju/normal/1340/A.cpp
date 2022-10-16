#include <bits/stdc++.h>
using namespace std;
struct ura
{
    int val,pz;
}v[100005];
bool cmp (ura a, ura b)
{
    return a.val<b.val;
}
int ocp[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n+1;++i)
            ocp[i]=0;
        for(i=1;i<=n;++i)
        {
            cin>>v[i].val;
            v[i].pz=i;
        }
        sort(v+1,v+n+1,cmp);
        ocp[n+1]=1;
        int ok=1;
        for(i=1;i<=n;++i)
        {
            if(!ok)
            {
                if(v[i-1].pz!=v[i].pz-1)
                {
                    cout<<"NO\n";
                    break;
                }
            }
            else
                ok=0;
            ocp[v[i].pz]=1;
            if(ocp[v[i].pz+1])
                ok=1;
        }
        if(i==n+1)
        {
            cout<<"YES\n";
        }
    }
    return 0;
}