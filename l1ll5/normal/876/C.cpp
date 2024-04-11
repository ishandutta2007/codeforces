#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100010
#define ll long long
using namespace std;
inline int read() 
{ 
    int x=0,f=1;char ch=getchar(); 
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();} 
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();} 
    return x*f; 
}
int n;
vector<int> v;
bool ck(int x)
{
	int ret=x;
	while(x)
	ret+=x%10,x/=10;
	return ret==n;
}
int main()
{
	n=read();
	for(int i=n;i>=max(0,n-120);i--)
	if(ck(i))v.push_back(i);
	cout<<v.size()<<endl;
	if(v.size()!=0)
	for(int i=v.size()-1;i>=0;i--)
	printf("%d ",v[i]);
}
/*
1000000000
*/