#include <bits/stdc++.h>
using namespace std;
long long d[12],dn[12],bst[4][4];
int main ()
{
    long long n,m,ta,tb,k=0,i,j,nrc=0,nrd=0,s=0,t;
    cin>>n;
    for(i=1;i<=9;++i)
        d[i]=-999999999999999LL;
    for(k=1;k<=n;++k)
    {
        cin>>m;
        bst[1][1]=bst[1][2]=bst[1][3]=bst[2][1]=bst[3][1]=0;
        for(i=1;i<=m;++i)
        {
            long long c,a;
            cin>>c>>a;
            if(c>=2)
                bst[c][1]=max(bst[c][1],a);
            else
            {
                if(bst[1][1]<=bst[1][2] && bst[1][1]<=bst[1][3])
                    bst[1][1]=max(bst[1][1],a);
                else
                if(bst[1][1]>=bst[1][2] && bst[1][2]<=bst[1][3])
                    bst[1][2]=max(bst[1][2],a);
                else
                if(bst[1][3]<=bst[1][2] && bst[1][1]>=bst[1][3])
                    bst[1][3]=max(bst[1][3],a);
            }
        }
        if(bst[1][1]<bst[1][2])
            swap(bst[1][1],bst[1][2]);
        if(bst[1][2]<bst[1][3])
            swap(bst[1][2],bst[1][3]);
        if(bst[1][1]<bst[1][2])
            swap(bst[1][1],bst[1][2]);
        if(bst[1][2]<bst[1][3])
            swap(bst[1][2],bst[1][3]);
        if(bst[1][1]<bst[1][3])
            swap(bst[1][1],bst[1][3]);
        for(i=1;i<=10;++i)
        {
            long long mx=d[i];
            if(i!=10)
            {
                mx=max(mx,d[i-1]+max(max(bst[1][1],bst[2][1]),bst[3][1]));
                if(i-2<0)
                    i+=10;
                if(i!=11)
                {
                    if(bst[1][1] && bst[1][2])
                        mx=max(mx,d[i-2]+bst[1][1]+bst[1][2]);
                    if(bst[2][1] && bst[1][1])
                        mx=max(mx,d[i-2]+bst[2][1]+bst[1][1]);
                }
                else
                {
                    if(bst[1][1] && bst[1][2])
                        mx=max(mx,d[i-2]+bst[1][1]+bst[1][2]+max(bst[1][1],bst[1][2]));
                    if(bst[1][1] && bst[2][1])
                        mx=max(mx,d[i-2]+bst[2][1]+bst[1][1]+max(bst[2][1],bst[1][1]));
                }
             ///   mx=max(mx,d[i-2]+max(bst[1][1]+bst[1][2],bst[2][1]+bst[1][1]));
                if(i-3<0)
                    i+=10;
                if(i!=11 && i!=12)
                {
                    if(bst[1][3])
                        mx=max(mx,d[i-3]+bst[1][1]+bst[1][2]+bst[1][3]);
                }
                else
                {
                    if(bst[1][3])
                        mx=max(mx,d[i-3]+bst[1][1]+bst[1][2]+bst[1][3]+bst[1][1]);
                }
                if(i>10)
                    i-=10;
            }
            else
            {
                mx=max(mx,d[i-1]+2LL*max(max(bst[1][1],bst[2][1]),bst[3][1]));
                if(bst[1][1] && bst[1][2])
                    mx=max(mx,d[i-2]+bst[1][1]+bst[1][2]+max(bst[1][1],bst[1][2]));
                if(bst[1][1] && bst[2][1])
                    mx=max(mx,d[i-2]+bst[2][1]+bst[1][1]+max(bst[2][1],bst[1][1]));
            ///    mx=max(mx,d[i-2]+max(bst[1][1]+bst[1][2]+max(bst[1][1],bst[1][2]),bst[2][1]+bst[1][1]+max(bst[2][1],bst[1][1])));
                if(bst[1][3])
                    mx=max(mx,d[i-3]+bst[1][1]+bst[1][2]+bst[1][3]+bst[1][1]);
            }
            dn[i]=mx;
        }
        for(i=1;i<=10;++i)
            d[i]=dn[i];
        d[0]=dn[10];
    }
    long long mx=0;
    for(i=1;i<=10;++i)
        mx=max(mx,d[i]);
    cout<<mx;
    return 0;
}