#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];

map<int,int> seen;
bool test(int now)
{
    //cout<<"test "<<now<<" "<<seen[0]<<endl;
    if(now==0)return 0;
    if(seen[now-1])return 0;
    //cout<<"ok"<<endl;
    return 1;
}
bool first_move()
{
    for(int i=1;i<=n;i++)
        seen[inp[i]]++;

    if(seen.count(0)&&seen[0]>=2)return 0;

    int over=0;
    for(auto k:seen)
        over=over+k.second-1;

    //cout<<"over= "<<over<<endl;

    if(over>=2)return 0;

    if(over==1)
    {
        for(auto k:seen)
            if(k.second==2)
            {
                if(test(k.first)==0)return 0;
            }
        return 1;
    }
    for(int i=1;i<=n;i++)
        if(test(inp[i]))return 1;
    return 0;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    //cout<<"first move= "<<first_move()<<endl;

    if(first_move()==0)
    {
        printf("cslnb\n");
        return 0;
    }

    sort(inp+1,inp+n+1);

    long long sum=0;
    for(int i=1;i<=n;i++)
        sum=sum+(inp[i]-(i-1));

    if(sum%2==0)printf("cslnb\n");
    else printf("sjfnb\n");

    return 0;
}