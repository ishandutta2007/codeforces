#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>

using namespace std;

const int MaxN=1010;

int n,k,nA,nB;

int c[MaxN],t[MaxN];

struct node
{
    long double cost;
    int from;
}A[MaxN],B[MaxN];

bool cmp_A(node A,node B)
{
    return A.cost>B.cost;
}

bool cmp_B(node A,node B)
{
    return A.cost<B.cost;
}

vector<int> v[MaxN];

int main()
{
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        cin>>c[i]>>t[i];
        if (t[i]==1)
        {
            ++nA;
            A[nA].cost=c[i];
            A[nA].from=i;
        }
        else
        {
            ++nB;
            B[nB].cost=c[i];
            B[nB].from=i;
        }
    }
    sort(A+1,A+nA+1,cmp_A);
    for (int i=1;i<=nA;++i)
    {
        v[min(i,k)].push_back(A[i].from);
    }
    for (int i=1;i<=nB;++i)
    {
        int flag=0;
        for (int j=1;j<=k;++j)
            if (v[j].empty())
            {
                flag=1;
                v[j].push_back(B[i].from);
                break;
            }
        if (flag) continue;
        v[k].push_back(B[i].from);
    }
    long double ans=0;
    for (int i=1;i<=k;++i)
    {
        long double tmp=1000000000;
        for (vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
        {
            if (c[*it]<tmp) tmp=c[*it];
            ans+=c[*it];
        }
        if (i<=nA)
            ans-=(tmp/((long double)2));
    }
    cout<<setprecision(1)<<fixed<<ans<<endl;
    for (int i=1;i<=k;++i)
    {
        cout<<v[i].size();
        for (vector<int>::iterator it=v[i].begin();it!=v[i].end();++it)
            cout<<" "<<(*it);
        cout<<endl;
    }
    return 0;
}