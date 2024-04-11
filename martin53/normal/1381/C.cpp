#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;

int n,x,y,inp[nmax];

vector<int> seen[nmax];

set< pair<int/*seen*/,int/*value*/> > active;

int outp[nmax];

void query()
{
    active={};

    scanf("%i%i%i",&n,&x,&y);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n+1;i++)seen[i]={};

    for(int i=1;i<=n;i++)seen[inp[i]].push_back(i);

    for(int i=1;i<=n;i++)outp[i]=0;

    active={};

    int wrong=0;

    for(int i=1;i<=n+1;i++)
        if(seen[i].size())active.insert({seen[i].size(),i});
        else wrong=i;
    /*
    cout<<"active: "<<endl;
    for(auto k:active)cout<<k.first<<" "<<k.second<<endl;
    cout<<"---"<<endl;
    */

    for(int t=1;t<=x;t++)
    {
        set< pair<int/*seen*/,int/*value*/> >::iterator it=active.end();
        it--;

        pair<int/*seen*/,int/*value*/> info=*it;

        //cout<<"info "<<info.first<<" "<<info.second<<endl;

        active.erase(it);

        info.first--;

        if(info.first)active.insert(info);

        outp[seen[info.second].back()]=info.second;

        seen[info.second].pop_back();
    }

    /*
    cout<<"active: "<<endl;
    for(auto k:active)cout<<k.first<<" "<<k.second<<endl;
    cout<<"---"<<endl;
    */

    if(x<y)
    {
        vector<int> order={};

        while(active.size())
        {
            set< pair<int/*seen*/,int/*value*/> >::iterator it=active.end();
            it--;

            pair<int/*seen*/,int/*value*/> info=*it;

            active.erase(it);

            for(auto k:seen[info.second])order.push_back(k);
        }

        //for(auto k:order)cout<<k<<" ";cout<<endl;

        int add=0;
        for(int i=0;i<order.size();i++)
            if(inp[order[i]]!=inp[order[0]]){add=i;break;}

        //cout<<"add= "<<add<<endl;

        for(int i=order.size()-1;i>=0&&x<y&&inp[order[i]]!=inp[order[0]];i--)
        {
            int pos=order[(i+add)%order.size()];

            int value=inp[order[i]];

            outp[pos]=value;
            y--;
        }

        for(int i=0;x<y&&inp[order[i]]==inp[order[0]];i++)
        {
            int pos=order[(i+add)%order.size()];

            int value=inp[order[i]];

            if(inp[pos]==value)
            {
                printf("NO\n");
                return;
            }

            else outp[pos]=value;
            y--;
        }
    }


    for(int i=1;i<=n;i++)
        if(outp[i]==0)outp[i]=wrong;

    printf("YES\n");
    for(int i=1;i<=n;i++)printf("%i ",outp[i]);
    printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        query();
    }
    return 0;
}