#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,q,at_least;

int input[nmax];

struct info
{
    long long sum;
    int l,r;
    vector< pair<int/*value*/,int/*position*/> > from_left,from_right;
};

info tree[nmax*4];

void init(int node,int pos)
{
    info ret;
    ret.sum=(input[pos]>=at_least);
    ret.l=pos;
    ret.r=pos;

    ret.from_left={{input[pos],pos}};
    ret.from_right={{input[pos],pos}};

    tree[node]=ret;
}

info my_merge(info l,info r)
{
    if(l.l==0)return r;
    if(r.r==0)return l;

    info ret;
    ret.l=l.l;
    ret.r=r.r;

    ret.from_left=l.from_left;
    for(auto k:r.from_left)
    {
        if((ret.from_left[ret.from_left.size()-1].first|k.first)!=ret.from_left[ret.from_left.size()-1].first)
        {
            ret.from_left.push_back({ret.from_left[ret.from_left.size()-1].first|k.first,k.second});
        }
    }

    ret.from_right=r.from_right;
    for(auto k:l.from_right)
    {
        if((ret.from_right[ret.from_right.size()-1].first|k.first)!=ret.from_right[ret.from_right.size()-1].first)
        {
            ret.from_right.push_back({ret.from_right[ret.from_right.size()-1].first|k.first,k.second});
        }
    }

    ret.sum=l.sum+r.sum;

    int i=l.from_right.size()-1;

    //cout<<ret.l<<" "<<ret.r<<" : "<<endl;

    for(int j=0;j<r.from_left.size();j++)
    {
        while(i>=0&&(r.from_left[j].first|l.from_right[i].first)>=at_least)i--;

        long long mult_1=0;
        i++;
        if(i<l.from_right.size())mult_1=l.from_right[i].second-l.l+1;
        i--;

        long long mult_2=0;
        if(j+1==r.from_left.size())mult_2=r.r+1-r.from_left[j].second;
        else mult_2=r.from_left[j+1].second-r.from_left[j].second;

        //cout<<mult_1<<" "<<mult_2<<" i= "<<i<<endl;

        ret.sum=ret.sum+mult_1*mult_2;
    }
    /*
    cout<<ret.sum<<endl;
    cout<<"from_left: ";for(auto k:ret.from_left)cout<<k.first<<" "<<k.second<<"\t";cout<<endl;
    cout<<"from_right: ";for(auto k:ret.from_right)cout<<k.first<<" "<<k.second<<"\t";cout<<endl;
    cout<<"---"<<endl;
    */
    return ret;
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        init(node,l);
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}

void update(int node,int l,int r,int pos)
{
    if(l==r)
    {
        init(node,l);
        return;
    }
    int av=(l+r)/2;
    if(pos<=av)update(node*2,l,av,pos);
    else update(node*2+1,av+1,r,pos);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
info query(int node,int l,int r,int lq,int rq)
{
    //cout<<"query "<<node<<" "<<l<<" "<<r<<" "<<lq<<" "<<rq<<endl;
    if(l==lq&&r==rq)return tree[node];
    info ret;
    ret.l=0;
    ret.r=0;
    int av=(l+r)/2;
    if(lq<=av)ret=my_merge(ret,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)ret=my_merge(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return ret;
}
int main()
{
    scanf("%i%i%i",&n,&q,&at_least);

    for(int i=1;i<=n;i++)scanf("%i",&input[i]);

    build(1,1,n);

    int type,x,y;
    for(int i=1;i<=q;i++)
    {
        scanf("%i%i%i",&type,&x,&y);
        if(type==1)
        {
            input[x]=y;
            update(1,1,n,x);
        }
        else
        {
            printf("%lld\n",query(1,1,n,x,y).sum);
        }
    }
    return 0;
}