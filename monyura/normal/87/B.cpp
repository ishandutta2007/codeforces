#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <complex>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <fstream>
#include <functional>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int main()
{

	int n;
	cin>>n;
	map<string,int> mp;
	mp["void"]=0;
	mp["errtype"]=-1;
	char op[100],type[1000],name[1000],str[1000];
	rep(i,0,n)
	{
		scanf(" %s",op);
		if (strcmp(op,"typedef")==0)
		{
			scanf(" %s %s",type,name);
			int st=0;
			while (type[st]=='&') st++;
			int cnt=0,en=strlen(type)-1;
			while (type[en]=='*') en--,cnt++;
			strncpy(str,type+st,en-st+1);
			str[en-st+1]=0;
			int curr;
			if (mp.find(str)==mp.end()) curr=-1;
			else curr=mp[str];
			if (curr==-1 || curr+cnt<st) mp[name]=-1;
			else mp[name]=curr+cnt-st;
		}
		else
		{
			scanf(" %s",name);
			int st=0;
			while (name[st]=='&') st++;
			int cnt=0,en=strlen(name)-1;
			while (name[en]=='*') en--,cnt++;
			strncpy(str,name+st,en-st+1);
			str[en-st+1]=0;
			int curr;
			if (mp.find(str)==mp.end()) curr=-1;
			else curr=mp[str];
			if (curr==-1 || curr+cnt<st) curr=-1;
			else curr+=cnt-st;
			if (curr==-1) puts("errtype");
			else
			{
				printf("void");
				rep(i,0,curr)
					printf("*");
				printf("\n");
			}
		}
	}
	return 0;	
}
/*
100
typedef void** a
typeof a**
*/