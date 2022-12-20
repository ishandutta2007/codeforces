#include<bits/stdc++.h>
using namespace std;

const int nmax=(1<<16)+42;

int n;

int outp[nmax];

int ask(string cur,int i,int j)
{
    if(i>j)swap(i,j);

    cout<<cur<<" "<<i<<" "<<j<<endl;
    cout.flush();

    int ret=0;
    cin>>ret;
    return ret;
}

int mem[5];

void solve()
{
    for(int i=2;i<=n;i++)
        outp[i]=outp[i]^outp[1];

    cout<<"!";for(int i=1;i<=n;i++)cout<<" "<<outp[i];cout<<endl;
    exit(0);
}

int seen[nmax];

int main()
{
    cin>>n;

    for(int i=2;i<=n;i++)
        outp[i]=ask("XOR",1,i);

    for(int i=2;i<=n;i++)
        if(outp[i]==0)
        {
            //cout<<"case 1"<<endl;

            outp[1]=ask("AND",1,i);
            solve();
        }

    for(int i=2;i<=n;i++)
        if(seen[outp[i]])
        {
            //cout<<"case 2"<<endl;

            int pos=seen[outp[i]];

            int at_pos=ask("AND",pos,i);

            outp[1]=outp[pos]^at_pos;

            solve();
        }
        else seen[outp[i]]=i;

    for(int i=2;i<=n;i++)
        if(outp[i]==n-1)
        {
            //cout<<"case 3"<<endl;

            int third=2;

            if(third==i)third=3;

            /*x1^xi=n-1
            x1^xthird=outp[third]
            xi^xthird=(n-1)^outp[third]
            */

            int xr[3]={n-1,outp[third],(n-1)^outp[third]};

            int sum[3]={n-1,xr[1]+2*ask("AND",1,third),xr[2]+2*ask("AND",i,third)};

            int s=(sum[0]+sum[1]+sum[2])/2;

            outp[1]=s-sum[2];

            solve();
        }

    return 0;
}