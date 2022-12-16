#include<bits/stdc++.h>
using namespace std;
const int nmax=9;
int n;
long long arr[nmax];
int parent[nmax];
int ans=1000;
long long help[nmax];
map<long long,int> mem;
int ask(long long num)
{
    if(mem.count(num))return mem[num];
    int d=1;
    for(long long i=2;i*i<=num;i++)
        if(num%i==0)
        {
            d=1+ask(num/i);
            break;
        }
    mem[num]=d;
    return d;
}
bool leaf[nmax];
void test()
{
    for(int i=1;i<=n;i++)
        help[i]=arr[i],leaf[i]=1;
    int now=0;
    for(int j=1;j<=n;j++)
        if(parent[j]==0)now++;
    if(now>1)now=1;
    else now=0;
    now=now+n;
    for(int j=n;j>=1;j--)
        if(parent[j])
        {
            leaf[parent[j]]=0;
            if(help[parent[j]]%help[j])return;
            help[parent[j]]=help[parent[j]]/help[j];
        }
    for(int i=1;i<=n;i++)
        if(leaf[i]&&ask(help[i])==1);
        else now=now+ask(help[i]);
    ans=min(ans,now);
}
void rec(int pos)
{
    if(pos>n)
    {
        test();
        return;
    }
    for(int i=pos+1;i<=n;i++)
        if(arr[i]%arr[pos]==0)
        {
            parent[pos]=i;
            rec(pos+1);
        }
    parent[pos]=0;
    rec(pos+1);
}
int main()
{
mem[1]=0;
cin>>n;
for(int i=1;i<=n;i++)cin>>arr[i];
sort(arr+1,arr+n+1);
rec(1);
cout<<ans<<endl;
return 0;
}