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
typedef long double ld;
typedef pair<int,int> pii;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

struct elem
{
	int val;
	int men;
	char c;
};

bool operator<(const elem &a,const elem& b)
{
	if (a.val!=b.val) return a.val<b.val;
	return a.men<b.men;
}

int main()
{
	char str[1000];
	scanf(" %s",str);
	for (int i=0;str[i];i++)
	{
		str[i]|=32;
		if (str[i]=='a' || str[i]=='o' || str[i]=='y' || str[i]=='e' || str[i]=='u' || str[i]=='i')
			continue;
		printf(".%c",str[i]);
	}
	printf("\n");
}
/*

*/