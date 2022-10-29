#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(n) ((int)(n).size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int n,m,mxl,mxr,vis[3000][3000];
string s[3000];
ii mov[] = {{1,0},{-1,0},{0,1},{0,-1}};

bool val(int i,int j, int l, int r){
  return i >= 0 && i < n && j >= 0 && j < m && s[i][j] != '*' && !vis[i][j] && l <= mxl && r <= mxr;
}

int bfs(int sx, int sy){
  deque<pair<ii,ii>> q;
  q.push_front({{sx,sy},{0,0}});
  int ans = 0;
  while(q.size()){
    int x = q.front().fst.fst, y = q.front().fst.snd, l = q.front().snd.fst, r = q.front().snd.snd;
    q.pop_front();
    if(!vis[x][y]){
      vis[x][y] = true;
      ans++;
      for(auto xx : mov){
        int nx = x+xx.fst, ny = y+xx.snd, nl = l+(ny<y), nr = r+(ny>y);
        if(!val(nx,ny,nl,nr)) continue;
        if(xx.snd) q.push_back({{nx,ny},{nl,nr}});
        else q.push_front({{nx,ny},{nl,nr}});
      }
    }
  }
  return ans;
}

int main(){FIN;
  int x,y;
  cin >> n >> m >> x >> y >> mxl >> mxr; x--; y--;
  fore(i,0,n) cin >> s[i];
  cout << bfs(x,y) << endl;
}