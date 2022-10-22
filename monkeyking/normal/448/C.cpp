#include <iostream>
#include <algorithm>
#define rep(N) for(int i=0;i<N;i++)
using namespace std;
int n,a[5005];

int cal(int l,int r,int h)
{
	if(l>=r) return 0;
	int minn=a[l],k=l;
	for(int i=l+1;i<r;i++)
	{
		if(a[i]<minn) minn=a[i],k=i;
	}
	return(min(r-l,minn-h+cal(l,k,minn)+cal(k+1,r,minn)));
}

int main()
{
	cin>>n;
	rep(n)
	{
		cin>>a[i];
	}
	cout<<cal(0,n,0)<<endl; 
}