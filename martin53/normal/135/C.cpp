#include<bits/stdc++.h>
using namespace std;
string inp,cop;
int n,q;
map<string,int> seen;
queue<int> zero,one,emp;
string make(int num,bool which)
{
if(which){num=q-num;}
for(int i=0;i<n;i++)
    if(inp[i]=='?')
    {
    if(num>0)cop[i]=which+'0';
    else cop[i]=!which+'0';
    num--;
    }

zero=emp;
one=emp;
for(int i=0;i<n;i++)
    if(cop[i]=='0')zero.push(i);
    else one.push(i);
int s=n,player=1;
while(s>2)
{
    if(player==1)
    {
    if(one.size())one.pop();
    else zero.pop();
    }
    else
    {
    if(zero.size())zero.pop();
    else one.pop();
    }
    player=!player;
    s--;
}
if(one.size()==2)return "11";
if(zero.size()==2)return "00";
if(one.front()<zero.front())return "10";
return "01";
}
void go(int l,string l_,int r,string r_,bool how)
{
    seen[l_]=1;
    seen[r_]=1;
    if(r-l<=1)return;
    if(l_==r_)return;
    int av=(l+r)/2;
    string s=make(av,how);
    seen[s]=1;
    go(l,l_,av,s,how);
    go(av,s,r,r_,how);
}
int main()
{
cin>>inp;
n=inp.size();
cop=inp;
for(auto k:inp)
    if(k=='?')q++;
go(0,make(0,0),q,make(q,0),0);
go(0,make(0,1),q,make(q,1),1);
for(auto k:seen)cout<<k.first<<endl;
return 0;
}