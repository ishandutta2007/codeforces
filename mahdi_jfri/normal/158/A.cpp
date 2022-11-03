#include<iostream>
using namespace std;
int a[110];
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int x=0;
    k--;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=a[k] && a[i]>0)
            x++;
    }
    cout<<x;
}