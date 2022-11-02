#include<bits/stdc++.h>
using namespace std;
int n,i,counti,maxi,k,mim,j,lol;
int a[500000];
int main()
{
    cin>>n;
    lol=n;
    for(i=1;i<=lol;i++)
    {
        if(n%2==1)
        {
            a[i]=1;
            counti++;
            //cout<<n<<" ";
        }
        else
        {
            a[i]=0;
        }
        n=n/2;
        //cout<<n<<" ";
        if(n==0)
        {
            break;
        }
    }
    maxi=i;
    cin>>k;
    if(k>lol || k<counti)
    {
        cout<<"NO";
    }
    else
    {
        cout<<"YES\n";
    for(i=maxi;i>0;i--)
    {
        if(a[i]>0 && k>counti)
        {
            mim=k-counti;
            if(mim>a[i])
            {
                a[i-1]+=2*a[i];
                counti+=a[i];
                a[i]=0;
                //cout<<"I'm a bug"<<i<<" "<<a[i-1]<<"\n";
            }
            else
            {
                a[i]-=mim;
                a[i-1]+=2*mim;
                counti+=mim;
            }
        }
        else if(k==counti)
        {break;}
    }
    n=1;
    for(i=1;i<=maxi;i++)
    {
        if(a[i]>0)
        {
            for(j=1;j<=a[i];j++)
            {
                cout<<n<<" ";
            }
        }
        n*=2;
    }
    }
}