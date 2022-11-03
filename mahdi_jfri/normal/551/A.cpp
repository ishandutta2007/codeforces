#include <iostream>
using namespace std;

int a[2001],b[2001];

void merge_(int l,int mid,int r)
{

    int z=0,c[2001];
    int p1=l,p2=mid;
    while(p1<mid && p2<r)
    {
        if(a[p1]>a[p2])
            {
                c[z++]=a[p2++];
            }
        else
        {
            c[z++]=a[p1++];
        }
    }
    for(;p1<mid;p1++)
        {
            c[z++]=a[p1];
        }
    for(;p2<r;p2++)
        {
            c[z++]=a[p2];
        }
    for(int j=0;j<r+l && l<r ;j++)
            {
                a[l++]=c[j];
            }
}
void mergesort(int l,int r)
{
    if(r-l==1)
    return ;
    else
    {
    int mid=(r+l)/2;
    mergesort(l,mid);
    mergesort(mid,r);
    merge_(l,mid,r);
    }
}

void sortnum(int n)
{
    for(int i=n-1;i>-1;i--)
    {
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
                {
                    b[j]=n-i+2001;
                }
        }
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
    mergesort(0,n);
    sortnum(n);
    for(int i=0;i<n;i++)
        cout<<b[i]-2001<<" ";
}