#include <bits/stdc++.h>
using namespace std;
const int N = 100, A = 30;
int n;
char word[N + 5][N + 5];
bool isDifferent[N + 5];
queue<int>Q;
vector<int> V[A];
int st[A];
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s", &word[i][1]);
    }
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(isDifferent[j] == false && word[j][i] != word[j + 1][i] && word[j][i] != 0)
            {
                if(word[j][i] != 0 && word[j + 1][i] == 0)
                {
                    printf("Impossible\n");
                    return 0;
                }
                st[word[j + 1][i] - 96]++;
                isDifferent[j] = true;
                V[word[j][i] - 96].push_back(word[j + 1][i] - 96);
            }
        }
    }
    
    for(int i = 1; i <= 26; i++)
    {
        if(st[i] == 0)
        {
            Q.push(i);
        }
    }
    vector<int>result;
    while(!Q.empty())
    {
        int w = Q.front();
        Q.pop();
        result.push_back(w);
        for(int i = 0; i < V[w].size(); i++)
        {
            int u = V[w][i];
            st[u]--;
            if(st[u] == 0)
                Q.push(u);
        }
    }
    if(result.size() < 26)
    {
        printf("Impossible\n");
        return 0;
    }
    for(int i = 0; i < result.size(); i++)
        printf("%c", char(result[i] + 96));
    return 0;
}