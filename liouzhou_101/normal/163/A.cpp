#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;

const int MaxN=5010;
const int MOD=1000000007;

char A[MaxN],B[MaxN];
int LA,LB,ans;
int F[MaxN][MaxN],sum[MaxN][MaxN];

int main()
{
	scanf("%s%s",A+1,B+1);
	LA=strlen(A+1);
	LB=strlen(B+1);
	for (int i=1;i<=LA;++i)
		for (int j=1;j<=LB;++j)
		{
			if (A[i]==B[j])
			{
				F[i][j]=(sum[i-1][j-1]+1)%MOD;
				ans=(ans+F[i][j])%MOD;
			}
			sum[i][j]=(sum[i][j-1]+F[i][j])%MOD;
		}
	cout<<ans<<endl;
	return 0;
}