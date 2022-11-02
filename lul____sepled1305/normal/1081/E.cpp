#include<bits/stdc++.h>
using namespace std;
long long int n,i,j,y,use;
long long int a[100010];
long long int s[100010];
void mini(int p)
{
    j=sqrt(s[p]);
    //cout<<j<<"\n";
    use=0;
    while(2*j+1<=a[p+2])
    {
        j++;
        //cout<<"I'm a bug\n";
        //cout<<j<<"\n";
        for(y=j;y<=j+100000;y++)
        {
            if(y*y==j*j+a[p+2])
            {
                use=j*j-s[p];
                break;
            }
            else if(y*y>j*j+a[p+2])
            {
                break;
            }
        }
        if(use>0)
        {
            break;
        }
    }
    if(use!=0)
    {
        a[p+1]=use;
        s[p+1]=s[p]+a[p+1];
        s[p+2]=s[p+1]+a[p+2];
    }
    else
    {
        a[p+1]=0;
    }
    //cout<<".............................................\n";
}
int main()
{
    cin>>n;
    for(i=1;i<=n/2;i++)
    {
        scanf("%d",&a[2*i]);
    }
    s[0]=0;
    for(i=0;i<=n/2-1;i++)
    {
        mini(2*i);
    }
    for(i=1;i<=n;i++)
    {
        if(a[i]==0 ||a[i]>1e13)
        {
            use=0;
            break;
        }
        else if(i==n)
        {
            use=1;
        }
    }
    //cout<<a[1];
    if(use==0)
    {
        cout<<"No";
    }
    else
    {
        printf("Yes\n");
        for(i=1;i<=n;i++)
        {
            cout<<a[i]<<" ";
        }
    }
    return 0;
}