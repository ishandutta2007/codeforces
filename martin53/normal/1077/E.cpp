#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e5+42;
set<int> possible[nmax];
map<int,int> seen;
int main()
{
int n;
int x;
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    scanf("%i",&x);
    seen[x]++;
    possible[seen[x]].insert(x);
}
int ans=0;
for(int i=n;i>=1;i--)
{
    set<int> taken={};
    int sum=0;
    for(int j=i;true;j=j/2)
    {
        int ok=0;
        for(auto k:possible[j])
            if(taken.count(k)==0){ok=k;break;}
        //cout<<i<<" "<<j<<" -> "<<ok<<endl;
        if(ok==0)break;
        sum=sum+j;
        taken.insert(ok);
        if(j%2==1)break;
    }
    ans=max(ans,sum);
}
cout<<ans<<endl;
return 0;
}