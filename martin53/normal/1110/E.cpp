#include<bits/stdc++.h>
#define int long long
using namespace std;
set< vector<int> > s;
set<int> t;
void run(vector<int> now)
{
    if(s.count(now))return;
    s.insert(now);
    t.insert(now[1]);
    for(auto k:now)cout<<k<<" ";cout<<endl;
    for(int i=1;i<now.size()-1;i++)
    {
        now[i]=now[i+1]+now[i-1]-now[i];
        run(now);
        now[i]=now[i+1]+now[i-1]-now[i];
    }
}
void brute()
{
//run({1,2,4,5,7});
//run({1,4,16,64,256});
//run({1,64,64,64,256});
//run({1,64,64,256});

cout<<s.size()<<endl;
for(auto k:t)cout<<k<<" ";cout<<endl;
}
const int nmax=1e5+42;
int n;
int input[nmax];
int target[nmax];
map<int, set<int> > seen;
bool test()
{
    if(input[1]!=target[1]||input[n]!=target[n])return 0;
    for(int i=1;i<n;i++)
    {
        seen[input[i]-input[i+1]].insert(i);
        //cout<<input[i]-input[i+1]<<endl;
    }

    for(int i=1;i<n;i++)
    {
        int x=target[i]-target[i+1];
        //cout<<"want= "<<x<<endl;
        if(seen[x].size()==0)return 0;
        int y=*(seen[x].begin());
        seen[x].erase(y);
    }

    return 1;
}
signed main()
{
/*
brute();
return 0;
*/
cin>>n;
for(int i=1;i<=n;i++)cin>>input[i];
for(int i=1;i<=n;i++)cin>>target[i];
cout<<(test()?"Yes":"No")<<endl;
return 0;
}