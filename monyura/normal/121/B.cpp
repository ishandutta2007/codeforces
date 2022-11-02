#pragma comment(linker,"/STACK:32000000")
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
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

vector<int> vec;

void rec(int step,int val)
{
	if (step>=9) return;
	vec.push_back(val);
	rec(step+1,val*10+4);
	rec(step+1,val*10+7);
}

int main()
{
	int n,k;
	cin>>n>>k;
	cin.get();
	char str[100101];
	gets(str);
	for (int i=1;str[i];i++)
	{
		if (k>0 && str[i]=='7' && str[i-1]=='4')
		{
			if (i>1 && str[i-2]=='4' && ((i)&1)==0)
			{
				if (k&1)
				{
					str[i-1]='7';
				}
				k=0;
				break;
			}
			k--;
			if (((i)&1)==0)
			{
				str[i-1]='7';
			}
			else
			{
				str[i]='4';
			}
		}
	}
	printf("%s\n",str);
	return 0;
}
/*
4 100000000
44478
*/