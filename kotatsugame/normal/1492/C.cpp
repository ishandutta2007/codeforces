#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
string s,t;
int R[2<<17];
main()
{
	cin>>N>>M>>s>>t;
	int r=N;
	for(int i=M;i--;)
	{
		while(r>0&&s[r-1]!=t[i])r--;
		R[i]=--r;
	}
	int l=0;
	int ans=-1;
	for(int i=0;i<M-1;i++)
	{
		while(l<N&&s[l]!=t[i])l++;
		ans=max(ans,R[i+1]-l);
		l++;
	}
	printf("%d\n",ans);
}