#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int chtholly = 0;
const int N = 1e5;
int n,m,h,k,i,mini = 1e9,index;
vector<pii> train;
map<int,int> mp;

int main()
{
    cin>>n>>h>>m>>k;
    for(i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        train.push_back({b%(m/2),i+1});
    }
    for(i=0;i<n;i++)
    {
        pii cur = train[i];
        train.push_back({cur.first+m/2,cur.second});
    }
    sort(train.begin(),train.end());
    int pointer1 = 0, pointer2 = 0;
    while(pointer1<n)
    {
        while(train[pointer1].first == train[pointer1+1].first)
            pointer1++;
        while(train[pointer2].first - train[pointer1].first<k)
            pointer2++;
        if(pointer2-pointer1-1 < mini)
        {
            mini = pointer2 - pointer1-1;
            index = pointer1;
        }
        pointer1++;
    }
    cout<<mini<<" "<<(train[index].first+k)%(m/2)<<"\n";
    pointer1 = index;
    pointer2 = pointer1+1;
    while(train[pointer2].first - train[pointer1].first<k)
    {
        cout<<train[pointer2].second<<" ";
        pointer2++;
    }
    return chtholly;
}