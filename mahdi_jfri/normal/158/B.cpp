#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+20;
int a;
int main()
{
    int n;
    cin>>n;
    int yek=0,dow=0,se=0,res=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a==1)
            yek++;
        else if(a==2)
            dow++;
        else if(a==3)
            se++;
        else res++;
    }
    if(dow&1)
    {
        dow--;
        yek--;
        se++;
    }
    res+=dow/2;
    if(se>=yek)
        res+=se;
    else
    {
        res+=se;
        yek-=se;
        res+=(yek%4==0?0:1)+(yek/4);
    }
    cout<<res;
}