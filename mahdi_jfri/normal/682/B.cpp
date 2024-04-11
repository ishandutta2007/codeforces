#include<iostream>
using namespace std;
long long a[100001],x=1;

void merge_(long long l,long long mid,long long r)
{

    long long z=0,c[100001];
    long long p1=l,p2=mid;
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
void mergesort(long long l,long long r)
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
int main()
{
    long long n,j=1;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    mergesort(0,n);
    for(int i=0;i<n;i++)
        if(a[i]>=j)
        a[i]=j++;
    cout<<j;
}