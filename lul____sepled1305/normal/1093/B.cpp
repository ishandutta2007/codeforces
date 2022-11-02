#include<bits/stdc++.h>
using namespace std;
int n,j,i,che,h,p;
char a[1005];
char beg;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=1004;j++)
        {
            a[j]='A';
        }
        //cout<<a[0];
        scanf("%s",a);
        j=1;
        che=0;
        h=0;
        beg=a[0];
        while(a[j]!='A')
        {
            h++;
            j++;
        }
        //cout<<"I'm not a bug";
        j=0;
        //cout<<a[0]<<"\n";
        while(a[j]!='\0')
        {
            if(a[j]==beg){}
            else
            {
                che=1;
                a[h]=a[j];
                p=j;
                break;
            }
            j++;
            //cout<<"I'm not a bug\n";
        }
        if(che==0)
        {
            printf("-1\n");
        }
        else
        {
            for(j=0;j<=h;j++)
            {
                if(j!=p)
                {
                    printf("%c",a[j]);
                }
            }
            cout<<"\n";
        }
    }
    return 0;
}