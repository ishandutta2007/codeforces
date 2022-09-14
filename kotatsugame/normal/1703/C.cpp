#include<iostream>
using namespace std;
int A[100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	for(;T--;)
	{
		int N;cin>>N;
		for(int i=0;i<N;i++)cin>>A[i];
		for(int i=0;i<N;i++)
		{
			int n;string S;cin>>n>>S;
			int now=A[i];
			for(char c:S)
			{
				if(c=='D')now=(now+1)%10;
				else now=(now+9)%10;
			}
			cout<<now<<(i+1==N?"\n":" ");
		}
	}
}