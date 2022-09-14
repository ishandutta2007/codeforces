#include<iostream>
using namespace std;
int T,N;
int A[1<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		int l=0;
		while(l<N&&A[l]==0)l++;
		int r=N-1;
		while(r>=0&&A[r]==0)r--;
		int zc=0;
		for(int i=l;i<=r;i++)zc+=!A[i];
		cout<<(l>r?0:zc==0?1:2)<<"\n";
	}
}