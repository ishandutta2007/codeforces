#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
int n,i,q;
const int N = 3e5+10;
int ans[N];
vector<int>  follow[N];
int val[N];
bool used[N];

struct triple
{
    int first,second,third;
};

bool operator < (triple &x, triple &y)
{
    if(x.first != y.first)
        return (x.first < y.first);
    if(x.second != y.second)
        return (x.second < y.second);
    return (x.third <= y.third);
}

triple query[N];

struct fenwickTree
{
private:
    int n;
    vector<int> bits;
public:
    fenwickTree(int n)
    {
        this -> n = n;
        for(int i = 0 ;i < n; i++)
            bits.push_back(0);
    }
    void add(int idx, int val)
    {
        for(;idx<n;idx = idx|(idx+1))
            bits[idx]+=val;
    }
    int sum(int r)
    {
        int sum = 0;
        for(;r>=0; r = (r&(r+1))-1)
            sum+=bits[r];
        return sum;
    }
    int sum(int l, int r)
    {
        return sum(r) - sum(l-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    fenwickTree thisTree = fenwickTree(N);
    fenwickTree verifyTree = fenwickTree(N);
    cin>>n>>q;
    for(i=0;i<n;i++)
    {
        cin>>val[i];
        val[i]-=i;
    }
    for(i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        query[i] = {a,b,i};
    }
    sort(query,query+q);
    for(i=0;i<n;i++)
    {
        if(val[i]<1)
        {
            int mini = 0, maxi = i, left = 1-val[i];
            if( verifyTree.sum(i) < left )
                continue;

            while(mini < maxi)
            {
                int mid = mini + maxi >> 1;
                if( mini == mid )
                {
                    int as = verifyTree.sum(maxi,i);
                    if( as >= left )
                        mini = maxi;
                    else
                        maxi = mini;
                }
                else
                {
                    int as = verifyTree.sum(mid,i);
                    if( as >= left )
                        mini = mid;
                    else
                        maxi = mid;
                }
            }

            verifyTree.add(mini,1);
            follow[mini].push_back(i);
            used[i] = true;
        }
        else if(val[i] == 1)
        {
            verifyTree.add(i,1);
            follow[i].push_back(i);
            used[i] = true;
        }
    }
    for( i = 0 ; i < n ; i++ )
    {
        if( used[i] )
            thisTree.add(i,1);
    }
    int pointer = 0;
    for(i=0;i<q;i++)
    {
        int l = query[i].first;
        int r = query[i].second;
        while(pointer < l)
        {
            for(auto it: follow[pointer])
                thisTree.add(it,-1);
            pointer++;
        }
        ans[query[i].third] = thisTree.sum(l,n-1-r);
    }

    for(i=0;i<q;i++)
    {
        cout<<ans[i]<<"\n";
    }
    return 0;
}