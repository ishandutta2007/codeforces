#include<bits/stdc++.h>
using namespace std;
void solve()
{
    long long int n,k,d;cin>>n>>k;
    long long int min,max;
    min = 10000000000000;
    max = -1;
    for(long long int i=0;i<n;i++)
    {
        cin>>d;
        if(d>max)
        {
            max=d;
        }
        if(d<min)
        {
            min=d;
        }
    }
    if(abs(min+k-max)<=k)
    {
        cout<<min+k<<endl;
    }
    else
    {
        cout<<-1<<endl;
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