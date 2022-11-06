#include <bits/stdc++.h>
using namespace std;
const int N = 100005, M = 7;
int n, m, k;
int a[N][M];
priority_queue<pair<int, int> > Q[M];
void czysc(int P)
{
    for(int i = 1; i <= m; i++)
        while(Q[i].top().second < P)
            Q[i].pop();
}
bool tooLarge(int P)
{
    czysc(P);
    int sum = 0;
    for(int i = 1; i <= m; i++)
        sum += Q[i].top().first;
    if(sum > k) return true;
    return false;   
}
void insert(int w)
{
    for(int i = 1; i <= M; i++)
        Q[i].push(make_pair(a[w][i], w));
}
int main()
{
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int poc = 1;
    int ans = 0;
    vector<int> ret;
    for(int i = 1; i <= m; i++)
        ret.push_back(0);
    for(int i = 1; i <= n; i++)
    {
        insert(i);
        while(poc <= i && tooLarge(poc))
            poc++;
        if(i - poc + 1 > ans)
        {
            ans = i - poc + 1;
            for(int j = 1; j <= m; j++)
                ret[j - 1] = Q[j].top().first;
        }
    }
    for(int j = 0; j < m; j++)
        printf("%d ", ret[j]);
    return 0;
}