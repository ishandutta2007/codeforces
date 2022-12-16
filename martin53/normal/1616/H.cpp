#include<bits/stdc++.h>
using namespace std;

const int mod=998244353,nmax=1.5e5+42;

int n,x,inp[nmax];

long long subsets[nmax];

int my_merge(vector<int> LHS,vector<int> RHS,int bit,int x_now)//take at least one number from both a and b
{
    if(LHS.size()==0||RHS.size()==0)return 0;

    if(bit<0)return subsets[LHS.size()]*subsets[RHS.size()]%mod;

    vector<int> groups_LHS[2]={{},{}};
    for(auto w:LHS)
        if((w&(1<<bit)))groups_LHS[1].push_back(w);
        else groups_LHS[0].push_back(w);

    vector<int> groups_RHS[2]={{},{}};
    for(auto w:RHS)
        if((w&(1<<bit)))groups_RHS[1].push_back(w);
        else groups_RHS[0].push_back(w);

    if((x_now&(1<<bit))==0)
    {
        long long ret=my_merge(groups_LHS[0],groups_RHS[0],bit-1,x_now)+my_merge(groups_LHS[1],groups_RHS[1],bit-1,x_now);

        return ret%mod;
    }

    long long val01=my_merge(groups_LHS[0],groups_RHS[1],bit-1,x_now-(1<<bit));
    long long val10=my_merge(groups_LHS[1],groups_RHS[0],bit-1,x_now-(1<<bit));

    long long ret=0;

    ret=ret+subsets[groups_LHS[0].size()]*subsets[groups_RHS[0].size()];
    ret=ret+val01;
    ret=ret+val01*subsets[groups_RHS[0].size()];

    ret=ret+val10;
    ret=ret+subsets[groups_LHS[1].size()]*subsets[groups_RHS[1].size()];
    ret=ret+val10*subsets[groups_RHS[1].size()];

    ret=ret+val10*subsets[groups_LHS[0].size()];
    ret=ret+val01*subsets[groups_LHS[1].size()];
    ret=ret+val01*val10;

    return ret%mod;
}

int dvd(vector<int> nums,int bit)
{
    //cout<<"nums: ";for(auto w:nums)cout<<w<<" ";cout<<"bit= "<<bit<<endl;

    vector<int> given[2]={{},{}};
    for(auto w:nums)
        if((w&(1<<bit)))given[1].push_back(w);
        else given[0].push_back(w);

    long long outp=subsets[given[0].size()]+subsets[given[1].size()]+my_merge(given[0],given[1],bit-1,x-(1<<bit));

    return outp%mod;
}

int solve(vector<int> nums,int bit)
{
    //cout<<"solve: ";for(auto w:nums)cout<<w<<" ";cout<<"bit= "<<bit<<endl;

    if(nums.size()<=1||bit<0)return subsets[nums.size()];

    vector<int> given[2]={{},{}};

    for(auto w:nums)
        if((w&(1<<bit)))given[1].push_back(w);
        else given[0].push_back(w);

    if((1<<bit)>x)return solve(given[0],bit-1)+solve(given[1],bit-1);

    return dvd(nums,bit);
}

int main()
{
    subsets[0]=0;
    for(int i=1;i<nmax;i++)subsets[i]=(subsets[i-1]*2+1)%mod;

    scanf("%i%i",&n,&x);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    vector<int> nums={};
    for(int i=1;i<=n;i++)nums.push_back(inp[i]);

    printf("%i\n",solve(nums,29));

    return 0;
}