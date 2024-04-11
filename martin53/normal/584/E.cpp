#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42;
int n;
int my[nmax],target[nmax];
vector< pair<int,int> > outp;

int hash_value[nmax];

int main()
{

cin>>n;
for(int i=1;i<=n;i++)cin>>my[i];
for(int i=1;i<=n;i++)cin>>target[i];

for(int i=1;i<=n;i++)hash_value[target[i]]=i;

for(int i=1;i<=n;i++)my[i]=hash_value[my[i]];

//for(int j=1;j<=n;j++)cout<<hash_value[j]<<" ";cout<<endl;
//for(int j=1;j<=n;j++)cout<<my[j]<<" ";cout<<endl;

int ans=0;
for(int i=n;i>=1;i--)
if(my[i]!=i)
{
    //assert(my[i]<=i);
    int now=-1;
    for(int j=1;j<=i;j++)
        if(my[j]==i)now=j;

    for(int j=now+1;j<=i;j++)
    {
        if(my[j]<=now)
        {
            ans=ans+(j-now);
            swap(my[j],my[now]);
            outp.push_back({j,now});
            now=j;
        }
    }

    //cout<<"after "<<i<<" : ";for(int j=1;j<=n;j++)cout<<my[j]<<" ";cout<<endl;

    assert(my[i]==i);
}

cout<<ans<<endl;
cout<<outp.size()<<endl;
for(auto k:outp)printf("%i %i\n",k.first,k.second);

return 0;
}