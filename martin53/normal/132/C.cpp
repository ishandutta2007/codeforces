#include<bits/stdc++.h>
using namespace std;
const int nmax=100+5;
string inp;
int n;
bool been[nmax][nmax][2*nmax][2];
int outp=0;
void rec(int position,int change,int x,int direction/*1-> +, 0->-*/)
{
//cout<<position<<" "<<change<<" "<<x<<" "<<direction<<endl;
if(position==n)
{
    if(change==0)
        outp=max(outp,abs(x));
    return;
}
if(been[position][change][x+nmax][direction])return;
been[position][change][x+nmax][direction]=1;
//do not change
if(inp[position]=='F')rec(position+1,change,x+(direction==1?1:-1),direction);
else rec(position+1,change,x,!direction);
//change
if(change)
{
if(inp[position]=='T')rec(position+1,change-1,x+(direction==1?1:-1),direction);
else rec(position+1,change-1,x,!direction);
}

}
int main()
{
int change;
cin>>inp>>change;
n=inp.size();
for(int i=0;change-2*i>=0;i++)rec(0,change-2*i,0,1);
cout<<outp<<endl;
return 0;
}