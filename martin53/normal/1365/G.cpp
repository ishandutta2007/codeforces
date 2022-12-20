#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n;

int mask[nmax],pointer;

void gen()
{
    for(int i=1;pointer<n;i++)
    {
        int cnt=0;

        int j=i;
        while(j)
        {
            if(j%2)cnt++;
            j=j/2;
        }

        if(cnt==6)
        {
            pointer++;
            mask[pointer]=i;
        }

    }
}

vector<int> query[20];

long long mem[nmax];

int main()
{
    cin>>n;

    gen();

    for(int i=1;i<=n;i++)
        for(int j=0;j<13;j++)
            if((mask[i]&(1<<j)))query[j].push_back(i);

    for(int i=0;i<13;i++)
    {
        if(query[i].size()==0)continue;

        cout<<"? "<<query[i].size();
        for(auto k:query[i])
            cout<<" "<<k;
        cout<<endl;
        cout.flush();

        cin>>mem[i];
    }

    cout<<"!";
    for(int i=1;i<=n;i++)
    {
        long long ret=0;
        for(int j=0;j<13;j++)
        {
            bool take=1;
            for(auto w:query[j])
                if(w==i)take=0;

            if(take)ret=ret|mem[j];
        }

        cout<<" "<<ret;
    }
    cout<<endl;

    return 0;
}