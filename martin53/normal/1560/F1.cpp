#include<bits/stdc++.h>
using namespace std;

string inp;
int k;

long long outp;

void dfs(int pos,int mask,int used,bool over,long long val)
{
    if(used>k)return;

    if(over||pos==inp.size())
    {
        if(used<k)
        {
            //cout<<pos<<" "<<mask<<" "<<used<<" "<<over<<" "<<val<<endl;

            for(int j=pos;j<inp.size();j++)val=val*10;

            outp=min(outp,val);

            return;
        }

        //used=k

        int mini=9;

        for(int i=9;i>=0;i--)
            if((mask&(1<<i)))mini=i;

        //cout<<pos<<" "<<mask<<" "<<used<<" "<<over<<" "<<val<<" "<<mini<<endl;

        for(int j=pos;j<inp.size();j++)val=val*10+mini;

        outp=min(outp,val);
        return;
    }

    int digit=inp[pos]-'0';

    if((mask&(1<<digit)))dfs(pos+1,mask,used,0,val*10+digit);
    else dfs(pos+1,mask+(1<<digit),used+1,0,val*10+digit);

    digit++;

    for(;digit<=9;digit++)
    {
        if((mask&(1<<digit)))
        {
            dfs(pos+1,mask,used,1,val*10+digit);
            break;
        }

        if(used==k)continue;

        dfs(pos+1,mask+(1<<digit),used+1,1,val*10+digit);
        break;
    }
}
int solve()
{
    cin>>inp>>k;

    outp=1e18;

    dfs(0,0,0,0,0);

    return outp;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<endl;
    }

    return 0;
}