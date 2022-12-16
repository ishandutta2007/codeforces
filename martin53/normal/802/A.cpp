#include<bits/stdc++.h>
using namespace std;
const int nmax=4e5+42;
int n,k;
int arr[nmax];

int nxt[nmax];
map<int,int> seen;

set< pair<int/*when is next occurrence*/,int/*book*/> > active;
int main()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&arr[i]);

    for(int i=n;i>=1;i--)
    {
        if(seen.count(arr[i]))nxt[i]=seen[arr[i]];
        else nxt[i]=n+1;
        seen[arr[i]]=i;
    }

    int output=0;
    for(int i=1;i<=n;i++)
    {
        if(active.count({i,arr[i]}))
        {
            active.erase({i,arr[i]});
            active.insert({nxt[i],arr[i]});
            continue;
        }
        if(active.size()==k)
        {
            set< pair<int/*when is next occurrence*/,int/*book*/> >:: iterator it=active.end();
            it--;
            active.erase(it);
        }

        output++;
        active.insert({nxt[i],arr[i]});
    }

    printf("%i\n",output);
    return 0;
}