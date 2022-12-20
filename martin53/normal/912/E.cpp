#include<bits/stdc++.h>
using namespace std;
const int nmax=20,STOP=1<<21;
int n,p[nmax],n_l=0,p_left[nmax],n_r=0,p_right[nmax];
long long k;
int sum=0;
long long now;

long long le[STOP],l_ind=0,ri[STOP],r_ind=0;

void gen_left(long long num,int pos)
{
    if(num>now)return;
    if(pos==n_l+1)
    {
        l_ind++;
        le[l_ind]=num;
        return;
    }
    gen_left(num,pos+1);
    if(now/p_left[pos]>=num)gen_left(num*p_left[pos],pos);
}

void gen_right(long long num,int pos)
{
    if(num>now)return;
    if(pos==n_r+1)
    {
        r_ind++;
        ri[r_ind]=num;
        return;
    }
    gen_right(num,pos+1);
    if(now/p_right[pos]>=num)gen_right(num*p_right[pos],pos);
}
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)scanf("%i",&p[i]);
for(int i=1;i<=n;i++)
    if(i%4<2)
    {
    n_l++;
    p_left[n_l]=p[i];
    }
    else
    {
    n_r++;
    p_right[n_r]=p[i];
    }
scanf("%lld",&k);
now=1e18;
l_ind=0;
r_ind=0;
gen_left(1,1);
gen_right(1,1);
sort(le+1,le+l_ind+1);
sort(ri+1,ri+r_ind+1);

long long ok=1e18,not_ok=0;
while(ok-not_ok>1)
{
    now=(ok+not_ok)/2;
    sum=0;
    int j=1;
    /*
    cout<<"le: ";for(int j=1;j<=l_ind;j++)cout<<le[j]<<" ";cout<<endl;
    cout<<"ri: ";for(int j=1;j<=r_ind;j++)cout<<ri[j]<<" ";cout<<endl;
    */
    for(int i=l_ind;i>=1;i--)
    {
        while(j<=r_ind&&ri[j]<=now/le[i])j++;
        sum=sum+j-1;
    }
    //cout<<now<<" -> "<<sum<<endl;
    if(sum>=k)ok=now;
    else not_ok=now;
}
printf("%lld\n",ok);
return 0;
}