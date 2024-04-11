#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
int n,m;
char arr[nmax];
int fenwick[nmax];
vector<int> seen[256];
set<int> there[256];
int query(int pos)
{
    int ret=0;
    while(pos)
    {
        ret=ret+fenwick[pos];
        pos=pos-(pos&(-pos));
    }
    return ret;
}
int sum(int l,int r)
{
    return query(r)-query(l-1);
}
void update(int pos,int value)
{
    while(pos<=n)
    {
        fenwick[pos]+=value;
        pos=pos+(pos&(-pos));
    }
}
int right_search(char c,int l,int r)
{
    int ok=-1,not_ok=seen[c].size();
    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;
        if(sum(1,seen[c][av])<=r)ok=av;
        else not_ok=av;
    }
    //cout<<"ok= "<<ok<<endl;
    if(ok==-1)return -1;
    set<int>::iterator it=there[c].upper_bound(seen[c][ok]);
    if(it==there[c].begin())return -1;
    it--;
    int val=*it;
    //cout<<"val= "<<val<<endl;
    if(sum(1,val)<l)return -1;
    there[c].erase(val);
    return val;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>arr[i];
    seen[arr[i]].push_back(i);
    there[arr[i]].insert(i);
}
for(int i=1;i<=n;i++)update(i,1);

int l,r;
char c;
for(int i=1;i<=m;i++)
{
    cin>>l>>r>>c;
    while(1)
    {
        int pos=right_search(c,l,r);
        //cout<<pos<<endl;
        if(pos==-1)break;
        update(pos,-1);
        r--;
    }
    /*
    for(int j=1;j<=n;j++)
        if(sum(j,j))cout<<arr[j];cout<<endl;
    */
}
for(int i=1;i<=n;i++)
    if(sum(i,i))cout<<arr[i];cout<<endl;
return 0;
}