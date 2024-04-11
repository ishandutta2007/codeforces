#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;

int tree[nmax*4][2];/*0-> -1 progression, 1-> +1 progression*/

void push(int node,int l,int r,int type)
{
    int av=(l+r)/2;
    tree[node*2][type]=min(tree[node*2][type],tree[node][type]);
    int other=tree[node][type]+(av-l+1)*(type==0?-1:1);
    //cout<<"\t other "<<other<<" "<<tree[node*2+1][type]<<endl;
    tree[node*2+1][type]=min(tree[node*2+1][type],other);
    tree[node][type]=1e9;
}
void update(int node,int l,int r,int lq,int rq,int value,int type)
{
    //cout<<node<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<" "<<value<<" "<<(type==0?-1:1)<<endl;
    if(l==lq&&r==rq)
    {
        //cout<<"updated "<<l<<" "<<r<<" with "<<add<<endl;
        tree[node][type]=min(tree[node][type],value);
        return;
    }
    int av=(l+r)/2;
    push(node,l,r,type);

    if(lq<=av)update(node*2,l,av,lq,min(av,rq),value,type);
    if(av<rq)update(node*2+1,av+1,r,max(lq,av+1),rq,value+max(0,av-lq+1)*(type==0?-1:1),type);
}
int output[nmax];
void solve(int node,int l,int r,int type)
{
    //cout<<node<<" "<<l<<" "<<r<<" "<<type<<" -> "<<tree[node][type]<<endl;
    if(l==r)
    {
        output[l]=min(output[l],tree[node][type]);
        return;
    }
    int av=(l+r)/2;
    push(node,l,r,type);
    solve(node*2,l,av,type);
    solve(node*2+1,av+1,r,type);
}
int n;
int a[nmax];
map<int,int> seen;
int b[nmax];
int main()
{
for(int i=0;i<4*nmax;i++)
    for(int j=0;j<2;j++)
    tree[i][j]=1e9;

scanf("%i",&n);
for(int i=1;i<=n;i++){scanf("%i",&a[i]);seen[a[i]]=i;}
for(int i=1;i<=n;i++)scanf("%i",&b[i]);

for(int q=1;q<=n;q++)
{
    int p=seen[b[q]];
    int prev;
    //cout<<p<<" "<<q<<endl;
    if(p<q)
    {
        prev=0;
        update(1,1,n,1,q-p+1,q-p,0);
        prev=q-p+1;
        update(1,1,n,prev,q,0,1);
        prev=q;
        if(prev<n)update(1,1,n,prev+1,n,n-p,0);
    }
    else if(p==q)
    {
        update(1,1,n,1,p,0,1);
        if(p!=n)update(1,1,n,p+1,n,n-p,0);
    }
    else//p>q
    {
        prev=0;
        update(1,1,n,prev+1,q,p-q,1);
        prev=q;
        if(prev<n)update(1,1,n,prev+1,prev+n-p+1,n-p,0);
        prev=prev+(n-p+1);
        if(prev<n)update(1,1,n,prev,n,0,1);
    }
}

for(int i=1;i<=n;i++)output[i]=n;

solve(1,1,n,0);
solve(1,1,n,1);

for(int i=1;i<=n;i++)printf("%i\n",output[i]);
return 0;
}