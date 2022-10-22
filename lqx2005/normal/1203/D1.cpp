#include <iostream>
#include <cstdio>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <deque>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <stack>
#include <set>
#include<climits>
typedef long long ll;
using namespace std;
string s,t;
int slen,tlen; 

bool calc(string d)
{
	int dlen=d.length();
	int no=0;
	for(int i=0;i<dlen;i++)
	{
		if(no>=tlen) return true;
		if(d[i]==t[no]) no++;
	}
	if(no>=tlen) return true;
	return false;
}
bool check(int len)
{
	for(int i=0;i+len-1<slen;i++)
	{
		string d=s;
		d.erase(d.begin()+i,d.begin()+i+len);
		if(calc(d)) return true;
	}
	return false;
}
int main()
{
	cin>>s>>t;
	slen=s.length();
	tlen=t.length();
	int l=0,r=slen,best=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid)) best=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",best);
	return 0;
}