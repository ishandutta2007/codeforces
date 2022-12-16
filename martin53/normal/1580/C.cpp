#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,MX=512;

int n,m;
pair<int,int> inp[nmax];

int on[nmax];

int cnt[MX][MX];

void push_slow(int i,int coeff)
{
    //cout<<"push slow "<<i<<" "<<coeff<<" "<<on[i]<<endl;

    int SZ=inp[i].first+inp[i].second;

    for(int t=inp[i].first;t<SZ;t++)
        cnt[inp[i].first+inp[i].second][(on[i]+t)%SZ]+=coeff;
}

int T_now=0,fenwick_add=0;
int add[nmax];

void upd(int l,int r,int coeff)
{
    //cout<<"upd "<<l<<" "<<r<<" "<<coeff<<endl;

    if(l<=T_now&&T_now<=r)fenwick_add+=coeff;

    if(l<=m)add[l]+=coeff;
    if(r+1<=m)add[r+1]-=coeff;
}

void push_fenwick(int i,int coeff)
{
    int SZ=inp[i].first+inp[i].second;

    for(int j=on[i];j<=m;j+=SZ)
        upd(j+inp[i].first,j+inp[i].first+inp[i].second-1,coeff);
}

int query(int i)
{
    T_now++;
    fenwick_add+=add[T_now];

    int ret=fenwick_add;

    for(int t=1;t<MX;t++)
        ret+=cnt[t][i%t];

    return ret;
}

int main()
{
    memset(on,-1,sizeof(on));

    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    for(int i=1;i<=m;i++)
    {
        int type,id;
        scanf("%i%i",&type,&id);

        if(inp[id].first+inp[id].second<MX)
        {
            if(type==1)on[id]=i;

            push_slow(id,type==1?1:-1);
        }
        else
        {
            if(type==1)on[id]=i;

            push_fenwick(id,type==1?1:-1);
        }

        printf("%i\n",query(i));
    }

    return 0;
}