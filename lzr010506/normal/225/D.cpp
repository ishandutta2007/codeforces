/*
1234@
xystatus400,01,10,11len(len-1)*2BFSstatus|=vis[x][y][status]
*/
#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, m, x, y, c = 0, p, i, j;
    int a[10][2];
    char s[15][16];
    queue <pair<int, int> > q;
    set <int> se;
    
    scanf("%d %d", &n, &m);
    
    for (i = 0; i < n; i++) scanf("%s", s[i]);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (s[i][j] == '@') {
                x = i;
                y = j;
            } else if (s[i][j] >= '1' && s[i][j] <= '9') {
                c++;
                
                a[s[i][j] - '0'][0] = i;
                a[s[i][j] - '0'][1] = j;
            }
        }
    }
    
    p = a[1][0] | (a[1][1] << 4);
    
    for (i = 2; i <= c; i++) {
        int f;
        
        if (a[i][0] == a[i - 1][0] - 1) {
            f = 0;
        } else if (a[i][1] == a[i - 1][1] + 1) {
            f = 1;
        } else if (a[i][0] == a[i - 1][0] + 1) {
            f = 2;
        } else {
            f = 3;
        }
        
        p |= (f << ((i - 2) * 2 + 8));
    }
    
    se.insert(p);
    q.push(make_pair(0, p));
    
    while (!q.empty()) {
        int t = q.front().first;
        int p = q.front().second;
        
        q.pop();
        
        a[1][0] = p & 15;
        a[1][1] = (p >> 4) & 15;
        
        if (a[1][0] == x && a[1][1] == y) {
            printf("%d\n", t);
            
            return 0;
        }
        
        for (i = 2; i <= c; i++) {
            int f = (p >> ((i - 2) * 2 + 8)) & 3;
            
            a[i][0] = a[i - 1][0];
            a[i][1] = a[i - 1][1];
            
            if (f == 0) {
                a[i][0]--;
            } else if (f == 1) {
                a[i][1]++;
            } else if (f == 2) {
                a[i][0]++;
            } else {
                a[i][1]--;
            }
        }
        
        for (i = 0; i < 4; i++) {
            int b[10][2];
            int f = 0;
            
            b[1][0] = a[1][0] + dx[i];
            b[1][1] = a[1][1] + dy[i];
            
            if (b[1][0] < 0 || b[1][0] >= n) continue;
            if (b[1][1] < 0 || b[1][1] >= m) continue;
            if (s[b[1][0]][b[1][1]] == '#') continue;
            
            for (j = 2; j <= c; j++) {
                b[j][0] = a[j - 1][0];
                b[j][1] = a[j - 1][1];
                
                if (b[j][0] == b[1][0] && b[j][1] == b[1][1]) f = 1;
            }
            
            if (f == 1) continue;
            
            p = b[1][0] | (b[1][1] << 4);
            
            for (j = 2; j <= c; j++) 
            {
                if (b[j][0] == b[j - 1][0] - 1) 
                    f = 0;
                else if (b[j][1] == b[j - 1][1] + 1) 
                    f = 1;
                else if (b[j][0] == b[j - 1][0] + 1)
                    f = 2;
                else 
                    f = 3;
                p |= (f << ((j - 2) * 2 + 8));
            }
            
            if (se.count(p)) continue;
            
            se.insert(p);
            q.push(make_pair(t + 1, p));
        }
    }
    
    puts("-1");
    
    return 0;
}