#include<bits/stdc++.h>
using namespace std;
int n,k,i,counti=1;
int a[100010];
int main(){
    cin>>n>>k;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    i=1;
    while(counti<=k)
    {
        if(i<=n)
        {
            if(a[i]-a[i-1]>0)
            {
                cout<<a[i]-a[i-1]<<"\n";
                counti++;
                i++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            cout<<"0\n";
            counti++;
        }
    }
    return 0;
}