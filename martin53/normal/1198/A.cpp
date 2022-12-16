#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,mx,inp[nmax];
map<int,int> s;

vector< pair<int/*number*/,int/*times*/> > seen={};

int eval(int k)
{
    int now=(1<<k);
    //cout<<k<<" "<<seen.size()<<" "<<now<<endl;
    if(k*n<=mx&&now>=seen.size())return 0;
    if(now>seen.size())return n;

    int sum=0,ret=n;
    for(int i=0;i<now-1;i++)
        sum=sum+seen[i].second;

    for(int i=now-1;i<seen.size();i++)
    {
        sum=sum+seen[i].second;
        if(i>=now)sum=sum-seen[i-now].second;

        //cout<<k<<" "<<i<<" -> "<<sum<<endl;

        if(k*n<=mx)
        {
            ret=min(ret,n-sum);
        }
    }

    return ret;
}
int main()
{
    scanf("%i%i",&n,&mx);
    mx=mx*8;
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)s[inp[i]]++;

    for(auto p:s)
    {
        seen.push_back(p);
    }

    int output=n;
    for(int k=0;k<20;k++)
    {
        output=min(output,eval(k));
    }

    printf("%i\n",output);

    return 0;
}