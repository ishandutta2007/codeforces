#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

int dx[] = {0,1,-1,0};
int dy[] = {1,0,0,-1};

bool flag2[4][1010][1010];

int main(){
	cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	vector<string>s(n);
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	vector<vector<int> > v(n+2,vector<int>(m+2));
	for(int i=0;i<n+2;i++){
		for(int j=0;j<m+2;j++){
			if(i==0||j==0||j==m+1||i==n+1){
				v[i][j]=0;
			}else{
				if(s[i-1][j-1]=='.'){
					v[i][j] = 1;
				}else{
					v[i][j] = 0;
				}
			}
		}		
	}
	/*for(int i=0;i<n+2;i++){
		for(int j=0;j<m+2;j++){
			cout << v[i][j];
		}
		cout << endl;
	}*/
	vector<vector<int> > dist(n+2,vector<int>(m+2,inf));
	vector<vector<bool> > flag(n+2,vector<bool>(m+2));
	queue<pair<int,int> > q;
	q.push(MP(x1,y1));
	dist[x1][y1]=0;
	flag[x1][y1]=true;
	while(!q.empty()){
		PII p = q.front();
		//cout << p.first << " " << p.second << endl;
		q.pop();
		int x = p.first;
		int y = p.second;
		v[x][y] = 0;
		int tx = x;
		int ty = y;
		for(int i=0;i<4;i++){
			tx = x;
			ty = y;
			for(int j=0;j<k;j++){
				tx += dx[i];
				ty += dy[i];
				if(v[tx][ty]==0)break;
				if(flag2[i][tx][ty]==1)break;
				if(flag[tx][ty]==0){
					dist[tx][ty] = min(dist[tx][ty],dist[x][y]+1);
					if(tx==x2&&ty==y2){
						cout << dist[x2][y2] << endl;
						return 0;
					}
					flag[tx][ty] = 1;
					flag2[i][tx][ty] = 1;
					flag2[3-i][tx][ty] = 1;
					q.push(MP(tx,ty));
				}
			}
		}
	}
	/*for(int i=0;i<n+2;i++){
		for(int j=0;j<m+2;j++){
			if(dist[i][j]==inf){
				cout << "#";
			}else{
				cout << dist[i][j];
			}
		}
		cout << endl;
	}*/
	if(dist[x2][y2]==inf){
		cout << -1 << endl;
	}else{
		cout << dist[x2][y2] << endl;
	}
	return 0;
}