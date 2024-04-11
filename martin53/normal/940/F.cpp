#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42/*500*/,BLOCK=2500/*2*/,MX=nmax/BLOCK+5;
int n,q,arr[nmax],help[nmax];
struct query
{
    int when,l,r;
};
vector<query> Q[MX][MX];

bool cmp(query a,query b)
{
    return a.r<b.r;
}
struct update
{
    int when,pos,value;
};

vector<update> updates;

vector<int> v;

int seen[2*nmax];

int c[2*nmax];

int output[nmax];

void add(int p)
{
    seen[c[help[p]]]--;
    c[help[p]]++;
    seen[c[help[p]]]++;
}
void remove(int p)
{
    seen[c[help[p]]]--;
    c[help[p]]--;
    seen[c[help[p]]]++;
}
int main()
{
cin>>n>>q;

for(int i=1;i<=n;i++)
{
    cin>>arr[i];
    v.push_back(arr[i]);
}

int type,l,r;
for(int i=1;i<=q;i++)
{
    cin>>type>>l>>r;
    if(type==1)
    {
        query now;
        now.when=i;
        now.l=l;
        now.r=r;
        Q[l/BLOCK][r/BLOCK].push_back(now);
    }
    else
    {
        update now;
        now.when=i;
        now.pos=l;
        now.value=r;
        updates.push_back(now);
        v.push_back(r);
    }
}

sort(v.begin(),v.end());

for(int i=1;i<=n;i++)
{
    arr[i]=lower_bound(v.begin(),v.end(),arr[i])-v.begin();
}

for(auto &k:updates)
{
    k.value=lower_bound(v.begin(),v.end(),k.value)-v.begin();
}
/*
for(int i=1;i<=n;i++)cout<<arr[i]<<" ";cout<<endl;
for(auto k:updates)cout<<k.value<<" ";cout<<endl;
*/

for(int i=0;i<MX;i++)
    for(int j=i;j<MX;j++)
    if(Q[i][j].size())
    {
        memset(seen,0,sizeof(seen));
        memset(c,0,sizeof(c));
        seen[0]=n;
        for(int k=1;k<=n;k++)help[k]=arr[k];

        if(i==j)
        {
            int prev=0;
            for(auto k:Q[i][j])
            {
                while(prev<updates.size()&&updates[prev].when<k.when)
                {
                    help[updates[prev].pos]=updates[prev].value;
                    prev++;
                }

                for(int p=k.l;p<=k.r;p++)
                    add(p);

                int o=1;
                while(seen[o])o++;

                output[k.when]=o;

                for(int p=k.l;p<=k.r;p++)
                    remove(p);

            }
        }
        else
        {
            int l=(i+1)*BLOCK,r=j*BLOCK-1;

            for(int j=l;j<=r;j++)
                add(j);

            int prev=0;
            for(auto k:Q[i][j])
            {
                //cout<<i<<" "<<j<<" -> "<<l<<" "<<r<<" "<<k.when<<" "<<k.l<<" "<<k.r<<endl;

                while(prev<updates.size()&&updates[prev].when<k.when)
                {
                    //cout<<"update "<<updates[prev].when<<" "<<updates[prev].pos<<" "<<updates[prev].value<<endl;

                    if(l<=updates[prev].pos&&updates[prev].pos<=r)
                        remove(updates[prev].pos);

                    help[updates[prev].pos]=updates[prev].value;

                    if(l<=updates[prev].pos&&updates[prev].pos<=r)
                        add(updates[prev].pos);

                    prev++;
                }

                for(int p=k.l;p<l;p++)
                    add(p);

                for(int p=r+1;p<=k.r;p++)
                    add(p);

                int o=1;
                while(seen[o])o++;

                output[k.when]=o;

                for(int p=k.l;p<l;p++)
                    remove(p);

                for(int p=r+1;p<=k.r;p++)
                    remove(p);

            }

        }
    }


for(int i=1;i<=q;i++)
    if(output[i])cout<<output[i]<<"\n";
return 0;
}