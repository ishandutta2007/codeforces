#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=2*1e5+42,inf=1e9+1e6;
int n,k;
string inp[nmax];
pair<int/*value*/,int/*index*/> seen[nmax];
long long outp[nmax];
long long take(string s)
{
    int mult=1;
    long long ret=0;
    for(auto k:s)
        if(k=='-')mult=-1;
        else ret=ret*10+(k-'0');
    return ret*mult;
}
void make(int i)
{
    /*
    cout<<"make "<<i<<endl;
    cout<<outp[i]<<" "<<seen[i%k].first<<" "<<seen[i%k].second<<endl;
    */
    if(seen[i%k].first>=0&&outp[i]>=0)
    {
        int now=seen[i%k].first;
        for(int j=seen[i%k].second+k;j<i;j=j+k)
        {
            now++;
            outp[j]=now;
        }

        for(int j=seen[i%k].second+k;j<i&&j<n;j=j+k)
            if(j-k>=0&&outp[j-k]>=outp[j])
            assert(0==1);
        return;
    }

    if(seen[i%k].first<=0&&outp[i]<=0)
    {
        int now=outp[i];
        for(int j=i-k;j>seen[i%k].second;j=j-k)
        {
            now--;
            outp[j]=now;
        }

        for(int j=seen[i%k].second+k;j<i&&j<n;j=j+k)
            if(j-k>=0&&outp[j-k]>=outp[j])
            {
                cout<<":("<<endl;
                exit(0);
            }
        return;
    }

    int d=(i-seen[i%k].second)/k-1;
    //cout<<seen[i%k].second<<endl;
    //cout<<"d= "<<d<<endl;
    if(d==0)return;
    deque<int> help={0};
    for(int v=1;help.size()<d;v++)
    {
        if(seen[i%k].first<-v)help.push_front(-v);
        if(help.size()==d)break;
        if(outp[i]>v)help.push_back(v);
    }
    for(int p=seen[i%k].second+k;p<i;p=p+k)
    {
        if(help.size()==0)
        {
            cout<<"y"<<endl;
            exit(0);
        }
        outp[p]=help.front();
        help.pop_front();
    }

    if(help.size())
    {
        cout<<"qqq"<<endl;
        exit(0);
    }

    for(int j=seen[i%k].second+k;j<i&&j<n;j=j+k)
            if(j-k>=0&&outp[j-k]>=outp[j])
            {
                cout<<":("<<endl;
                exit(0);
            }
}
signed main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>k;
for(int i=0;i<n;i++)cin>>inp[i];
for(int i=0;i<k;i++)seen[i]={-(inf),i-k};
for(int i=0;i<n;i++)
    if(inp[i]!="?")
    {
        outp[i]=take(inp[i]);
        if(seen[i%k].first+(i-seen[i%k].second)/k<=outp[i])
        {
            make(i);
        }
        else
        {
        cout<<"Incorrect sequence"<<endl;
        return 0;
        }
        seen[i%k]={outp[i],i};
        //cout<<"after "<<i<<" : ";for(int j=0;j<n;j++)cout<<outp[j]<<" ";cout<<endl;
    }

for(int i=n;i-k+1<=n;i++)
        if(seen[i%k].second+k!=i)
        {
        outp[i]=inf;
        make(i);
        }

for(int i=0;i<n;i++)cout<<outp[i]<<" ";cout<<endl;
return 0;
}