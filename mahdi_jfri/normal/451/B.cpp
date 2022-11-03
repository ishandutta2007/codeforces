#include <iostream>
#include <algorithm>
using namespace std;
int n;
bool check(int *a,int l,int r)
{
    if(l>0)
    if(a[r]<a[l-1])
        return 0;
    for(int i=0;i<l-1;i++)
        {
            if(a[i]>a[i+1])
                {return 0;}
        }
        for(int i=r;i>l;i--)
        {
            if(a[i]>a[i-1])
                {return 0;}
        }
        for(int i=r;i<n-2;i++)
        {
            if(a[i]>a[i+1])
                {return 0;}
        }
    if(r<n-1)
    if(a[l]>a[r+1])
        return 0;
    return 1;
}

int main()
{
    cin>>n;
    int a[100100];
    int i,y,x=1;
    for(i=1;i<=n;i++)
        cin>>a[i];
    for(i=1;i<n;i++)
        if(a[i]>a[i+1])
            {x=i; break;}
    for(i=x;i<n;i++)
        if(a[i]<a[i+1])
            {y=i; break;}
    if(i==n)
        y=n;
    reverse(a+x,a+y+1);
    for(i=1;i<n;i++)
        if(a[i]>a[i+1]) break;
    if(i!=n) cout<<"no";
    else
        cout<<"yes\n"<<x<<" "<<y;
}