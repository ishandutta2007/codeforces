#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <math.h>
#include <string>
#include <string.h>
#include <stdlib.h>
using namespace std;
string ans;

void codeforces(string c)
{
	if(c==ans)
	{
		cout<<"OK\n";
	}
	else
	{
		cout<<"WRONG_ANSWER\n";
	}
	exit(0);
}

int main()
{
	string c;
	cin>>c>>ans;
	if(c=="0")
	{
		codeforces(c);
	}
	priority_queue <int> que;
	for(int i=0;i<c.size();i++)
	{
		que.push(-(c[i]-'0'));
	}
	string res="";
	while(que.top()==0)
	{
		res+="0";
		que.pop();
	}
	res=(char)(-que.top()+'0')+res;
	que.pop();
	while(que.size())
	{
		res+=(char)(-que.top()+'0');
		que.pop();
	}
	codeforces(res);
	return 0;
}