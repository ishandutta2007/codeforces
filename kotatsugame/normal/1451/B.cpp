#include<iostream>
using namespace std;
int T,N,Q;
string s;
bool L[110][2],R[110][2];
main()
{
	cin>>T;
	for(;T--;)
	{
		cin>>N>>Q>>s;
		L[0][0]=L[0][1]=false;
		for(int i=0;i<N;i++)
		{
			L[i+1][0]=L[i][0];
			L[i+1][1]=L[i][1];
			L[i+1][s[i]-'0']=true;
		}
		R[N][0]=R[N][1]=false;
		for(int i=N;i--;)
		{
			R[i][0]=R[i+1][0];
			R[i][1]=R[i+1][1];
			R[i][s[i]-'0']=true;
		}
		for(;Q--;)
		{
			int l,r;cin>>l>>r;
			bool ok=false;
			if(L[l-1][s[l-1]-'0'])ok=true;
			if(R[r][s[r-1]-'0'])ok=true;
			cout<<(ok?"YES\n":"NO\n");
		}
	}
}