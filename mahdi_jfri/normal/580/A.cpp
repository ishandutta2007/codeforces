#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+20;
int a[maxn];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int res=1;
    int max1=1;
    for(int i=1;i<n;i++)
    {
        if(a[i-1]>a[i])
        {
            max1=max(res,max1);
            res=1;
        }
        else
            res++;
    }
    cout<<max(res,max1);
}