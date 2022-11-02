#include<bits/stdc++.h>
using namespace std;
const int N = 262144;
int arr[3];

struct lazyTree
{
private:
    int n;
    vector<pair<int,int>> rang;
    vector<long long> ma;
    vector<long long> lazy;
public:
    lazyTree(int n)
    {
        n=2*n+1;
        this -> n = n;
        int i;
        for(i=0;i<2*n;i++)
        {
            ma.push_back(0LL);
            lazy.push_back(0LL);
        }
        rang.push_back({0,0});
        rang.push_back({1,n/2});
        queue<int> qu;
        qu.push(2);
        qu.push(3);
        while(!qu.empty())
        {
            int node = qu.front();
            qu.pop();
            int siz = rang[node/2].second - rang[node/2].first +1;
            siz/=2;
            int mid = (rang[node/2].second + rang[node/2].first)/2;
            if(node%2==0)
                rang.push_back({rang[node/2].first,mid});
            else
                rang.push_back({mid+1,rang[node/2].second});
            if(siz > 1)
                qu.push(2*node), qu.push(2*node+1);
            //cout<<node<<" "<<node/2<<" "<<siz<<" "<<rang[node].first<<" "<<rang[node].second<<" "<<qu.size()<<"\n";
        }
    }
    void update(int idx)
    {
        ma[idx] +=lazy[idx];
        if(rang[idx].first != rang[idx].second)
            lazy[2*idx]+=lazy[idx], lazy[2*idx+1]+=lazy[idx];
        lazy[idx] = 0LL;
    }
    void add(int l, int r, int idx, long long val)
    {
        update(idx);
        if(l>=rang[idx].first && r<=rang[idx].second)
        {
            if(l==rang[idx].first && r==rang[idx].second)
            {
                if(l!=r)
                    lazy[2*idx]+=val,lazy[2*idx+1]+=val;
                ma[idx]+=val;
            }
            else
            {
                int mid = rang[idx].first+rang[idx].second >>1;
                if(l<=mid)
                    add(l,min(mid,r),2*idx,val);
                if(r>=mid+1)
                    add(max(l,mid+1),r,2*idx+1,val);
                update(2*idx);
                update(2*idx+1);
                ma[idx] = min(ma[2*idx],ma[2*idx+1]);
            }
        }
    }
    long long query(int l, int r, int idx)
    {
        update(idx);
        if(l>=rang[idx].first && r<=rang[idx].second)
        {
            if(l==rang[idx].first && r==rang[idx].second)
            {
                return ma[idx];
            }
            else
            {
                long long can1 = 1e18, can2 = 1e18;
                int mid = rang[idx].first + rang[idx].second >> 1;
                if(l <= mid)
                    can1 = query(l,min(r,mid),2*idx);
                if(r>=mid+1)
                    can2 = query(max(l,mid+1),r,2*idx+1);
                return min(can1,can2);
            }
        }
    }
    void print()
    {
        for(auto it: ma)
        {
            cout<<it<<" ";
        }
    }
};

void process()
{
    arr[0]=0,arr[1]=0,arr[2]=0;
    string s;
    bool minu = false;
    getline(cin,s);
    int j=0,k=0;
    for(j=0;j<s.size();j++)
    {
        if(s.at(j)!=' ' && s.at(j)!='-')
            arr[k]*=10, arr[k]+=s.at(j)-'0';
        else if(s.at(j)=='-')
            minu = true;
        else
        {
            if(minu)
                arr[k]*=-1;
            k++;
        }
    }
    if(minu)
        arr[k]*=-1;
    arr[1]++,arr[0]++;
    if(k==1)
        arr[2] = -1e9;
}

int main()
{
    int n,m,i;
    cin>>n;
    lazyTree thisTree(N);
    for(i=0;i<n;i++)
    {
        long long a;
        cin>>a;
        thisTree.add(i+1,i+1,1,a);
    }
    cin>>m;
    for(i=0;i<m+1;i++)
    {
        process();
        if(arr[2]==-1e9)
        {
            if(arr[1]<arr[0])
            {
                long long can1=-1e18,can2=-1e18;
                can1 = thisTree.query(arr[0],n,1);
                can2 = thisTree.query(1,arr[1],1);
                cout<<min(can1,can2)<<"\n";
            }
            else
            {
                cout<<thisTree.query(arr[0],arr[1],1)<<"\n";
            }
        }
        else
        {
            if(arr[1]<arr[0])
            {
                thisTree.add(arr[0],n,1,arr[2]);
                thisTree.add(1,arr[1],1,arr[2]);
            }
            else
            {
                thisTree.add(arr[0],arr[1],1,arr[2]);
            }
        }
    }
    return 0;
}