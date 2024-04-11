#include <iostream>
using namespace std;

int a[1005],d=0;

void merge_(int l,int mid,int r)
{

    int z=0,c[1005];
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
int main()
{
    int n,num1=0,num2=0,max2=1,t=0;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];
    mergesort(0,n);
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[i+1])
        {
            num1=1;
            while(a[i]==a[i+1])
            {
                num1++;
                i++;
            }
            num2+=num1;
            t++;
        }
        if(num1>max2)
            max2=num1;
    }
    cout << max2 << " " <<n-num2+t;
}