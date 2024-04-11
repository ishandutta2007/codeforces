#include<bits/stdc++.h>
using namespace std;
int n,i,coun=0;
int a[101];
int main(){
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n-2;i++)
    {
        if(a[i]==1 && a[i+1]==0 && a[i+2]==1)
        {
            a[i+2]=0;
            coun++;
        }
    }
    cout<<coun;
    return 0;
}