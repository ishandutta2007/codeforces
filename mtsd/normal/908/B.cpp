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
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

long long  mod = 1000000007;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int p[4];
char v[100][100];

int main(){
	int n,m;
	cin >> n >> m;
	vector<string> s(n);
	for(int i=0;i<n;i++){
		cin >> s[i];
	}
	string ss;
	cin >> ss;
	for(int i=0;i<=n+1;i++){
		v[i][0]= '#';
		v[i][m+1]='#';
	}
	for(int i=0;i<=m+1;i++){
		v[0][i]= '#';
		v[n+1][i]= '#';
	}
	pair<int,int> st,te;
	for(int i=1;i<n+1;i++){
		for(int j=1;j<m+1;j++){
			v[i][j] = s[i-1][j-1];
			if(v[i][j]=='S'){
				st = MP(i,j);
			}
			if(v[i][j]=='E'){
				te = MP(i,j);
			}
		}
	}
	int ans = 0;
	rep(i,4){
		rep(j,4){
			if(i==j)continue;
			rep(k,4){
				if(i==k||j==k)continue;
				rep(l,4){
					if(i==l||j==l||k==l)continue;
					p[0]=i;
					p[1]=j;
					p[2]=k;
					p[3]=l;
					int x = 0;
					pair<int,int> g = st;
					while(1){
						if(x==ss.size())break;
						g = MP(g.first+dx[p[ss[x]-'0']],g.second+dy[p[ss[x]-'0']]);
						//cout << g.first << " " << g.second << endl;
						if(v[g.first][g.second]=='#')break;
						if(g==te){
							ans++;
							//cout << i << " " << j << " " << k << " " << l << endl;
							break;
						}
						x++;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}