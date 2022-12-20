#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
struct s
{
int l=-1,r=-1;
int sum=0;
};
vector<s> tree;
int n,k,arr[nmax];
int pref[nmax];
s emp;
int pos=0;
int take(int node)
{
    if(node==-1)return 0;
    return tree[node].sum;
}
void update(int value,int bit,int node)
{
    if(bit==-1)
    {
        tree[node].sum++;
        return;
    }
    if((value&(1<<bit))==0)
    {
        if(tree[node].l==-1)
        {
            tree[node].l=++pos;
            tree.push_back(emp);
        }
        update(value,bit-1,tree[node].l);
    }
    else
    {
        if(tree[node].r==-1)
        {
            tree[node].r=++pos;
            tree.push_back(emp);
        }
        update(value,bit-1,tree[node].r);
    }
    tree[node].sum=take(tree[node].l)+take(tree[node].r);
    //cout<<value<<" "<<bit<<" "<<node<<" -> "<<tree[node].sum<<endl;
}
int query(int value,int bit,int node)
{
    //cout<<"query "<<value<<" "<<bit<<" "<<node<<endl;
    if(node==-1)return 0;
    if(bit==-1)return tree[node].sum;
    int ans=0;
    bool le=value&(1<<bit),ri=k&(1<<bit);
    if(le==0&&ri==0)
    {
        ans=ans+take(tree[node].r);
        ans=ans+query(value,bit-1,tree[node].l);
    }

    if(le==0&&ri==1)
    {
        ans=ans+query(value,bit-1,tree[node].r);
    }

    if(le==1&&ri==0)
    {
        ans=ans+take(tree[node].l);
        ans=ans+query(value,bit-1,tree[node].r);
    }

    if(le==1&&ri==1)
    {
        ans=ans+query(value,bit-1,tree[node].l);
    }


    return ans;
}
int main()
{
tree.push_back(emp);
scanf("%i%i",&n,&k);
for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
for(int i=1;i<=n;i++)pref[i]=pref[i-1]^arr[i];
long long ans=0;
update(0,30,0);
for(int i=1;i<=n;i++)
{
    ans=ans+query(pref[i],30,0);
    update(pref[i],30,0);
    //cout<<i<<" -> "<<ans<<" "<<pos<<endl;
}
printf("%lld\n",ans);
return 0;
}