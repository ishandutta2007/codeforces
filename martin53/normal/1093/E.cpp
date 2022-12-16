#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42,BLOCK=2000;
int n;
int a[nmax];
int b[nmax];
int hsh[nmax];
vector<int> seen[nmax/BLOCK+42];
void upd(int bl,int j,int val)
{
seen[bl][j]=val;
    while(j>0&&seen[bl][j]<seen[bl][j-1])
    {
    swap(seen[bl][j],seen[bl][j-1]);
    j--;
    }

int SZ=seen[bl].size();
    while(j+1<SZ&&seen[bl][j]>seen[bl][j+1])
    {
    swap(seen[bl][j],seen[bl][j+1]);
    j++;
    }

}
int main()
{
int m;
scanf("%i%i",&n,&m);
for(int i=1;i<=n;i++)
{
    scanf("%i",&a[i]);
    hsh[a[i]]=i;
    a[i]=hsh[a[i]];
}
for(int i=1;i<=n;i++)
{
    scanf("%i",&b[i]);
    b[i]=hsh[b[i]];
    seen[i/BLOCK].push_back(b[i]);
}

for(int i=0;i<=n/BLOCK;i++)
    sort(seen[i].begin(),seen[i].end());

int type,la,ra,lb,rb;

int l,r;

for(int i=1;i<=m;i++)
{
    scanf("%i",&type);
    if(type==1)
    {
        scanf("%i%i%i%i",&la,&ra,&lb,&rb);
        int cnt=0;
        while(lb%BLOCK&&lb<=rb)
        {
            if(la<=b[lb]&&b[lb]<=ra)cnt++;
            lb++;
        }
        while(rb%BLOCK!=BLOCK-1&&lb<=rb)
        {
            if(la<=b[rb]&&b[rb]<=ra)cnt++;
            rb--;
        }

        if(lb<=rb)
        {
            int p,q;
            for(int j=lb/BLOCK;j<=rb/BLOCK;j++)
            {
                p=lower_bound(seen[j].begin(),seen[j].end(),la)-seen[j].begin();
                q=upper_bound(seen[j].begin(),seen[j].end(),ra)-seen[j].begin();
                /*
                cout<<"seen: ";for(auto k:seen[j])cout<<k<<" ";cout<<endl;
                cout<<p<<" "<<q<<endl;
                */

                cnt=cnt+q-p;
            }
        }

        printf("%i\n",cnt);
    }
    else
    {
        scanf("%i%i",&l,&r);
        if(l/BLOCK!=r/BLOCK)
        {
            int l_BLOCK=l/BLOCK,r_BLOCK=r/BLOCK;
            for(int j=0;true;j++)
                if(seen[l_BLOCK][j]==b[l])
                {
                    upd(l_BLOCK,j,b[r]);
                    break;
                }
            for(int j=0;true;j++)
                if(seen[r_BLOCK][j]==b[r])
                {
                    upd(r_BLOCK,j,b[l]);
                    break;
                }
        }
        swap(b[l],b[r]);
    }
    /*
    cout<<"a: ";for(int j=1;j<=n;j++)cout<<a[j]<<" ";cout<<endl;
    cout<<"b: ";for(int j=1;j<=n;j++)cout<<b[j]<<" ";cout<<endl;
    */
}
return 0;
}