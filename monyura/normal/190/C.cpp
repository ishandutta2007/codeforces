//#pragma comment(linker,"/STACK:128000000")
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

typedef unsigned long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef unsigned char uc;
typedef short int si;
typedef unsigned short int usi;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define rep(x,y,z) for(int x=(y),e##x=(z);x<e##x;x++)
#define all(x) (x).begin(),(x).end()
#define movmax(A,B) {if(A<(B)) A=(B);}
#define movmin(A,B) {if(A>(B)) A=(B);}
//#define x first
//#define y second

const double PI=acos(-1.0);
template<class T> T SQR(const T &a){return a*a;}


char A[100100];
void run()
{
	int n;
	cin>>n;
	char str[100];
	char S[1000000]={0};
	stack<int> st;
	int m=0;
	for (int i=0;;i++)
	{
		if (scanf(" %s",str)!=1)
		{
			break;
		}
		A[i]=str[0];
		m++;
	}
	if (n==1 && m==1)
	{
		puts("int");
		return;
	}
	int pos=0;
	rep(i,0,m)
		if (A[i]=='p')
		{
			st.push(0);
			strcpy(S+pos,"pair<");
			pos+=5;
		}
		else
		{
			if (st.empty())
			{
				puts("Error occurred");
				return;
			}
			if (st.top()==0)
			{
				st.push(1);
				strcpy(S+pos,"int,");
				pos+=4;
			}
			else
			{
				strcpy(S+pos,"int>");
				pos+=4;
				st.pop();
				st.pop();
				while (!st.empty() && st.top()!=0)
				{
					st.pop();
					st.pop();
					S[pos++]='>';
				}
				if (st.empty() && i!=m-1)
				{
					puts("Error occurred");
					return;
				}
				if (i!=m-1)
				{
					st.push(1);
					S[pos++]=',';
				}
			}
		}
	if (!st.empty())
	{
		puts("Error occurred");
		return;
	}
	printf("%s\n",S);

}

int main()
{

#ifdef _MON_JUDGE_
	freopen("test.in","r",stdin);
	freopen("test.out","w",stdout);
#endif
	time_t beg=clock();
	run();
#ifdef _MON_JUDGE_
	puts("=================");
	printf("Time: %.3lf s.\n",(clock()-beg)/double(CLOCKS_PER_SEC));
#endif
	return 0;
}

/*

*/