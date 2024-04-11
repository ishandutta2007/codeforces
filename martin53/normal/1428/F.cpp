#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

string inp;

int pointer;

pair<int/*size*/,int/*type*/> seen[nmax];

int pref[nmax];

int tree[4*nmax];
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=seen[l].first;

        if(seen[l].second==0)tree[node]=0;

        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

int query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];

    int av=(l+r)/2,ret=0;

    if(lq<=av)ret=max(ret,query(node*2,l,r,lq,min(av,rq)));
    if(av<rq)ret=max(ret,query(node*2+1,av+1,r,max(av+1,lq),rq));

    return ret;
}
long long eval(long long d)
{
    return d*(d+1)/2*(d+1)-d*(d+1)*(2*d+1)/6;//!
}

long long outp=0;

vector<int> zero;

int nxt[nmax];

void solve(int l,int r)
{
    //cout<<"solve "<<l<<" "<<r<<endl;

    if(l>r)return;

    if(l==r)
    {
        if(inp[l]=='1')outp++;

        return;
    }

    //int p=lower_bound(zero.begin(),zero.end(),l)-zero.begin();

    //int q=upper_bound(zero.begin(),zero.end(),r)-zero.begin()-1;

    int p=nxt[l];

    int q=nxt[r+1]-1;

    //cout<<"p= "<<p<<" q= "<<q<<endl;

    if(p>q)
    {
        //cout<<"cheat "<<l<<" "<<r<<" -> "<<eval(r-l+1)<<endl;

        outp+=eval(r-l+1);
        return;//only ones
    }

    int mid=zero[(p+q)/2];

    if(r==mid)mid--;

    //cout<<"mid= "<<mid<<endl;

    //cout<<"solve "<<l<<" "<<r<<" "<<mid<<endl;

    //system("pause");

    solve(l,mid);
    solve(mid+1,r);

    vector<int> LHS={},RHS={};

    vector<long long> sum={};

    int prv=0,mx=0;

    long long cur_sum=0;


    for(int i=mid;i>=l;i--)
    {
        if(inp[i]=='0')prv=0;
        else prv++;

        mx=max(mx,prv);
        LHS.push_back(mx);

        cur_sum+=mx;
        sum.push_back(cur_sum);

        //cout<<i<<" -> "<<mx<<endl;
    }

    int pointer=0;

    prv=0,mx=0;
    for(int i=mid+1;i<=r;i++)
    {
        if(inp[i]=='0')prv=0;
        else prv++;

        mx=max(mx,prv);

        RHS.push_back(mx);

        //int help_1=lower_bound(LHS.begin(),LHS.end(),mx)-LHS.begin();

        while(pointer<LHS.size()&&LHS[pointer]<mx)pointer++;

        //cout<<i<<" -> "<<help_1<<" "<<help_1*mx<<" "<<sum[LHS.size()-1]<<" "<<(help_1?sum[help_1-1]:0)<<endl;

        outp+=1LL*pointer*mx;

        outp+=sum[LHS.size()-1]-(pointer?sum[pointer-1]:0);

        //cout<<i<<" -> "<<mx<<endl;
    }

    //cout<<outp<<" ---"<<endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    int n;

    cin>>n;

    cin>>inp;

    memset(nxt,-1,sizeof(nxt));

    for(int i=0;i<n;i++)
        if(inp[i]=='0')
        {
            nxt[i]=zero.size();
            zero.push_back(i);
        }

    nxt[n+1]=zero.size();
    for(int i=n;i>=0;i--)
        if(nxt[i]==-1)nxt[i]=nxt[i+1];

    solve(0,inp.size()-1);

    printf("%lld\n",outp);
    return 0;
}