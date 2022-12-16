#include<bits/stdc++.h>
using namespace std;
const int nmax=3e5+42,kmax=1e6+42;
int n,k,arr[nmax];
pair<int/*value*/,int/*position*/> sparse[20][nmax];
int lg[nmax];
void build()
{
    for(int i=1;i<=n;i++)
        sparse[0][i]={arr[i],i};

    for(int sz=1;(1<<sz)<=n;sz++)
        for(int j=1;j+(1<<sz)-1<=n;j++)
            {
            sparse[sz][j]=max(sparse[sz-1][j],sparse[sz-1][j+(1<<(sz-1))]);
            //cout<<sz<<" "<<j<<" -> "<<sparse[sz][j].first<<" "<<sparse[sz][j].second<<endl;
            }

    for(int j=2;j<=n;j++)
        lg[j]=lg[j/2]+1;
}
pair<int/*value*/,int/*position*/> query(int l,int r)
{
    if(l>r)swap(l,r);
    if(l==r)return {arr[l],l};
    int st=lg[r-l+1];

    //cout<<"st= "<<st<<endl;

    return max(sparse[st][l],sparse[st][r-(1<<st)+1]);
}
int where[nmax];
int pref[nmax];
vector<int> seen[kmax];
int ask(int l_,int r_,int val)
{
    int p=upper_bound(seen[val].begin(),seen[val].end(),r_)-seen[val].begin();
    int q=lower_bound(seen[val].begin(),seen[val].end(),l_)-seen[val].begin();
    return p-q;
}
long long solve(int l,int r)
{
    if(l>=r)return 0;
    int av=query(l,r).second;

    //cout<<l<<" "<<r<<" -> av= "<<av<<endl;

    long long ret=solve(l,av-1)+solve(av+1,r);


    if(av<=(l+r)/2)
    {
        for(int p=l;p<=av;p++)
        {
            int want=pref[p-1]+arr[av];
            want=want%k;
            //cout<<"want= "<<want<<endl;
            ret=ret+ask(av,r,want);
        }
        ret--;
    }

    else
    {
        for(int q=av;q<=r;q++)
        {
            int want=pref[q]-arr[av];
            want=want%k;
            if(want<0)want=want+k;
            //cout<<"want= "<<want<<endl;
            ret=ret+ask(l-1,av-1,want);
        }
        ret--;
    }


    //cout<<l<<" "<<r<<" -> "<<ret<<endl;
    return ret;
}
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>arr[i];
for(int i=1;i<=n;i++)pref[i]=(pref[i-1]+arr[i])%k;
for(int i=0;i<=n;i++)seen[pref[i]].push_back(i);

build();
cout<<solve(1,n)<<endl;
return 0;
}