#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

bool chk[8][8];

vector<pair<int, int> > go(int sx, int sy, int ex, int ey)
{
	bool seen[8][8] = {0,}; pair<int, int> via[8][8];
	queue<pair<int, int> > Q;
	Q.push({sx,sy}); via[sx][sy] = {-1,-1}; seen[sx][sy] = 1;
	int dx[8] = {1,2,2,1,-1,-2,-2,-1};
	int dy[8] = {2,1,-1,-2,-2,-1,1,2};
	while (!Q.empty()){
		int x = Q.front().first, y = Q.front().second; Q.pop();
		for (int k=0;k<8;k++){
			int px = x + dx[k], py = y + dy[k];
			if (px < 0 || px > 7 || py < 0 || py > 7) continue;
			if (!seen[px][py]){
				Q.push({px,py}); via[px][py] = {x,y}; seen[px][py] = 1;
			}
		}
	}

	vector<pair<int, int> > res;
	while (ex >= 0){
		res.push_back({ex,ey});
		int x = via[ex][ey].first, y = via[ex][ey].second;
		ex = x;
		ey = y;
	}
	reverse(res.begin(),res.end());
	return move(res);
}

int main()
{
	struct mv{int a,b,c,d;};
	vector<mv> ans;

	int N; scanf ("%d",&N); for (int t=0;t<N;t++){
		char S[5]; scanf ("%s",S);
		int x = S[1] - '1', y = S[0] - 'a';
		chk[x][y] = 1;
	}

	for (int c=0;c<N;c++){
		int x = c / 8, y = c % 8;
		if (chk[x][y]) continue;

		for (int d=c;d<64;d++){
			int px = d / 8, py = d % 8;
			if (!chk[px][py]) continue;
			auto pt = go(px,py,x,y);
			for (int i=1;i<pt.size();i++){
				int j = i;
				while (j < pt.size() && chk[pt[j].first][pt[j].second]) j++;
				for (int k=j;k>=i;k--){
					ans.push_back({pt[k-1].first,pt[k-1].second,pt[k].first,pt[k].second});
				}
				chk[pt[j].first][pt[j].second] = 1;
				chk[pt[i-1].first][pt[i-1].second] = 0;
				i = j;
			}
			break;
		}
	}

	printf ("%d\n",ans.size());
	for (auto m : ans){
		printf ("%c%d-%c%d\n",m.b+'a',m.a+1,m.d+'a',m.c+1);
	}

	return 0;
}