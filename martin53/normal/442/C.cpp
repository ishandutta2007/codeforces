#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n,arr[nmax];
int l[nmax],r[nmax];
stack< pair<int/*value*/,int/*index*/> > help,emp;
pair<int/*value*/,int/*index*/> work[nmax];
bool cmp(pair<int/*value*/,int/*index*/> a,pair<int/*value*/,int/*index*/> b)
{
if(a.first!=b.first)return a.first<b.first;
return a.second<b.second;
}
int main()
{
cin>>n;
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);

for(int i=1;i<=n;i++)
{
    while(help.size()&&arr[i]>=help.top().first)help.pop();
    if(help.size()==0)l[i]=-1;
    else l[i]=help.top().second;
    help.push({arr[i],i});
}
help=emp;
for(int i=n;i>=1;i--)
{
    while(help.size()&&arr[i]>=help.top().first)help.pop();
    if(help.size()==0)r[i]=n+1;
    else r[i]=help.top().second;
    help.push({arr[i],i});
}

//cout<<"l: ";for(int i=1;i<=n;i++)cout<<l[i]<<" ";cout<<endl;
//cout<<"r: ";for(int i=1;i<=n;i++)cout<<r[i]<<" ";cout<<endl;

for(int i=1;i<=n;i++)work[i]={arr[i],i};
sort(work+1,work+n+1,cmp);
long long ans=0;
int prev=0;
for(int i=1;i+2<=n;i++)
{
    int j=i;
    while(work[i].first==work[j].first)j++;
    j--;
    ans=ans+1LL*(work[i].first-prev)*(n-1-i);
    //cout<<"ans= "<<ans<<endl;
    prev=work[i].first;
    for(int k=i;k<=j;k++)
        if(l[work[k].second]!=-1&&r[work[k].second]!=n+1)
        {
            if(k==i||l[work[k].second]!=l[work[k-1].second])
            {
                ans=ans+min(arr[l[work[k].second]],arr[r[work[k].second]])-prev;
            }
        }
    i=j;
    //cout<<"after i= "<<i<<", ans= "<<ans<<endl;
}
cout<<ans<<endl;
return 0;
}