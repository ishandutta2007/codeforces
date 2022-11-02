#include<bits/stdc++.h>
using namespace std;
long long int i,j,k,n,l,o,p,maxi=0,running,poin=1,poout=1,gg=1;
long long int aa[300000];
long long int a[300000];
int main()
{
    cin>>n;
    aa[0]=-9999;
    aa[n+1]=-15;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        aa[i]=a[i];
    }
    sort(aa+1,aa+n+1);
    for(i=1;i<=n+1;i++)
    {
        if(aa[i]==aa[i-1])
        {
            running++;
            l++;
            //cout<<"YAAAAAAAAY";
        }
        else
        {
            if(running+1>maxi)
            {
                maxi=running+1;
                if(i>1)
                {
                    p=aa[i-1];
                }
                else p=a[1];
            }
            running=0;
        }
    }
    //cout<<maxi;
    //cout<<p;
    /*if(a[1]==23979)
    {
        cout<<l;
    }*/
    cout<<n-maxi<<"\n";
    while(gg<=maxi)
    {
        //cout<<"INTHELOOOPPPPP";
        if(a[poin]==p && poout < poin && a[poout]!=p)
        {
            for(i=1;i<=poin-poout;i++)
            {
                if(a[poin-i]<p)
                cout<<1<<" "<<poin-i<<" "<<poin-i+1<<"\n";
                else
                cout<<2<<" "<<poin-i<<" "<<poin-i+1<<"\n";
            }
            poout=poin;
        }
        else if (a[poin]!=p)
        {
            poin++;
        }
        else if(poout==poin)
        {
            poin++;
            gg++;
            //cout<<"FUCK IPST";
        }
        else if(a[poout]==p)
        {
            poout++;
        }
    }
    if(poin-1 != n)
    {
        //cout<<"atleast we got here\n"<<p<<"\n";
        for(i=0;i<=n-poin;i++)
        {
            if(a[poin+i]<p)
            {
                cout<<1<<" "<<poin+i<<" "<<poin+i-1<<"\n";
            }
            else
                cout<<2<<" "<<poin+i<<" "<<poin+i-1<<"\n";
        }
    }
    return 0;
}