 #include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1000100
int n, m, a, b;
vector <int> v[maxn];
bool odw[maxn];
char s[1010][1010];
int passable[maxn];
int kladliwe[maxn];
inline int num(int i, int j) {
    return i * m + j;
}
queue <int> q;
bool dodane[4];
int odl[maxn][4];
int skl_odl[5][5];
vector <int> SKL[4];


void bfs(int skladowa) {
    
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (kladliwe[x] > 1) {
            int type = kladliwe[x] - 100;
            if (type != skladowa && dodane[type] == 0) {
            --odl[x][skladowa];
            dodane[type] = 1;
            for (ui j=0; j<SKL[type].size(); ++j)
            {
                odl[SKL[type][j]][skladowa] = odl[x][skladowa];
                q.push(SKL[type][j]);
            }
            }
        }

        for (ui i=0; i<v[x].size(); ++i)
        {
            int u = v[x][i];
            if (odl[u][skladowa] == -1) {
                odl[u][skladowa] = odl[x][skladowa] + 1;
                q.push(u);
            }
        }
    }
}
int sasiedzi[4][4];

void check(int a, int b, int c, int d) {
    if (s[a][b] < '1' || s[a][b] > '3' || s[c][d] < '1' || s[c][d] > '3') return;
    int n1 = s[a][b] - '0', n2 = s[c][d] - '0';
    sasiedzi[n1][n2] = 1;
    sasiedzi[n2][n1] = 1;
}

int exist[4];

int main() {
    scanf("%d%d", &n, &m);
    for (int j=1; j<=3; ++j)
      for (int k=1; k<=3; ++k) {
          if (j == k) skl_odl[j][k] = 0;
          else skl_odl[j][k] = inf;
      }
    exist[1] = exist[2] = exist[3] = 1;
    for (int i=0; i<n; ++i) scanf("%s", s[i]);
    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j) check(i, j, i + 1, j), check(i, j, i, j + 1);
    sasiedzi[1][1] = sasiedzi[2][2] = sasiedzi[3][3] = 1;
    if (sasiedzi[1][2] || sasiedzi[1][3])
      if (sasiedzi[2][3]) sasiedzi[1][3] = sasiedzi[1][2] = sasiedzi[2][1] = sasiedzi[3][1] = 1;    

      if (sasiedzi[1][2]) exist[2] = 0;
      if (sasiedzi[1][3]) exist[3] = 0;
      if (sasiedzi[2][3]) exist[3] = 0;
    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j)
    {
        if (s[i][j] < '1' || s[i][j] > '3') continue;
        int nr = s[i][j] - '0';
        if (sasiedzi[nr][1]) s[i][j] = '1';
        else if (sasiedzi[nr][2]) s[i][j] = '2';
    }

    for (int i=0; i<n; ++i)
    {  
        for (int j=0; j<m; ++j) {
          if (s[i][j] != '#') passable[num(i, j)] = 1;
          else passable[num(i,j)] = 0;
          if (s[i][j] == '.') kladliwe[num(i, j)] = 1;
          if (s[i][j] == '1') kladliwe[num(i, j)] = 101;
          if (s[i][j] == '2') kladliwe[num(i, j)] = 102;
          if (s[i][j] == '3') kladliwe[num(i, j)] = 103;
      }
    }

    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j)
      {
          int nr = num(i, j);
          if (passable[nr]) {
            if (i > 0 && passable[num(i-1, j)]) v[nr].pb(num(i-1, j));
            if (j > 0 && passable[num(i, j-1)]) v[nr].pb(num(i, j-1));
            if (i < n-1 && passable[num(i+1,j)]) v[nr].pb(num(i+1, j));
            if (j < m-1 && passable[num(i,j+1)]) v[nr].pb(num(i, j+1));
          }
      }

   for (int i=0; i<n; ++i)
     for (int j=0; j<m; ++j)
         if (s[i][j] >= '1' && s[i][j] <= '3') SKL[s[i][j] - '0'].push_back(num(i, j));

    for (int i=0; i<maxn; ++i)
      for (int j=0; j<4; ++j) odl[i][j] = -1;
      
    for (int skl=1; skl<=3; ++skl) 
    if (exist[skl]) {
        for (int j=0; j<4; ++j) dodane[j] = 0;
        while (!q.empty()) q.pop();  
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
            if (s[i][j] == (char)(skl + '0')) q.push(num(i, j)), odl[num(i, j)][skl] = 0;
        bfs(skl);
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j)
            if (s[i][j] >= '1' && s[i][j] <= '3') 
            {
                int help = s[i][j]-'0';
                skl_odl[skl][help] = min(skl_odl[skl][help], odl[num(i, j)][skl]);
                skl_odl[help][skl] = min(skl_odl[help][skl], odl[num(i, j)][skl]);
            }
    }

  int usage = exist[1] + exist[2] + exist[3];
    skl_odl[1][1] = skl_odl[2][2] = skl_odl[3][3] = 0;
    for (int i=1; i<=3; ++i)
      for (int j=1; j<=3; ++j)
      if (i != j && skl_odl[i][j] == -1) OUT("-1");
    int wyn = inf;
    for (int i=1; i<=3; ++i) 
    {
        int tmp = 0;
        if (exist[i] == 0) continue;
        for (int j=1; j<=3; ++j)
          if (exist[j]) tmp += skl_odl[i][j];
        wyn = min(wyn, tmp);
    }
    
   /*for (int a=1; a<=3; ++a) {
    for (int i=0; i<n; ++i) {
      for (int j=0; j<m; ++j) printf("%d ", odl[num(i, j)][a]);
      puts("");
  }
  puts("");
    }*/

    for (int i=0; i<n; ++i)
      for (int j=0; j<m; ++j) {
          if (s[i][j] == '.') {
              int nr = num(i, j);
              int tmp = 0; bool zly = false;
              for (int help = 1; help <= 3; ++help) {
                if (exist[help]) tmp += odl[nr][help];
                if (odl[nr][help] == -1) zly = true;
            }
              tmp-=(usage-1);
              if (!zly) wyn = min(wyn, tmp);
          }
      }

    if (wyn == inf) puts("-1");
    else printf("%d", max(0, wyn));
}