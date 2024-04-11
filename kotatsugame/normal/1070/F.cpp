#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N;
vector<int>A[4];
main()
{
	cin>>N;
	for(int i=0;i<N;i++)
	{
		string s;
		int a;
		cin>>s>>a;
		int t=(s[0]-'0')*2+s[1]-'0';
		A[t].push_back(a);
	}
	int d=A[3].size();
	int sum=0;
	for(int a:A[3])sum+=a;
	int mn=min(A[1].size(),A[2].size());
	sort(A[1].begin(),A[1].end());reverse(A[1].begin(),A[1].end());
	sort(A[2].begin(),A[2].end());reverse(A[2].begin(),A[2].end());
	for(int i=0;i<mn;i++)
	{
		sum+=A[1][i]+A[2][i];
	}
	priority_queue<int>P;
	for(int a:A[0])P.push(a);
	int id=A[1].size()<A[2].size()?2:1;
	int gt=min((int)A[id].size()-mn,d);
	for(int i=0;i<gt;i++)sum+=A[id][mn+i];
	int cnt=d-gt;
	int ans=sum;
	for(int i=gt;i>=0;i--)
	{
		while(cnt>0&&!P.empty())
		{
			cnt--;
			sum+=P.top();
			P.pop();
		}
		ans=max(ans,sum);
		if(i>0)
		{
			cnt++;
			sum-=A[id][mn+i-1];
		}
	}
	cout<<ans<<endl;
}