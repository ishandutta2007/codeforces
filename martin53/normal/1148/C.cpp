#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42;
int n,arr[nmax],where[nmax];
vector< pair<int,int> > output={};
bool can(int i,int j)
{
    return 2*abs(i-j)>=n;
}
void add(int i,int j)
{
    output.push_back({i,j});
    swap(where[arr[i]],where[arr[j]]);
    swap(arr[i],arr[j]);
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
{
    scanf("%i",&arr[i]);
    where[arr[i]]=i;
}
for(int i=2;i<n;i++)
    if(where[i]!=i)
    {
        int aim=i;
        if(can(where[i],1))
        {
            add(where[i],1);
            if(can(1,aim))
            {
                add(1,aim);
            }
            else
            {
                add(1,n);
                add(n,aim);
            }
        }
        else//can(where[i],n)
        {
            add(where[i],n);
            if(can(n,aim))
            {
                add(n,aim);
            }
            else
            {
                add(n,1);
                add(1,aim);
            }
        }

        //cout<<"after "<<i<<" -> ";for(int j=1;j<=n;j++)cout<<arr[j]<<" ";cout<<endl;
    }

if(arr[1]!=1)
{
    add(1,n);
}

for(int i=1;i<=n;i++)
    assert(arr[i]==i);

printf("%i\n",output.size());
for(auto k:output)
{
    printf("%i %i\n",k.first,k.second);
}
return 0;
}