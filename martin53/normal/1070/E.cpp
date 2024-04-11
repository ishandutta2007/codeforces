#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=2*1e5+42;
int n,m;
long long t;
int difficulty[nmax];
pair<int/*solved*/,long long/*remaining time*/> ask(int d)
{
    long long t_now=t;
    int ans=0,solved=0,sum=0;
    for(int i=1;i<=n;i++)
        if(difficulty[i]<=d)
        {
            if(t_now>=difficulty[i])
            {
                t_now=t_now-difficulty[i];
                solved++;
                sum=sum+difficulty[i];
                ans++;
                if(solved==m)t_now=t_now-sum,sum=0,solved=0;
            }
            else t_now=-1;
            //cout<<i<<" "<<t_now<<" "<<ans<<endl;
        }
    //cout<<d<<" -> "<<ans<<" "<<t_now<<endl;
    return {ans,t_now};
}
void query()
{
cin>>n>>m>>t;
for(int i=1;i<=n;i++)cin>>difficulty[i];
long long ok=0,not_ok=t+1;
pair<int/*solved*/,int/*time*/> ans={-1,0};
while(not_ok-ok>1)
{
    int av=(ok+not_ok)/2;
    pair<int/*solved*/,long long/*remaining time*/> ret=ask(av);
    if(ret.second>=0)ok=av;
    else not_ok=av;
    if(ans.first<ret.first)ans={ret.first,av};
}
cout<<ans.first<<" "<<ans.second<<"\n";
}
signed main()
{
ios_base::sync_with_stdio(false);
cin.tie();
int q;
cin>>q;
for(int i=1;i<=q;i++)
    query();
return 0;
}