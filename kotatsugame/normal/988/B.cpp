#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
main()
{
	int N;
	cin>>N;
	vector<string>A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	sort(A.begin(),A.end(),[](const string&a,const string&b){return a.size()<b.size();});
	for(int i=0;i+1<N;i++)
	{
		bool fn=false;
		for(int j=0;j<=A[i+1].size()-A[i].size();j++)
		{
			if(A[i]==A[i+1].substr(j,A[i].size()))
			{
				fn=true;
				break;
			}
		}
		if(!fn)
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=0;i<N;i++)cout<<A[i]<<endl;
}