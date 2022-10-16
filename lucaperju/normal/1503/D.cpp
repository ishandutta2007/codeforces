#include <bits/stdc++.h>
using namespace std;
int a[200003];
int b[200003];
int pz[400003];
int fol[200003];
int fa[200003],fb[200003];
int main()
{
    ios_base::sync_with_stdio(false);
    int t,n,d,i,j,m;
    long long s=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>a[i]>>b[i];
        pz[a[i]]=i;
        pz[b[i]]=i;
    }
    int cntc,sc;
    int cnt=0;
    int st=1,dr=n;
    int vst=0,vdr=n*2+1,lst=0,ldr=n*2+1;
    while(st<=dr)
    {
        ++vst;
        cntc=0;
        sc=0;
        while((lst<vst || vdr<ldr) && st<=dr)
        {
            while(lst<vst && st<=dr)
            {
                ++lst;
                if(fol[pz[lst]])
                    continue;
                ++cntc;
                fa[st]=lst;
                fb[st]=a[pz[lst]]+b[pz[lst]]-lst;
                if(a[pz[lst]]!=lst)
                    ++sc;
                fol[pz[lst]]=1;
                if(fb[st-1]<fb[st] && st>1)
                {
                    cout<<-1;
                    return 0;
                }
                vdr=fb[st];
                ++cnt;
                ++st;
            }
            while(vdr<ldr && st<=dr)
            {
                --ldr;
                if(fol[pz[ldr]])
                    continue;
                ++cntc;
                fa[dr]=ldr;
                fb[dr]=a[pz[ldr]]+b[pz[ldr]]-ldr;
                if(a[pz[ldr]]!=ldr)
                    ++sc;
                fol[pz[ldr]]=1;
                if(fb[dr+1]>fb[dr] && dr<n)
                {
                    cout<<-1;
                    return 0;
                }
                vst=fb[dr];
                ++cnt;
                --dr;
            }
        }
        s+=min(sc,cntc-sc);
    }
    for(i=2;i<=n;++i)
    {
        if(fa[i]<fa[i-1] || fb[i]>fb[i-1])
        {
            cout<<-1;
            return 0;
        }
    }
    cout<<s;
	return 0;
}