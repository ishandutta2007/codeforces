#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax],outp[nmax];

int cnt[nmax];

set< pair<int/*cnt*/,int/*number*/> > active={};

void add(int l,int val)
{
    active.erase({cnt[inp[l]],inp[l]});

    cnt[inp[l]]+=val;

    active.insert({cnt[inp[l]],inp[l]});
}
void push(int l,int r,int val)
{
    add(l,val);
    add(r,val);
}
int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)cnt[i]=0;

    for(int i=1;i<=n;i++)cnt[inp[i]]++;

    for(int i=1;i<=n;i++)
        if(cnt[i]>(n+1)/2)return -1;

    for(int i=1;i<=n;i++)cnt[i]=0;

    int outp=n-1;

    active={};

    for(int i=1;i<=n;i++)
        push(i,i,1);

    for(int i=1;i<=n;i++)
        active.insert({cnt[i],i});

    int start_group=1;

    for(int i=1;i<n;i++)
    {
        if(inp[i]!=inp[i+1])
        {
            push(start_group,i,-1);
            push(i+1,i+1,-1);

            push(start_group,i+1,1);

            //there are outp+1 groups now

            int groups=2*(outp+1);

            set< pair<int/*cnt*/,int/*number*/> >::iterator it=active.end();
            it--;

            int cur_mx=(*it).first;

            //cout<<"groups= "<<groups<<" cur_mx= "<<cur_mx<<endl;

            if(2*cur_mx-1>groups)//wrong
            {
                push(start_group,i+1,-1);

                push(i+1,i+1,+1);

                push(start_group,i,+1);
            }
            else
            {
                outp--;
            }
        }
        else
        {
            start_group=i+1;
        }
        /*
        cout<<"i= "<<i<<" start= "<<start_group<<" outp= "<<outp<<endl;
        cout<<"active: ";for(auto w:active)cout<<w.first<<" "<<w.second<<"\t";cout<<endl;
        */
    }
    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%i\n",solve());
    }

    return 0;
}