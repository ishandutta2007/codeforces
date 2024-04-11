#ifdef _MONYURA_
#pragma comment(linker,"/STACK:256000000")
#endif

#include <iostream>
#include <cstdio>
#include <memory>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cstring>
#include <fstream>
#include <functional>
#include <stack>
#include <complex>
#include <cmath>
#include <queue>
#include <ctime>


using namespace std;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define SQ(x) ((x)*(x))
#define all(c) (c).begin(), (c).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef short int si;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;

const double PI=acos(-1.0);

vector<int> inc[200200];

void run()
{
	/*int A[2]={0};
	int n;
	cin>>n;
	rep(i,0,n)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if (a==1)
			A[0]+=b-c;
		else
			A[1]+=b-c;
	}
	rep(i,0,2)
		puts(A[i]>=0? "LIVE":"DEAD");
	return;*/
	char str[1000];
	scanf("%s",str);
	char res[1000]={0};
	int pos=0;
	int len = str[0]=='f' ? 3 : 4;
	strncpy(res,str,len);
	pos+=len;
	strcat(res+pos,"://");
	pos+=3;
	int ru=-1;
	rep(i,len+1,strlen(str))
		if (strncmp(str+i,"ru",2)==0)
		{
			ru=i;
			break;
		}
	if (ru==-1)
		throw 1;
	rep(i,len,ru)
		res[pos++]=str[i];
	strcat(res+pos,".ru");
	pos+=3;
	if (ru+2<strlen(str))
	{
		res[pos++]='/';
		strcat(res+pos,str+ru+2);
	}
	printf("%s\n",res);
}


int main()
{
	srand(time(0));
#ifdef _MONYURA_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
	time_t st=clock();
#else
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
#endif
	run();
#ifdef _MONYURA_
	printf("=============\n");
	printf("Time: %.2lf sec\n",(clock()-st)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}

/*

*/