#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42,SIZE=1350;
int n,q;
int arr[nmax];
vector<int> sorted[nmax/SIZE+5];
void update(int l,int r)
{
    if(l/SIZE==r/SIZE)
    {
        swap(arr[l],arr[r]);
        return;
    }
    int bucket_l=l/SIZE,bucket_r=r/SIZE;
    for(int i=0;i<sorted[bucket_l].size();i++)
        if(sorted[bucket_l][i]==arr[l])
        {
            sorted[bucket_l][i]=arr[r];
            while(i>=1&&sorted[bucket_l][i]<sorted[bucket_l][i-1])
                {
                swap(sorted[bucket_l][i],sorted[bucket_l][i-1]);
                i--;
                }
            while(i<sorted[bucket_l].size()-1&&sorted[bucket_l][i]>sorted[bucket_l][i+1])
                {
                swap(sorted[bucket_l][i],sorted[bucket_l][i+1]);
                i++;
                }
            break;
        }

    for(int i=0;i<sorted[bucket_r].size();i++)
        if(sorted[bucket_r][i]==arr[r])
        {
            sorted[bucket_r][i]=arr[l];
            while(i>=1&&sorted[bucket_r][i]<sorted[bucket_r][i-1])
                {
                swap(sorted[bucket_r][i],sorted[bucket_r][i-1]);
                i--;
                }
            while(i<sorted[bucket_r].size()-1&&sorted[bucket_r][i]>sorted[bucket_r][i+1])
                {
                swap(sorted[bucket_r][i],sorted[bucket_r][i+1]);
                i++;
                }
            break;
        }
    swap(arr[l],arr[r]);
}
int inv(int l,int r,int value)//finds how many numbers in [l,r] are <value
{
    if(l>r)return 0;
    if(l/SIZE==r/SIZE)
    {
        int ans=0;
        for(int j=l;j<=r;j++)
            if(value>arr[j])ans++;
        return ans;
    }
    int bucket_l=l/SIZE,bucket_r=r/SIZE;
    int ans=0,STOP=(bucket_l+1)*SIZE;
    for(int i=l;i<STOP;i++)
        if(value>arr[i])ans++;

    STOP=bucket_r*SIZE;
    for(int i=r;i>=STOP;i--)
        if(value>arr[i])ans++;

    int p;
    for(int j=bucket_l+1;j<bucket_r;j++)
    {
        p=lower_bound(sorted[j].begin(),sorted[j].end(),value)-sorted[j].begin();
        ans=ans+p;
    }
    return ans;
}
int main()
{
scanf("%i%i",&n,&q);
for(int i=0;i<n;i++)arr[i]=i+1,sorted[i/SIZE].push_back(i+1);
int l,r;
long long ans=0;
for(int i=1;i<=q;i++)
{
    //cout<<"arr: ";for(int j=0;j<n;j++)cout<<arr[j]<<" ";cout<<endl;
    scanf("%i%i",&l,&r);
    l--;
    r--;
    if(l>r)swap(l,r);
    //ans=ans-2*inv(l,r,arr[l])+(r-l-1);
    if(l!=r)
    {
    ans=ans-2*inv(l,r,arr[l])+(r-l);
    ans=ans+2*inv(l+1,r,arr[r])-(r-l-1);
    update(l,r);
    }
    printf("%lld\n",ans);
}
return 0;
}