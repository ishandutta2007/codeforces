#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];

set< pair<int,int> > active;
int stop[nmax];
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=2*n;i++)
        inp[i+n]=inp[i];

    for(int i=1;i<=3*n;i++)
        stop[i]=-1;
    /*
    for(int i=1;i<=3*n;i++)
        cout<<inp[i]<<" ";cout<<endl;
    */
    for(int i=1;i<=3*n;i++)
    {
        while(active.size())
        {
            set< pair<int,int> >::iterator it=active.end();
            it--;

            pair<int,int> now=*it;

            if(inp[i]*2+1<=now.first)
            {
                stop[now.second]=i;
                active.erase(it);
            }
            else break;
        }
        active.insert({inp[i],i});
    }

    for(int i=3*n-1;i>=1;i--)
        if(stop[i]==-1)stop[i]=stop[i+1];
        else if(stop[i+1]>0)stop[i]=min(stop[i],stop[i+1]);

    for(int i=1;i<=n;i++)
        if(stop[i]==-1)printf("-1 ");
        else printf("%i ",stop[i]-i);

    return 0;
}