#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using std::ios;
using std::cin;
using std::cout;
using std::sort;
using std::string;
const int N=3e5+5;
int n,cnt,ans;
int stack[N],top;
string s;
inline bool cmp(int a,int b)
{
	return a>b;
}
inline int read()
{
	int sum(0);
	char x;
	while((x=getchar())<'0'||x>'9');
	for(;x>='0'&&x<='9';x=getchar())
		sum=(sum<<3)+(sum<<1)+x-'0';
	return sum;
}
signed main()
{
	int i,j;
	n=read();
	for(i=1;i<=(n<<1);i++)
	{
		cin>>s;
		if(s=="add")
			stack[++top]=read();
		else
		{
			cnt++;
			if(top)
			{
				if(stack[top]!=cnt)
				{
					ans++;
					top=0;
				}
				else
					top--;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}