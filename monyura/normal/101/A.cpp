#pragma comment(linker,"/STACK:65000000")
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

template<class T> inline T sqr(T a){return a*a;}

int main()
{
	int k;
	char *str=new char[1e5+1];
	scanf("%s%d",str,&k);
	int cnt[300]={0};
	for (int i=0;str[i];i++)
		cnt[str[i]]++;
	vector<pii> vec;
	rep(i,'a','z'+1)
		vec.push_back(pii(cnt[i],i));
	sort(vec.begin(),vec.end());
	bool state[300]={0};
	int dif=vec.size();
	rep(i,0,vec.size())
	{
		if (k>=vec[i].first)
		{
			dif--;
			k-=vec[i].first;
			state[vec[i].second]=1;
		}
	}
	bool del[100000]={0};
	for (int i=0;str[i];i++)
	{
		if (state[str[i]]) del[i]=1;
		else if (k>0)
		{
			del[i]=1;
			k--;
		}
	}
	cout<<dif<<endl;
	for (int i=0;str[i];i++)
		if (!del[i]) putchar(str[i]);
	printf("\n");
	return 0;      
}

/*
2 1
0 0 0 0 0 1
0 1 0 0 0 -1
*/