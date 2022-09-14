#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
main()
{
	int N;
	scanf("%d",&N);
	vector<int>A(N);
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	sort(A.begin(),A.end());
	vector<int>L,R;
	for(int i=0;i<N;i++)
	{
		if(L.empty()||L.back()<A[i])L.push_back(A[i]);
		else if(R.empty()||R.back()<A[i])R.push_back(A[i]);
		else
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	printf("%d\n",(int)L.size());
	for(int i=0;i<L.size();i++)printf("%d%c",L[i],i+1==L.size()?10:32);
	printf("%d\n",(int)R.size());
	for(int i=R.size();i--;)printf("%d%c",R[i],i?32:10);
}