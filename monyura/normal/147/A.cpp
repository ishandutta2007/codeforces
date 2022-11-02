//#pragma comment(linker,"/STACK:32000000")
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

const double PI=acos(-1.0);

template<class T> inline T SQR(T a){return a*a;}

int main()
{
	char str[20000];
	cin.getline(str,20000);
	char res[20000]={0};
	int pos=0;
	int n=strlen(str);
	bool wassp=false;
	rep(i,0,n)
	{
		if (str[i]>='a' && str[i]<='z')
		{
			if (wassp)
				res[pos++]=' ';
			res[pos++]=str[i];
			wassp=false;
		}
		else
		{
			if (str[i]!=' ')
				res[pos++]=str[i];
			wassp=true;
		}
	}
	rep(i,0,pos)
	{
		putchar(res[i]);
		if ((res[i]<'a' || res[i]>'z') && res[i]!=' ' && res[i+1]!=' ')
			putchar(' ');
	}
	putchar('\n');
	return 0;
} 

/*
          s !!!! !   ! s ! s,,ss
*/