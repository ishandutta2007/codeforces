#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define ll long long    
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'|ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
} 
inline char getcaaa()
{
	char c;
	while((c=getchar())>'z'||c<'a');
	return c;
}
bool find_vis1[1561],find_vis2[1561];
int main()
{
	char a=getcaaa(),b=getcaaa();
	int n=read();
	for(int i=1;i<=n;i++)
	{
		int A=getcaaa(),B=getcaaa();
		find_vis1[A]=1,find_vis2[B]=1;
		if(A==a&&b==B)
		{
			cout<<"YES"<<endl;
			return 0;
		}
		swap(A,B);
		if(A==a&&b==B)
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	if(find_vis2[a]&&find_vis1[b])
		cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}