#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,x;cin>>n>>x;
    long long int min=1000000000000000;
    bool b1= false;
    long long int d,h,ans;
    long long int a[n];
    long long int b[n];
    long long int max = 0;
    for (long long int i=0;i<n;i++)
    {
        cin>>a[i]>>b[i];
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    for(long long int i=0;i<n;i++)
    {
        d=a[i];h=b[i];
        ans=d-h;
        if(d-h>0)
        {
            b1=true;
            ans=(x-max+ans-1)/(ans);
            if(ans<0)
            {
                ans=1;
            }
            ans+=1;
            if(d>x)
            {
                ans=1;
            }
            if(ans<min)
            {
                min=ans;
            }
        }
    }
    if(max>=x)
    {
        b1=true;
        ans=1;
        min=1;
    }
    if(b1)
    {
        cout<<min<<"\n";
    }
    else
    {
        cout<<-1<<"\n";
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num;
    cin>>num;
    for(long long int i=0;i<num;i++)
    {
       	solve();
    }   
}