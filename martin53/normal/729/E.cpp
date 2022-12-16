#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,s,a[nmax];
int seen[nmax];
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>s;
for(int i=1;i<=n;i++)
{
cin>>a[i];
seen[a[i]]++;
}
int ans=0,free=0;
if(a[s]==0){ans=seen[0]-1;free=seen[0]-1;}
else
{
ans=seen[0]+1;
free=seen[0];
seen[a[s]]--;
}
//cout<<ans<<endl;

int pos=n;
while(seen[pos]==0)pos--;

for(int level=1;level<=pos;level++)
{
    if(seen[level]==0)
    {
        if(free)free--;
        else
        {
        ans++;
        while(pos>=level&&seen[pos]==0)pos--;
        assert(pos>=level);
        seen[pos]--;
        while(pos>=level&&seen[pos]==0)pos--;
        }
    }
}
cout<<ans<<endl;
return 0;
}