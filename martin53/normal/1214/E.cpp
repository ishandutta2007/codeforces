#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];

pair<int/*dist*/,int/*id*/> seen[nmax];

bool cmp(pair<int/*dist*/,int/*id*/> a,pair<int/*dist*/,int/*id*/> b)
{
    return a.first>b.first;
}

vector< int > there[nmax];

int order[nmax];

int where[nmax];

vector< pair<int,int> > output;
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
        seen[i]={inp[i],2*i};

    sort(seen+1,seen+n+1,cmp);

    int pos=1;
    for(int i=1;i<=n+1;i++)
    {
        //cout<<i<<" "<<pos<<endl;
        if(there[pos].size())
        {
            order[pos]=there[pos][0];
            pos++;
            i--;
            continue;
        }

        if(i>n)break;

        order[pos]=seen[i].second;
        there[pos+seen[i].first].push_back(seen[i].second-1);

        //cout<<"there at "<<pos+seen[i].first<<endl;

        pos++;
    }

    pos--;
    //for(int i=1;i<=pos;i++)cout<<order[i]<<" ";cout<<endl;
    for(int i=1;i<=pos;i++)
        where[order[i]]=i;

    for(int i=1;i<pos;i++)
        output.push_back({order[i],order[i+1]});

    for(int i=2;i<=2*n;i=i+2)
        if(where[i-1]==0)
        {
            int d=inp[i/2],other=-1;
            if(where[i]>=d)other=where[i]-d+1;
            else if(where[i]<=pos-d+1)other=where[i]+d-1;
            else assert(0==1);

            //cout<<"add: "<<i-1<<" "<<order[other]<<endl;

            output.push_back({i-1,order[other]});
        }

    for(auto k:output)
        printf("%i %i\n",k.first,k.second);
    return 0;
}