#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,k;
int inp[nmax];
bool can[nmax];
deque<int/*index*/> q;
bool test(int d)
{
memset(can,0,sizeof(can));
can[0]=1;
q={};
    for(int i=1;i<=n;i++)
    {
        if(i-k>=0&can[i-k])q.push_front(i-k+1);
        while(q.size()&&inp[i]-inp[q.back()]>d)q.pop_back();
        if(q.size())can[i]=1;
        else can[i]=0;
        //cout<<d<<" "<<i<<" -> "<<can[i]<<" "<<(q.size()?q.back():-1)<<endl;
    }
    return can[n];
}
int main()
{
scanf("%i%i",&n,&k);
for(int i=1;i<=n;i++)scanf("%i",&inp[i]);
sort(inp+1,inp+n+1);
int ok=inp[n]-inp[1],not_ok=-1;
while(ok-not_ok>1)
{
    int av=(ok+not_ok)/2;
    if(test(av))ok=av;
    else not_ok=av;
    //cout<<"---"<<endl;
}
printf("%i\n",ok);
return 0;
}