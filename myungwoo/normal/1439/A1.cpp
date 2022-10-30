#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int N, M; scanf("%d%d", &N, &M);
	vector<vector<int>> arr(N+1, vector<int>(M+1, 0));
	vector<array<int, 6>> ans;
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) scanf("%1d", &arr[i][j]);
	auto stamp = [&](int ax, int ay, int bx, int by, int cx, int cy){
		ans.push_back({ax, ay, bx, by, cx, cy});
		arr[ax][ay] ^= 1; arr[bx][by] ^= 1; arr[cx][cy] ^= 1;
	};
	for (int i=N;i>2;i--){
		for (int j=1;j<=M;j++) if (arr[i][j]){
			if (j == M) stamp(i-1, j-1, i-1, j, i, j);
			else stamp(i-1, j, i-1, j+1, i, j);
		}
	}
	for (int j=M;j>2;j--){
		for (int i=1;i<=2;i++) if (arr[i][j]){
			stamp(1, j-1, 2, j-1, i, j);
		}
	}
	for (int msk=1;msk<16;msk++){
		array<array<int, 2>, 2> a = {0,};
		for (int b=0;b<4;b++) if (msk>>b&1){
			for (int i=0;i<2;i++) for (int j=0;j<2;j++) if (i*2+j != b) a[i][j] ^= 1;
		}
		bool identical = 1;
		for (int i=0;i<2;i++) for (int j=0;j<2;j++) if (a[i][j] != arr[i+1][j+1]) identical = 0;
		if (!identical) continue;
		for (int b=0;b<4;b++) if (msk>>b&1){
			vector<int> s;
			for (int i=0;i<2;i++) for (int j=0;j<2;j++) if (i*2+j != b) s.push_back(i+1), s.push_back(j+1);
			stamp(s[0], s[1], s[2], s[3], s[4], s[5]);
		}
		break;
	}
	printf("%d\n", (int)ans.size());
	for (auto &row: ans){
		for (int j=0;j<6;j++) printf("%d%s", row[j], j+1 < 6 ? " " : "\n");
	}
	// for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) fprintf(stderr, "%d%s", arr[i][j], j < M ? " " : "\n");
	for (int i=1;i<=N;i++) for (int j=1;j<=M;j++) assert(arr[i][j] == 0);
}

int main()
{
	int T;
	for (scanf("%d", &T);T--;) solve();
}