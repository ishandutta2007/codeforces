#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 60;
string s[maxn];
bool visited[maxn][maxn];
int n , m;
bool l;
char xx = '.';
int res;
vector<pair<int,int> >deq;
deque<pair<int,int> >dq;
pair<int,int>pa;
bool zz;
void dfs(int x,int y,char k)
{
    visited[x][y] = !zz;
    s[x][y] = xx;
    res++;
    for(int i = -1; i < 2; i++)
        for(int j = -1; j < 2; j++)
        {
            if(abs(i) != abs(j))
            {
                int a = i + x;
                int b = j + y;
                if(a < 0 || a > n) continue;
                if(b < 0 || b > m) continue;
                if(s[a][b] == k && visited[a][b] == zz)
                    dfs(a,b,k);
            }
        }
}
int main()
{
    int k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(j == 0 || i == 0 || i == n-1 || j == m-1)
                if(!visited[i][j] && s[i][j] == '.')
                    dfs(i,j,'.');
        }
    }
    l = 1;
    int res1 = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            res = 0;
            if(s[i][j] == '.' && !visited[i][j])
            {
                dfs(i,j,'.');
                pa.first = i;
                pa.second = j;
                dq.push_back(pa);
                pa.first = res;
                pa.second = dq.size() - 1;
                deq.push_back(pa);
                res1++;
            }
        }
    }
    xx = '*';
    res1 = 0;
    sort(deq.begin(),deq.end());
    zz = 1;
    int i = 0;
    while(deq.size() - i > k)
    {
        int u = deq[i].second;
        res1 += deq[i].first;
        dfs(dq[u].first,dq[u].second,'.');
        i++;
    }
    cout << res1 << endl;
    for(int i = 0; i < n; i++)
        cout << s[i] << endl;
}