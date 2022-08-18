#include <iostream>

using namespace std;

int main()
{
    int k,n,s=0;
    cin>>n>>k;
    int* a = new int[n+1];
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        if (a[i]<=0 && s<1) s=i;
    }
    if (k>=s && s>0) cout<<s-1;
    else 
    { 
        for (int i=k;i<=n;i++)
            if (a[i]<a[k])
            {
                cout <<i-1;
                break;
            }
        if (a[n]==a[k]) cout<<n;
    }
    return 0;
}