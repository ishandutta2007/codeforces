#pragma comment(linker,"/STACK:64000000")
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
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define x first
#define y second

const double PI=acos(-1.0);

vector<string> split(char *str)
{
	int n=strlen(str);
	vector<string> res;
	if (str[0]=='/') ++str;
	char *last=str;
	rep(i,0,strlen(str)+1)
		if (str[i]=='/' || str[i]==0)
		{
			str[i]=0;
			if (last[0])
				res.push_back(last);
			last=str+i+1;
		}
	return res;
}

int main()
{
	int n;
	cin>>n;
	cin.get();
	vector<string> p,curr;
	char str[1000];
	rep(i,0,n)
	{
		gets(str);
		if (str[0]=='c')
		{
			curr=split(str+3);
			if (str[3]=='/')
				p.clear();
			p.insert(p.end(),all(curr));
			for (int j=0;j<p.size();j++)
				if (p[j]=="..")
				{
					p.erase(p.begin()+j-1,p.begin()+j+1);
					j-=2;
				}
		}
		else
		{
			rep(j,0,p.size())
				printf("/%s",p[j].c_str());
			printf("/\n");
		}
	}
	return 0;
} 

/*
1
1

1
2

1
3

1
4


*/