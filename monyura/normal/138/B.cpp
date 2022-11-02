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
	char a[100101],b[100101];
	scanf("%s",a);
	strcpy(b,a);
	int ca[11]={0};
	int cb[11]={0};
	int n=strlen(a);
	rep(i,0,n)
	{
		ca[a[i]-'0']++;
		cb[b[i]-'0']++;
	}
	int c10=-1;
	rep(i,1,10)
		if (ca[i]>ca[9-i] && cb[10-i]>cb[9-(10-i)])
			c10=i;
	if (c10==-1)
		rep(i,1,10)
			if (ca[i]>ca[9-i] && cb[10-i]!=0)
				c10=i;
	if (c10==-1)
		rep(i,1,10)
			if (ca[i]!=0 && ca[10-i]!=0)
				c10=i;
	if (c10==-1)
	{
		sort(a,a+n,greater<char>());
		sort(b,b+n,greater<char>());
		printf("%s\n%s\n",a,b);
		return 0;
	}
	int lft=max(0,ca[0]-ca[9]);
	char A[100101]={0};
	char B[100101]={0};
	int pos=0;
	rep(i,0,lft)
	{
		A[pos]=B[pos]='0';
		ca[0]--;
		cb[0]--;
		pos++;
	}
	A[pos]=c10+'0';
	B[pos]=10-c10+'0';
	pos++;
	ca[c10]--;
	cb[10-c10]--;
	int c[11]={0};
	rep(i,0,10)
		c[i]=min(ca[i],cb[9-i]);
	rep(i,0,10)
	{
		rep(j,0,c[i])
		{
			A[pos]=i+'0';
			ca[i]--;
			B[pos]=9-i+'0';
			cb[9-i]--;
			pos++;
		}
	}
	int pa=pos;
	rep(i,0,10)
		rep(j,0,ca[i])
			A[pa++]=i+'0';
	int pb=pos;
	rep(i,0,10)
		rep(j,0,cb[i])
			B[pb++]=i+'0';
	reverse(A,A+n);
	reverse(B,B+n);
	printf("%s\n%s\n",A,B);
	return 0;
} 
/*
75223
*/