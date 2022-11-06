#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 10;
char s[N];
int vis[30];
int n, k, tot = 0;
int solve() 
{
    int tot = n / k;
    for(int i = 0; i < 26; i ++)
    {
        if(vis[i] == 0 || tot == 0) return i;
        vis[i] --; 
        tot --;
    }
}
int main() 
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        scanf("%d%d", &n, &k);
        scanf("%s", s + 1);
        for(int i = 0; i <= 26; i ++) vis[i] = 0;
        tot = n;
        for(int i = 1; i<= n; i ++) vis[s[i] - 'a'] ++;
        for(int i = 1; i <= k; i ++)
        {
            int x = solve();
            cout << char('a' + x);
        }
        puts("");
    }
    return 0;
}