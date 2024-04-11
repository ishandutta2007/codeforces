#include<bits/stdc++.h>
using namespace std;
const int nmax=10e5+42,bonus=2e5+1;
bool vowel(char x)
{
return x=='a'||x=='e'||x=='o'||x=='u'||x=='i'||x=='A'||x=='E'||x=='O'||x=='U'||x=='I';
}
int tree[2*4*nmax];
string inp;
int n;
void check()
{
    for(int i=0;i<n;i++)
        if(vowel(inp[i])==0)return;
    cout<<"No solution"<<endl;
    exit(0);
}
int query(int node,int l,int r,int lq,int rq)
{
    if(l==lq&&r==rq)return tree[node];
    int av=(l+r)/2,mini=1e9;
    if(lq<=av)mini=min(mini,query(node*2,l,av,lq,min(av,rq)));
    if(av<rq)mini=min(mini,query(node*2+1,av+1,r,max(av+1,lq),rq));
    return mini;
}
void update(int node,int l,int r,int value,int position)
{
    //cout<<l<<" "<<r<<" "<<position<<endl;
    if(l==r)
    {
        //assert(l==position);
        tree[node]=min(tree[node],value);
        return;
    }
    int av=(l+r)/2;
    if(position<=av)update(node*2,l,av,value,position);
    else update(node*2+1,av+1,r,value,position);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}
void add(int value,int pos)
{
    //cout<<"update "<<value<<" "<<pos<<endl;
    update(1,1,2*nmax-1,pos,value+bonus);
}
int ask(int pos,int value)
{
    //cout<<"query "<<value<<" "<<pos<<endl;
    int where=query(1,1,2*nmax-1,1,value+bonus);
    if(where>pos)return 0;
    return pos-where;
}
int main()
{
cin>>inp;
n=inp.size();
check();
inp=" "+inp;
for(int i=0;i<2*4*nmax;i++)
    tree[i]=1e9;

add(0,0);
int l=0,t=0,s=0;
for(int i=1;i<=n;i++)
{
    if(vowel(inp[i]))s=s-1;
    else s=s+2;
    int now=ask(i,s);
    if(l<now)
    {
    l=now;
    t=1;
    }
    else if(l==now)t++;
    add(s,i);
}
cout<<l<<" "<<t<<endl;
return 0;
}