#include<iostream>
#include<vector>
using namespace std;
int N;
int A[50];
bool ex[1010];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	vector<int>ans;
	for(int i=N;i--;)if(!ex[A[i]])
	{
		ex[A[i]]=true;
		ans.push_back(A[i]);
	}
	printf("%d\n",ans.size());
	for(int i=ans.size();i--;)printf("%d%c",ans[i],i?32:10);
}