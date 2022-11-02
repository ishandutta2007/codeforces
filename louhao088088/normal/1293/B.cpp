#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;char ch=getchar();bool f=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n;
double num=0;
int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		num=num+1.0*1/i;
	}
	printf("%.10lf",num);
	return 0;
}