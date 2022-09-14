#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>Zalgo(const vector<string>&s)
{
	vector<int>ret(s.size());
	if(s.empty())return ret;
	ret[0]=s.size();
	int i=1,j=0;
	while(i<s.size())
	{
		while(i+j<s.size()&&s[j]==s[i+j])j++;
		ret[i]=j;
		if(j==0)
		{
			i++;
			continue;
		}
		int k=1;
		while(i+k<s.size()&&k+ret[k]<j)ret[i+k]=ret[k],k++;
		i+=k;j-=k;
	}
	return ret;
}
int N;
main()
{
	cin>>N;
	vector<string>A(N);
	int all=N-1;
	for(int i=0;i<N;i++)
	{
		cin>>A[i];
		all+=A[i].size();
	}
	int ans=0;
	for(int i=0;i<N;i++)
	{
		vector<string>now(A.begin()+i,A.end());
		vector<int>ret=Zalgo(now);
		int sum=0;
		for(int k=1;k<=now.size();k++)
		{
			sum+=now[k-1].size();
			int cnt=0;
			for(int j=0;j<ret.size();)
			{
				if(ret[j]>=k)
				{
					cnt++;
					j+=k;
				}
				else j++;
			}
			if(cnt>=2)
			{
				ans=min(ans,cnt*(1-sum));
			}
		}
	}
	cout<<all+ans<<endl;
}