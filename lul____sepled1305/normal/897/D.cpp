#include<bits/stdc++.h>
using namespace std;
int a,b,c,m,n,i,j,k,number;
int napkin[1500];

int main()
{
    cin>>n>>m>>c;
    for(i=1;i<=m;i++)
    {
        cin>>a;
        if(a<=c/2)
        {
            for(j=1;j<=n;j++)
            {
                if(napkin[j]>a)
                {
                    napkin[j]=a;
                    break;
                } else if (napkin[j]==0)
                {
                    napkin[j]=a;
                    number++;
                    break;
                }
            }
            printf("%d\n",j);
            fflush(stdout);
        }
        else
        {
            for(j=1;j<=n;j++)
            {
                if(napkin[n+1-j]<a && napkin[n+1-j]!=0)
                {
                    napkin[n+1-j]=a;
                    break;
                } else if (napkin[n+1-j]==0)
                {
                    napkin[n+1-j]=a;
                    number++;
                    break;
                }
            }
            j=n+1-j;
            printf("%d\n",j);
            fflush(stdout);
        }
        if(number==n)
        {
            break;
        }
    }
}