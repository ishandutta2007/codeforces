#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
long long n,m,ta,tb,k;
long long a_times[nmax],b_times[nmax];
int main()
{
cin>>n>>m>>ta>>tb>>k;
for(int i=1;i<=n;i++)
{
    cin>>a_times[i];
}

for(int i=1;i<=m;i++)
{
    cin>>b_times[i];
}

if(n<=k||m<=k)
{
    cout<<-1<<endl;
    return 0;
}
long long maxi=-1;

for(int i=1;i<=n&&i-1<=k;i++)
{
    //cancel everything before a_times[i]
    int in=lower_bound(b_times+1,b_times+m+1,a_times[i]+ta)-b_times;

    //cout<<i<<" -> "<<in<<endl;

    in=in+(k-(i-1));

    //cout<<"final in "<<in<<endl;

    if(in>m)
    {
        cout<<-1<<endl;
        return 0;
    }
    else
    {
        maxi=max(maxi,b_times[in]+tb);
    }
}
cout<<maxi<<endl;
return 0;
}