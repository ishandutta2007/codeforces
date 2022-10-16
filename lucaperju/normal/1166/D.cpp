#include <bits/stdc++.h>

using namespace std;
unsigned long long v[55];
unsigned long long cat[55];
int main()
{
    unsigned long long q,a,b,m,i,j;
    cin>>q;
    while(q--)
    {
        cin>>a>>b>>m;
        --m;
        if(a==b)
        {
            cout<<1<<' '<<a<<'\n';
            continue;
        }
        unsigned long long lng;
        for(lng=2;lng<=50;++lng)
        {
            v[1]=a;
            for(i=2;i<=lng;++i)
            {
                unsigned long long s=1LL;
                for(j=1;j<=i-1;++j)
                {
                    if(b-s<v[j])
                    {
                        lng=53;
                        break;
                    }
                    s=s+v[j];
                }
                v[i]=s;
            }
            if(lng==53)
                break;
            unsigned long long dst=b-v[lng];
            unsigned long long pas=1LL<<(lng-3LL);
            if(lng==2)
                pas=1;
            for(i=2LL;i<=lng;++i)
            {
                cat[i]=min(dst/pas,m);
                dst-=cat[i]*1LL*pas;
                if(i!=lng-1LL)
                    pas>>=1LL;
            }
            if(dst==0)
            {
                v[1]=a;
                for(i=2;i<=lng;++i)
                {
                    unsigned long long s=cat[i]+1LL;
                    for(j=1;j<=i-1;++j)
                        s=s+v[j];
                    v[i]=s;
                }
                cout<<lng<<' ';
                for(i=1;i<=lng;++i)
                    cout<<v[i]<<' ';
                cout<<'\n';
                lng=52;
                break;
            }
        }
        if(lng==52)
            continue;
        else
        {
            cout<<-1<<'\n';
            continue;
        }
    }
    return 0;
}