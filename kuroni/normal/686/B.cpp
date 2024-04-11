#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,k,a[100],temp;
    cin>>n;
    for (i=0;i<n;i++)
        {
            cin>>a[i];
        }
    for (i=0;i<n-1;i++) for (k=0;k<n-1;k++) if (a[k]>a[k+1])
    {
        cout<<k+1<<" "<<k+2<<endl;
        temp=a[k];
        a[k]=a[k+1];
        a[k+1]=temp;
    }
    return 0;
}