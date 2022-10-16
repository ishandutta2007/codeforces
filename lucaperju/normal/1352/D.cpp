#include <bits/stdc++.h>

using namespace std;
int v[1003];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long m,n,i,t,j,k,mx,p,mxx=0,a;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;++i)
            cin>>v[i];
        int sa=0,sb=0,prec=0;
        int pa=1,pb=n;
        int cnt=0;
        while(pa<=pb)
        {
            int sc=0;
            if(pa<=pb)
                ++cnt;
            while(pa<=pb && sc<=prec)
                sc+=v[pa++];
            sa+=sc;
            prec=sc;
            sc=0;
            if(pa<=pb)
                ++cnt;
            while(pa<=pb && sc<=prec)
                sc+=v[pb--];
            sb+=sc;
            prec=sc;
        }
        cout<<cnt<<' '<<sa<<' '<<sb<<'\n';
    }
    return 0;
}