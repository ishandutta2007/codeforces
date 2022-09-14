#include<iostream>
#include<algorithm>
using namespace std;
int T,N;
int L[1<<17],R[1<<17],C[1<<17];
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		int ml=0,mr=0;
		int ma=0;
		for(int i=0;i<N;i++)
		{
			cin>>L[i]>>R[i]>>C[i];
			if(L[ml]>L[i]||L[ml]==L[i]&&C[ml]>C[i])ml=i;
			if(R[mr]<R[i]||R[mr]==R[i]&&C[mr]>C[i])mr=i;
			if(ma!=-1&&(R[ma]<R[mr]||L[ma]>L[ml]))ma=-1;
			if(L[i]==L[ml]&&R[i]==R[mr])
			{
				if(ma==-1||C[ma]>C[i])ma=i;
			}
			int ans=C[ml]+C[mr];
			if(ma!=-1)ans=min(ans,C[ma]);
			cout<<ans<<"\n";
		}
	}
}