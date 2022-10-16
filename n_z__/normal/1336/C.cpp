#include<bits/stdc++.h>
using namespace std;
int f[3001][3001];
char s[3001],t[3001];
int main(){
    cin>>(s+1)>>(t+1);
    for(int x=1;s[x];x++)
	if(!t[x]||s[1]==t[x])f[x][x]=2;
    for(int x=2;s[x];x++)
	for(int y=1;s[x+y-1];y++)
	{
		f[y][x+y-1]=0;
    	if(!t[y]||s[x]==t[y])f[y][x+y-1]+=f[y+1][x+y-1];
		if(!t[x+y-1]||s[x]==t[x+y-1])f[y][x+y-1]+=f[y][x+y-2];
		f[y][x+y-1]%=998244353;
	}
    int a=0;
    for(int x=1;s[x];x++)
	if(!t[x+1])a+=f[1][x],a%=998244353;
    cout<<a;
}