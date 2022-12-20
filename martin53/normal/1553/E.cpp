#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,m,inp[nmax];

int proper[nmax];

int start[nmax];

int hsh[nmax];

int given[nmax];

bool been[nmax];

bool test(int t)
{
    for(int i=0;i<n;i++)
        start[i]=(i-t+n)%n;

    for(int i=0;i<n;i++)
        hsh[start[i]]=i;

    for(int i=0;i<n;i++)
    {
        given[i]=hsh[inp[i]];
        been[i]=0;
    }

    //cout<<"test "<<t<<" : ";for(int i=0;i<n;i++)cout<<given[i]<<" ";cout<<endl;

    int need=0;

    for(int i=0;i<n;i++)
        if(been[i]==0)
        {
            int j=i;

            need--;

            while(been[j]==0)
            {
                need++;

                been[j]=1;

                j=given[j];
            }
        }

    return need<=m;
}
void solve()
{
    scanf("%i%i",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%i",&inp[i]);
        inp[i]--;
    }

    for(int i=0;i<n;i++)proper[i]=0;

    for(int i=0;i<n;i++)
    {
        int t=(i-inp[i]+n)%n;

        proper[t]++;
    }

    vector<int> outp={};
    for(int i=0;i<n;i++)
        if(proper[i]>=n-2*m)
        {
            if(test(i))outp.push_back(i);
        }

    //cout<<"outp: ";

    printf("%i",outp.size());

    for(auto w:outp)printf(" %i",w);

    printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}