#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,inp[nmax];

long long pref[nmax];

int outp;

void test(int l,int r)
{
    if(r-l+1<3)return;

    long long lhs=inp[l]^inp[r];
    long long rhs=pref[r-1]-pref[l];

    if(lhs==rhs)
    {
        //cout<<"l= "<<l<<" r= "<<r<<endl;

        outp++;
    }
}


long long nums[nmax],tree[nmax*4];

void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=nums[l];
        return;
    }

    int av=(l+r)/2;

    build(node*2,l,av);
    build(node*2+1,av+1,r);

    tree[node]=min(tree[node*2],tree[node*2+1]);
}

int l_root;

void go_down(int node,int l,int r,int lq,int rq)
{
    if(tree[node]>inp[l_root]+pref[l_root])return;
    //else cout<<l<<" "<<r<<" "<<lq<<" "<<rq<<" tree "<<tree[node]<<" "<<inp[l_root]+pref[l_root]<<endl;

    if(l==r)
    {
        test(l_root,r);
        return;
    }

    int av=(l+r)/2;

    if(lq<=av)go_down(node*2,l,av,lq,min(av,rq));
    if(av<rq)go_down(node*2+1,av+1,r,max(av+1,lq),rq);
}
int main()
{
    scanf("%i",&n);
    //n=2e5;

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        //inp[i]=rand()+1;

        pref[i]=pref[i-1]+inp[i];
    }

    for(int r=1;r<=n;r++)
        nums[r]=pref[r-1]-inp[r];

    build(1,1,n);

    for(int l=1;l<=n;l++)
    {
        //cout<<l<<" "<<outp<<endl;

        int ok=n+1,not_ok=l;

        while(ok-not_ok>1)
        {
            int av=(ok+not_ok)/2;

            if(pref[l]+inp[l]<=pref[av])ok=av;
            else not_ok=av;
        }

        int r=ok;
        if(r>n)continue;

        l_root=l;

        go_down(1,1,n,r,n);
    }

    printf("%i\n",outp);
    return 0;
}