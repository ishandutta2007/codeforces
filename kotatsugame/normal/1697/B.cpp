#include<iostream>
#include<algorithm>
using namespace std;
int N,Q;
int P[2<<17];
long long S[2<<17];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>N>>Q;
	for(int i=0;i<N;i++)cin>>P[i];
	sort(P,P+N);
	for(int i=0;i<N;i++)S[i+1]=S[i]+P[i];
	for(;Q--;)
	{
		int x,y;cin>>x>>y;
		cout<<S[N-x+y]-S[N-x]<<"\n";
	}
}