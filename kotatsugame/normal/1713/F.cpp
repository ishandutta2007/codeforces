#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int B[5<<17],A[5<<17];
int tmp[5<<17];
void solve(int L,int R)
{
	int W=R-L;
	if(W==1)
	{
		A[L]=B[L];
		return;
	}
	int t=0;
	while((1<<t+1)<W)t++;
	for(int k=L+(1<<t);k<R;k++)B[k]^=B[k-(1<<t)];
	solve(L+(1<<t),R);
	for(int i=0;i<1<<t;i++)tmp[i]=0;
	for(int k=L+(1<<t);k<R;k++)tmp[k-L-(1<<t)]=A[k];
	for(int i=0;i<t;i++)for(int j=0;j<1<<t;j++)if(j>>i&1)tmp[j]^=tmp[j^1<<i];
	for(int i=0;i<1<<t;i++)B[L+i]^=tmp[(1<<t)-1^i];
	solve(L,L+(1<<t));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin>>N;
	for(int i=0;i<N;i++)cin>>B[i];
	solve(0,N);
	for(int i=N;i--;)cout<<A[i]<<(i==0?"\n":" ");
}