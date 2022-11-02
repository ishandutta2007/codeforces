#include<bits/stdc++.h>
using namespace std;
char a[250][250];
int n,i,j,s1,s2,co,con,f;
int b[250];
char c[250];
int main()
{
    cin>>n;
    for(i=0;i<2*n-2;i++)
    {
        scanf("%s",&a[i]);
    }
    j=0;
    for(i=0;i<2*n-2;i++)
    {
        j=0;
        while(a[i][j]!='\0')
        {
            j++;
        }
        if(j==n-1 && s1==0)
        {
            s1=i;
        }
        else if(j==n-1)
        {
            s2=i;
        }
    }
    for(i=1;i<n-1;i++)
    {
        if(a[s1][i] != a[s2][i-1])
        {
            co=1;
        }
    }
    if(co==0)
    {
        for(i=0;i<n-1;i++)
        {
            a[2*n-2][i]=a[s1][i];
        }
        a[2*n-2][n-1]=a[s2][n-2];
    }
    if(co==1)
    {
        for(i=0;i<n-1;i++)
        {
            a[2*n-2][i]=a[s2][i];
        }
        a[2*n-2][n-1]=a[s1][n-2];
    }
    for(i=0;i<2*n-2;i++)
    {
        j=0;
        while(a[i][j] != '\0')
        {
            if(a[i][j]!=a[2*n-2][j])
            {
                break;
            }
            j++;
        }
        f=j;
                j=0;
        while(a[i][j] != '\0')
        {
            j++;
        }
        if(a[i][f]=='\0' && b[j]!=1)
        {
            c[i]='P';
            b[j]=1;
        }
        else if(b[j]!=725)
        {
            c[i]='S';
            b[j]=725;
        }
        else
        {
co=2;
break;
        //cout<<"I'm a bug";
    }}
       // cout<<b[j]<<" "<<i<<" "<<j<<"\n";}
    if(co==2){
            for(i=0;i<n-1;i++)
        {
            a[2*n-2][i]=a[s2][i];
        }
        a[2*n-2][n-1]=a[s1][n-2];

    for(i=0;i<2*n-2;i++)
    {
        b[i]=0;
    }
    for(i=0;i<2*n-2;i++)
    {
        j=0;
        while(a[i][j] != '\0')
        {
            if(a[i][j]!=a[2*n-2][j])
            {
                break;
            }
            j++;
        }
        f=j;
                        j=0;
        while(a[i][j] != '\0')
        {
            j++;
        }
        if(a[i][f]=='\0' && b[j]!=1)
        {
            c[i]='P';
            b[j]=1;
        }
        else
        {
            c[i]='S';
            b[j]=725;
        }}
}
for(i=0;i<2*n-2;i++)
{
    cout<<c[i];
}
return 0;}