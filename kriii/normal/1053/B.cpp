#include <stdio.h>

int N,C[300300],S[2][300300];

int main()
{
	scanf ("%d",&N);
	for (int i=1;i<=N;i++){
		long long s = 0; scanf ("%lld",&s);
		int c = 0;
		while (s){
			c++;
			s -= s & (-s);
		}
		C[i] = c;
	}

	long long ans = 0; int s = 0;
	S[0][0] = 1;
	for (int i=1;i<=N;i++){
		s = (s + C[i]) % 2;
		S[s][i]++;
		S[0][i] += S[0][i-1];
		S[1][i] += S[1][i-1];

		int mx = 0, sum = 0;
		for (int j=i;j>0;j--){
			if (mx < C[j]) mx = C[j];
			sum += C[j];
			if (sum >= 128){
				ans += S[s][j-1];
				break;
			}
			if (sum % 2 == 0 && sum - mx >= mx){
				ans++;
			}
		}
	}

	printf ("%lld\n",ans);

	return 0;
}