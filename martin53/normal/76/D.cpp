#include<bits/stdc++.h>
using namespace std;
void no()
{
    printf("-1\n");
    exit(0);
}
int main()
{
unsigned long long a,b;
scanf("%I64u%I64u",&a,&b);
unsigned long long x=0,y=0;
vector<int> there={};
for(int i=0;i<64;i++)
{
    unsigned long long now=(1ULL<<i);
    if((b&now))
    {
        y=y+now;
        if(a<now)no();
        a=a-now;
    }
    else if(i!=63)there.push_back(i+1);
}
sort(there.begin(),there.end());
for(auto k:there)
{
    unsigned long long now=(1ULL<<k);
    if((a&(now)))
        {
        a=a-now;
        x=x+now/2;
        y=y+now/2;
        }
}
if(a)no();
printf("%I64u %I64u\n",x,y);
return 0;
}