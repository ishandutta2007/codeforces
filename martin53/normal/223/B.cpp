#include<bits/stdc++.h>
using namespace std;
const int nmax=2e5+42;
string s,t;
int pr[nmax],suf[nmax];
vector<int> emp;
vector<int> tree[4*nmax];
vector<int> my_merge(vector<int> a,vector<int> b)
{
    for(int i=0;i<26;i++)
        a[i]=a[i]+b[i];
    return a;
}
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=emp;
        tree[node][t[l]-'a']++;
        return;
    }
    int av=(l+r)/2;
    build(node*2,l,av);
    build(node*2+1,av+1,r);
    tree[node]=my_merge(tree[node*2],tree[node*2+1]);
}
vector<int> query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2;
    vector<int> now=emp;
    if(lq<=av)now=my_merge(now,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)now=my_merge(now,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return now;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>s>>t;
int n=s.size(),m=t.size();
for(int i=0;i<n;i++)
{
    if(i)pr[i]=pr[i-1];
    else pr[i]=-1;
    if(pr[i]+1<m&&s[i]==t[pr[i]+1])pr[i]++;
}
for(int i=n-1;i>=0;i--)
{
    if(i==n-1)suf[i]=m;
    else suf[i]=suf[i+1];
    if(suf[i]&&s[i]==t[suf[i]-1])suf[i]--;
}
for(int i=0;i<26;i++)
    emp.push_back(0);
build(1,0,m-1);
for(int i=0;i<n;i++)
{
    if(pr[i]<suf[i])
    {
        cout<<"No"<<endl;
        return 0;
    }
    if(query(1,0,m-1,suf[i],pr[i])[s[i]-'a']==0)
    {
        cout<<"No"<<endl;
        return 0;
    }
}
cout<<"Yes"<<endl;
return 0;
}