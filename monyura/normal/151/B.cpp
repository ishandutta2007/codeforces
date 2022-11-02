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


int main()
{
	int n;
	cin>>n;
	vector<string> V[3];
	int cnt[101][3]={0};
	string S[101];
	char str[1000];
	rep(i,0,n)
	{
		int m;
		scanf("%d%s",&m,str);
		S[i]=str;
		char tmp[20];
		
		rep(j,0,m)
		{
			scanf(" %s",tmp);
			char num[20]={tmp[0],tmp[1],tmp[3],tmp[4],tmp[6],tmp[7],0};
			bool t=1;
			rep(k,1,6)
				if (num[k]!=num[0])
					t=0;
			bool p=1;
			rep(k,1,6)
				if (num[k]>=num[k-1])
					p=0;
			if (t) cnt[i][0]++;
			else if (p) cnt[i][1]++;
			else cnt[i][2]++;
		}
	}
	int mx[3]={0};
	rep(i,0,3)
		rep(j,0,n)
			mx[i]=max(mx[i],cnt[j][i]);
	rep(i,0,3)
		rep(j,0,n)
			if (cnt[j][i]==mx[i]) V[i].push_back(S[j]);
	printf("If you want to call a taxi, you should call: ");
	rep(i,0,V[0].size()-1)
		printf("%s, ",V[0][i].c_str());
	if (V[0].size()!=0)
		printf("%s",V[0].back().c_str());
	printf(".\n");
	printf("If you want to order a pizza, you should call: ");
	rep(i,0,V[1].size()-1)
		printf("%s, ",V[1][i].c_str());
	if (V[1].size()!=0)
		printf("%s",V[1].back().c_str());
	printf(".\n");
	printf("If you want to go to a cafe with a wonderful girl, you should call: ");
	rep(i,0,V[2].size()-1)
		printf("%s, ",V[2][i].c_str());
	if (V[2].size()!=0)
		printf("%s",V[2].back().c_str());
	printf(".\n");
	return 0;
} 

/*

*/