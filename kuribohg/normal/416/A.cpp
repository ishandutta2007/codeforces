#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,dat;
string op;
char right0;
int minnum=-2e9,maxnum=2e9;
int main()
{
	cin>>n;
	for(int cas=1;cas<=n;cas++)
	{
		cin>>op>>dat>>right0;
		if(op==">") dat++,op=">=";
		else if(op=="<") dat--,op="<=";
		if(op==">="&&right0=='Y') minnum=max(minnum,dat);
		else if(op==">="&&right0=='N') maxnum=min(maxnum,dat-1);
		else if(op=="<="&&right0=='Y') maxnum=min(maxnum,dat);
		else if(op=="<="&&right0=='N') minnum=max(minnum,dat+1);
	}
	if(minnum>maxnum) puts("Impossible");
	else printf("%d\n",minnum);
	return 0;
}