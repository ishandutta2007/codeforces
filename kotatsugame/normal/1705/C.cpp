#include<iostream>
using namespace std;
int T;
int N,C,Q;
string S;
long long L[40],R[40];
long long len[41];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N>>C>>Q>>S;
		len[0]=N;
		for(int i=0;i<C;i++)
		{
			cin>>L[i]>>R[i];
			L[i]--;
			len[i+1]=len[i]+(R[i]-L[i]);
		}
		for(;Q--;)
		{
			long long k;cin>>k;
			k--;
			for(int i=C-1;i>=0;i--)
			{
				if(len[i]>k)continue;
				k=L[i]+(k-len[i]);
			}
			cout<<S[k]<<"\n";
		}
	}
}