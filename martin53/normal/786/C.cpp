#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,a[nmax];
int ans[nmax];
bool seen[nmax];
int query(int k)
{
    int ans_now=0;
    for(int pos=1;pos<=n;pos++)
    {
        int colours=0;
        int j;
        for(j=pos;j<=n;j++)
        {
            if(seen[a[j]]==0)
            {
            colours++;
            if(colours>k)break;
            seen[a[j]]=1;
            }

        }
        //cout<<"k= "<<k<<" pos= "<<pos<<" j= "<<j<<endl;
        for(int p=pos;p<j;p++)seen[a[p]]=0;
        pos=j-1;
        ans_now++;
    }
    //cout<<k<<" -> "<<ans_now<<endl;
    return ans_now;
}
void solve(int l,int r)
{
    if(r-l<=1)return;
    int av=(l+r)/2;
    ans[av]=query(av);
    if(ans[l]==ans[av])
    {
        for(int j=l;j<=av;j++)ans[j]=ans[l];
    }
    else solve(l,av);
    if(ans[av]==ans[r])
    {
        for(int j=av;j<=r;j++)ans[j]=ans[r];
    }
    else solve(av,r);

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n;
for(int i=1;i<=n;i++)cin>>a[i];

ans[1]=query(1);
ans[n]=1;

solve(1,n);

for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
return 0;
}
//O(2*n^1.5)?