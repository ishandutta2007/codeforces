#include <iostream>
using namespace std;
void merge_(int *a,int l,int mid,int r)
{

    int z=0,c[105];
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
void mergesort(int *a,int l,int r)
{
    if(r-l==1)
    return ;
    else
    {
    int mid=(r+l)/2;
    mergesort(a,l,mid);
    mergesort(a,mid,r);
    merge_(a,l,mid,r);
    }
}
int main()
{
    int a[4];
    cin>>a[0]>>a[1]>>a[2]>>a[3];
    mergesort(a,0,4);
    if(a[0]+a[1]+a[2]<=a[3] && a[0]+a[1]<a[2])
        cout<<"IMPOSSIBLE";
    else
    {
        if(a[0]+a[1]>a[3]|| a[1]+a[2]>a[3] || a[0]+a[2]>a[3] || a[0]+a[1]>a[2])
            cout<<"TRIANGLE";
        else if(a[1]+a[2]==a[3]||a[0]+a[1]==a[2]) cout << "SEGMENT";
        else
            cout<<"IMPOSSIBLE";
    }
}