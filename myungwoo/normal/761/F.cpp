#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
typedef long long lld;
typedef pair<int, int> pii;

#define MAXK 300005

int N, M, K;
char A[1001][1002];
int C[1002][1002][26];
int OC[1002][1002];
lld S[1002][1002], D[1002][1002][26];

struct RECT{
	int sy, sx, ey, ex;
	char c;
} R[MAXK];

int main()
{
	scanf("%d%d%d", &N, &M, &K);
	for (int i=1;i<=N;i++) scanf("%s", A[i]+1);
	OC[N][M] = K;
	for (int i=1;i<=K;i++){
		int sy, sx, ey, ex; char c;
		scanf("%d%d%d%d %c", &sy, &sx, &ey, &ex, &c);
		R[i] = {sy, sx, ey, ex, c};
		C[ey][ex][c-'a']++;
		C[sy-1][ex][c-'a']--;
		C[ey][sx-1][c-'a']--;
		C[sy-1][sx-1][c-'a']++;
		OC[ey][ex]--;
		OC[sy-1][ex]++;
		OC[ey][sx-1]++;
		OC[sy-1][sx-1]--;
	}
	for (int i=N;i;i--) for (int j=M;j;j--) OC[i][j] += OC[i+1][j]+OC[i][j+1]-OC[i+1][j+1];
	for (int i=N;i;i--) for (int j=M;j;j--){
		for (int k=0;k<26;k++){
			C[i][j][k] += C[i+1][j][k]+C[i][j+1][k]-C[i+1][j+1][k];
			S[i][j] += abs(k-(A[i][j]-'a')) * C[i][j][k];
		}
	}
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++){
		C[i][j][A[i][j]-'a'] += OC[i][j];
		lld sum = 0, total = 0;
		for (int k=0;k<26;k++){
			D[i][j][k] = sum;
			total += C[i][j][k];
			sum += total;
		}
		sum = total = 0;
		for (int k=26;k--;){
			D[i][j][k] += sum;
			total += C[i][j][k];
			sum += total;
		}
	}
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++){
		S[i][j] += S[i-1][j]+S[i][j-1]-S[i-1][j-1];
		for (int k=0;k<26;k++)
			C[i][j][k] += C[i-1][j][k]+C[i][j-1][k]-C[i-1][j-1][k];
		for (int k=0;k<26;k++){
			D[i][j][k] += D[i-1][j][k]+D[i][j-1][k]-D[i-1][j-1][k];
		}
	}
	lld ans = 1e18;
	for (int i=1;i<=K;i++){
		auto &r = R[i];
		lld v = S[N][M] - (S[r.ey][r.ex]-S[r.sy-1][r.ex]-S[r.ey][r.sx-1]+S[r.sy-1][r.sx-1]);
		int c = r.c-'a';

		v += D[r.ey][r.ex][c]-D[r.sy-1][r.ex][c]-D[r.ey][r.sx-1][c]+D[r.sy-1][r.sx-1][c];
		ans = min(ans, v);
	}
	cout << ans << endl;
}