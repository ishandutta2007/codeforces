#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int L[20],R[20],B[10],A[10],ans,n;
bool ok(int l,int r)
{
    if(l>r)return 0;
    for(int i=l;i<=r;i++)
    if(B[i])return 1;
    return 0;
}
bool judge(int x,int lf,int rf)
{
    if(x>n)return 1;
    int l=L[x],r=R[x];
    if(lf&&rf)
    {
        if(l==r)
        {
            if(B[l])
            {
                B[l]--;
                if(judge(x+1,1,1))return 1;
                B[l]++;
            }
            return 0;
        }
        if(ok(l+1,r-1))return 1;
        if(B[l])
        {
            B[l]--;
            if(judge(x+1,1,0))return 1;
            B[l]++;
        }
        if(B[r])
        {
            B[r]--;
            if(judge(x+1,0,1))return 1;
            B[r]++;
        }
        return 0;
    }
    else if(lf)
    {
        if(ok(l+1,9))return 1;
        if(B[l])
        {
            B[l]--;
            if(judge(x+1,1,0))return 1;
            B[l]++;
        }
        return 0;
    }
    else if(rf)
    {
        if(ok(0,r-1))return 1;
        if(B[r])
        {
            B[r]--;
            if(judge(x+1,0,1))return 1;
            B[r]++;
        }
        return 0;
    }
    return 0;
}
void Work(int x,int sum)
{
    if(x==10)
    {
        memcpy(B,A,sizeof(A));
        B[0]+=sum;
        if(judge(1,1,1))ans++;
        return;
    }
    for(int i=0;i<=sum;i++)
    {
        A[x]=i;
        Work(x+1,sum-i);
    }
}
int main()
{
    int i;
    long long x,y,t;
    cin>>x>>y;t=y;
    while(t){t/=10;n++;}
    for(i=n;i>=1;i--)R[i]=y%10,y/=10;
    for(i=n;i>=1;i--)L[i]=x%10,x/=10;
    Work(1,n);
    cout<<ans;
}