#include<iostream>
#include<vector>

using namespace std;

const long long MAXN=100005;
long long n,node[4*MAXN],ans=0,pter;
vector<long long> ele[MAXN];

void build_tree(long long i,long long left,long long right)
{
    if(left==right){ node[i]=1; return ; }
    long long mid=(left+right)/2;
    build_tree(i*2,left,mid); build_tree(i*2+1,mid+1,right);
    node[i]=node[i*2]+node[i*2+1];
}

void update(long long i,long long left,long long right,long long pos)
{
    if(pos<left||right<pos) return ;
    if(left==right){ node[i]=0; return ; }
    long long mid=(left+right)/2;
    update(i*2,left,mid,pos); update(i*2+1,mid+1,right,pos);
    node[i]=node[i*2]+node[i*2+1];
}

long long get(long long i,long long left,long long right,long long a,long long b)
{
    if(right<a||b<left) return 0;
    if(a<=left&&right<=b) return node[i];
    long long mid=(left+right)/2;
    return get(i*2,left,mid,a,b)+get(i*2+1,mid+1,right,a,b);
}

int main()
{
    cin>>n;
    for(long long i=1;i<=n;++i)
    {
        long long x;
        cin>>x;
        ele[x].push_back(i);
    }

    build_tree(1,1,n);

    pter=1;

    for(long long i=1;i<MAXN;++i)
    {
        if(ele[i].size()==0) continue;
        long long gioihan=0;
        for(long long j=0;j<ele[i].size();++j)
        {
            if(ele[i][j]>=pter){ gioihan=j; break; }
        }
        for(long long j=0;j<ele[i].size();++j)
        {
            long long x=(j+gioihan)%ele[i].size();
            //cout<<ele[i][x]<<"\n";
            if(ele[i][x]<pter)
            {
                ans+=get(1,1,n,pter,n);
                pter=1;
            }
            ans+=get(1,1,n,pter,ele[i][x]);
            //cout<<"ans="<<ans<<endl;
            update(1,1,n,ele[i][x]);
            pter=ele[i][x];
        }
    }

    cout<<ans;

    return 0;
}