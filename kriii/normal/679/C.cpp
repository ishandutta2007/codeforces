#include <stdio.h>

int N,K;
char S[505][505]; int sum[505][505],trans[505][505];
int par[250050],sz[250050],cnt[250050],all,ans;

int find(int x)
{
	if (par[x] != x) par[x] = find(par[x]);
	return par[x];
}

void in(int g)
{
	g = find(g);
	if (++cnt[g] == 1){
		all += sz[g];
	}
}

void out(int g)
{
	g = find(g);
	if (--cnt[g] == 0){
		all -= sz[g];
	}
}

int main()
{
	scanf ("%d %d",&N,&K);
	for (int i=1;i<=N;i++){
		scanf ("%s",S[i]+1);
		for (int j=1;j<=N;j++){
			trans[i][j] = (i - 1) * N + j;
			par[trans[i][j]] = trans[i][j];
			if (S[i][j] == '.'){
				sum[i][j] = 1;
				sz[trans[i][j]] = 1;
			}
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}

	int dx[2] = {1,0};
	int dy[2] = {0,1};
	for (int k=0;k<2;k++){
		for (int i=1;i<=N-dx[k];i++) for (int j=1;j<=N-dy[k];j++){
			if (S[i][j] == '.' && S[i+dx[k]][j+dy[k]] == '.'){
				int x = find(trans[i][j]), y = find(trans[i+dx[k]][j+dy[k]]);
				if (x != y){
					par[x] = y;
					sz[y] += sz[x];
				}
			}
		}
	}

	for (int i=K;i<=N;i++){
		for (int k=0;k<K;k++){
			in(trans[i-k][0]);
			in(trans[i-k][K+1]);
			in(trans[i-K][k+1]);
			in(trans[i+1][k+1]);
		}
		for (int k=0;k<K;k++) for (int l=1;l<=K;l++) in(trans[i-k][l]);
		for (int j=K;j<=N;j++){
			int now = all - (sum[i][j] - sum[i-K][j] - sum[i][j-K] + sum[i-K][j-K]) + K * K;
			if (ans < now) ans = now;
			for (int k=0;k<K;k++){
				out(trans[i-k][j-K]);
				in(trans[i-k][j+1+1]);
			}
			out(trans[i-K][j-K+1]);
			out(trans[i+1][j-K+1]);
			in(trans[i-K][j+1]);
			in(trans[i+1][j+1]);
		}
		for (int k=0;k<K;k++){
			out(trans[i-k][N-K+1]);
			out(trans[i-k][N+2]);
			out(trans[i-K][N-K+k+2]);
			out(trans[i+1][N-K+k+2]);
		}
		for (int k=0;k<K;k++) for (int l=1;l<=K;l++) out(trans[i-k][N-K+l+1]);
	}

	printf ("%d\n",ans);

	return 0;
}