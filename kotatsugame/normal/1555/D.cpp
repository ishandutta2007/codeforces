#include<iostream>
#include<algorithm>
using namespace std;
int N,M;
string S;
int cnt[6][2<<17];
main()
{
	cin>>N>>M>>S;
	string T="abc";
	int id=0;
	do{
		for(int i=0;i<N;i++)
		{
			cnt[id][i+1]=cnt[id][i];
			if(T[i%3]!=S[i])cnt[id][i+1]++;
		}
		id++;
	}while(next_permutation(T.begin(),T.end()));
	for(;M--;)
	{
		int L,R;cin>>L>>R;
		L--;
		int ans=1e9;
		for(int i=0;i<6;i++)ans=min(ans,cnt[i][R]-cnt[i][L]);
		cout<<ans<<"\n";
	}
}