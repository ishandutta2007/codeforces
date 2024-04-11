#include<iostream>
#include<stdio.h>
using namespace std;
long long int m,n,l,h,f,k,o,p=1;
int i,g;
int j;
int main(){
    cin>>n>>m>>l;
    long long int a[n+1];
    int b[n+1];
    a[0]=0;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=m;i++)
    {
        cin>>h;
        if(h==1 && p>=2)
        {
            cin>>f>>k;
            if(a[f]+k>l)
            {
                if(a[f]<=l)
                {
                    if(f==1)
                {
                    if(b[2]==0)
                    {
                        a[0]++;
                        b[1]=1;
                    }
                }
                else if(f==n)
                {
                    if(b[n-1]==0)
                    {
                        a[0]++;
                        b[n]=1;
                    }
                }
                else
                {
                    if(b[f-1]==0 && b[f+1]==0)
                    {
                        a[0]++;
                    }
                    else if(b[f-1]==1 && b[f+1]==1)
                    {
                       a[0]--;
                    }
                    b[f]=1;
                }
                }
            }
            a[f]=a[f]+k;
        }
        else {if(h==1)
        {
            cin>>f>>k;
            a[f]=a[f]+k;
        }
        else
            {
            p++;
        if (p==2)
        {
            j=0;
            for(g=1;g<=n;g++)
            {
                if(a[g]>l)
                {
                    if(j==0)
                    {
                        j=1;
                    }
                    b[g]=1;
                }
                else
                {
                    if(j==1)
                    {
                        a[0]++;
                        j=0;
                    }
                    b[g]=0;
                }
            }
            if(j==1)
            {
                a[0]++;
            }
            cout<<a[0]<<"\n";
        }
        else
        {
            cout<<a[0]<<"\n";
        }
        }
        }
    }

}