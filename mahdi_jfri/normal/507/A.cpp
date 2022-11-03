#include <iostream>
using namespace std;

int a[1005],b[1005];

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
int sortnum(int x,int n)
{
    for(int j=0;j<n;j++)
    {
        if(x==b[j])
        {
            b[j]=-1;
            return j;
        }
    }
}
int main()
{
    int n,k,c[1000];
    cin >> n >> k;
    for(int i=0;i<n;i++)
        {
            cin >> a[i];
            b[i]=a[i];
        }
    mergesort(0,n);
    int sum=0,j=0;
    for(;j<n;j++)
    {
        sum+=a[j];
        if(sum>k)
        {
            j--;
            break;
        }
        if(sum==k)
            {
                c[j]=1+sortnum(a[j],n);
                break;
            }
        c[j]=1+sortnum(a[j],n);
    }
    if(j==n)
    {cout<<n<<endl;}
    else cout<<++j<<endl;
    for(int i=0;i<j;i++)
        cout<<c[i]<<" ";
}