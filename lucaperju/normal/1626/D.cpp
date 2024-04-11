
#include <bits/stdc++.h>
using namespace std;
int fv[200003];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,k;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            fv[i]=0;
        for(i=1;i<=n;++i)
        {
            int a;
            cin>>a;
            ++fv[a];
        }
        int a,b;
        int ans=n+n+n;
        for(a=0;a<=20;++a)
            for(b=0;b<=20;++b)
            {
                int pa=(1<<a),rzc=0,sc=0,s1;
                for(i=1;i<=n;++i)
                {
                    if(sc+fv[i]>pa)
                        break;
                    else
                        sc+=fv[i];
                }
                s1=sc;
                rzc+=pa-sc;
                int pb=(1<<b);
                sc=0;
                for(;i<=n;++i)
                {
                    if(sc+fv[i]>pb)
                        break;
                    else
                        sc+=fv[i];
                }
                s1+=sc;
                rzc+=pb-sc;
                int ram=n-s1,c;
                for(c=0;c<=20;++c)
                {
                    if((1<<c)>=ram)
                        break;
                }
                rzc+=(1<<c)-ram;
                ans=min(ans,rzc);
            }
        cout<<ans<<'\n';
    }
    return 0;
}