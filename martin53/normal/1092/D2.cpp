#include<bits/stdc++.h>
using namespace std;
const int nmax=2*1e5+42;
int n;
int arr[nmax];
void print(bool ans)
{
    if(ans)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    exit(0);
}
stack< pair<int/*value*/,int/*wall*/> > help;
int main()
{
cin>>n;
for(int i=1;i<=n;i++)cin>>arr[i];
for(int i=1;i<=n;i++)
    if(help.size()==0)help.push({arr[i],0});
    else
    {
        if(help.top().first!=arr[i])help.push({arr[i],0});
        else if(help.top().first==arr[i])
        {
            if(help.top().first<help.top().second)print(0);
            int mx=max(help.top().first,help.top().second);
            help.pop();
            if(help.size())
            {
                pair<int/*value*/,int/*wall*/> now=help.top();
                help.pop();
                now.second=max(now.second,mx);
                help.push(now);
            }
        }
        //cout<<i<<" "<<help.size()<<endl;
    }
int mx=0;
for(int i=1;i<=n;i++)
    mx=max(mx,arr[i]);
while(help.size())
{
    if(help.top().first!=mx)print(0);
    help.pop();
}
print(1);
return 0;
}