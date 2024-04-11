#include<bits/stdc++.h>
using namespace std;
/*
int sg(int x)
{
if(x==0)return 0;
vector<int> mem(x+1,0);
mem[sg(x-1)]=1;
if(x%2==0)mem[sg(x/2)]=1;
int p=0;
while(mem[p])p++;
return p;
}
*/
map< vector<int>, int> seen;
int real_sg(vector<int> state)
{
sort(state.begin(),state.end());
if(state.size()==0)return 0;
if(seen.count(state))return seen[state];
int SZ=state.size();
for(int i=0;i<SZ;i++)
    if(state[i]==0)
    {
    state.erase(state.begin()+i);
    return real_sg(state);
    }

//for(auto k:state)cout<<k<<" ";cout<<endl;

set<int> mem;
mem.clear();
for(int i=0;i<SZ;i++)
{
    state[i]--;
    mem.insert(real_sg(state));
    state[i]++;
}
//cout<<"passed"<<endl;
for(int i=0;i<SZ;i++)
    if(state[i]%2==0)
    {
        vector<int> help={};
        for(int j=0;j<SZ;j++)
            if(j!=i)help.push_back(state[j]);

            //cout<<"i= "<<i<<endl;
            help.push_back(state[i]/2);
            mem.insert(real_sg(help));
    }
for(int i=0;true;i++)
    if(mem.count(i)==0)
    {
    seen[state]=i;
    return i;
    }
}

bool check(int x)
{
if(x%3)return 0;
x=x/3;
int t=0;
while(x%2==0)
{
x=x/2;
t++;
}
if(x==1&&t%2==0)return 1;
return 0;
}
bool check2(int x)
{
    int t=0;
    while(x%2==0)
    {
    x=x/2;
    t++;
    }
    return x!=3&&(t%2==1);
}
int sg(int x)
{
if(x==0||x==2)return 0;
if(x%2==1&&x>=5)return 0;

if(x==1)return 1;
if(x==6)return 2;
if(x==8)return 1;
if(check(x))return 1;
if(check2(x))return 1;

return 2;
}
int main()
{
/*
for(int i=0;i<=100;i++)
{
cout<<i<<" -> "<<sg(i)<<endl;
}
*/
/*
for(int i=0;i<=100;i++)
{
cout<<i<<" -> "<<sg({i})<<endl;
}
*/
//sg(a[i],k)=sg(a[i],k-2)
//k=1->oeis
//k=2->x<=2->sg(x)=x; x>2->sg(x)=1-x%2
/*
for(int i=1;i<=100;i++)
{
    cout<<i<<" -> "<<sg(i)<<" "<<real_sg({i})<<endl;
    assert(sg(i)==real_sg({i}));
}
return 0;
*/
int n,k;
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n>>k;
int x;
long long ans=0;
for(int i=1;i<=n;i++)
{
cin>>x;
    if(k%2==0)
    {
    if(x<=2)ans=ans^x;
    else ans=ans^(1-x%2);
    }
    else
    {
        ans=ans^sg(x);
    }
}
if(ans)cout<<"Kevin"<<endl;
else cout<<"Nicky"<<endl;
return 0;
}