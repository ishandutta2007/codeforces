#pragma comment(linker,"/STACK:16000000")
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

int F[1000100];
bool Can[1000100]={0};
int KMP(char *str,int n)
{
	F[0]=0;
	int best=0;
	int pos=-1;
	rep(i,1,n)
	{
		int curr=F[i-1];
		while (curr>0 && str[curr]!=str[i]) curr=F[curr-1];
		if (str[curr]==str[i])
			curr++;
		F[i]=curr;
		if (curr>=best && i!=n-1)
		{
			best=curr;
			pos=i;
		}
	}
	int curr=F[n-1];
	while (curr!=0)
	{
		Can[curr]=1;
		curr=F[curr-1];
	}
	int res=0;
	for (int i=n-2;i>0;i--)
		if (Can[F[i]] && F[i]>res)
			res=F[i];
	return res;
}

int main()
{
	char str[1000101];
	scanf(" %s",str);
	int n=strlen(str);
	int res=KMP(str,n);
	if (res==0)
		printf("Just a legend\n");
	else
	{
		str[res]=0;
		printf("%s\n",str);
	}
    return 0;
} 
/*
abababacababa
*/