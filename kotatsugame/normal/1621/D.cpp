#include<iostream>
using namespace std;
int T,N;
int C[500][500];
long long H[501][500],W[500][501],S[501][501];
long long cnt(int a,int b,int c,int d)
{
	return S[c][d]-S[c][b]-S[a][d]+S[a][b];
}
main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>T;
	for(;T--;)
	{
		cin>>N;
		for(int i=0;i<2*N;i++)
		{
			for(int j=0;j<2*N;j++)
			{
				cin>>C[i][j];
				S[i+1][j+1]=S[i+1][j]+S[i][j+1]-S[i][j]+C[i][j];
				H[i+1][j]=H[i][j]+C[i][j];
				W[i][j+1]=W[i][j]+C[i][j];
			}
		}
		long long ans=9e18;
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				{
					long long now=0;
					long long a=W[i][N+j]-W[i][N];
					now+=min(a,W[i][2*N]-W[i][N]-a-C[i][N+j]);
					long long b=H[N][N+j]-H[i+1][N+j];
					now+=min(b,H[N][N+j]-H[0][N+j]-b-C[i][N+j]);
					now+=C[i][N+j];
					now+=min(cnt(N,j+1,2*N,N),cnt(N,0,2*N,j));
					ans=min(ans,now);
				}
				{
					long long now=0;
					long long a=H[N+j][i]-H[N][i];
					now+=min(a,H[2*N][i]-H[N][i]-a-C[N+j][i]);
					long long b=W[N+j][N]-W[N+j][i+1];
					now+=min(b,W[N+j][N]-W[N+j][0]-b-C[N+j][i]);
					now+=C[N+j][i];
					now+=min(cnt(j+1,N,N,2*N),cnt(0,N,j,2*N));
					ans=min(ans,now);
				}
			}
		}
		cout<<ans+cnt(N,N,2*N,2*N)<<"\n";
	}
}