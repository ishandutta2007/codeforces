#include <iostream>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string.h>
#include <cstdio>

#define wait system("pause")
#define MP make_pair

using namespace std;

const int MAXN = (int)1e5 + 10;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

vi ady[26];
int ID[26];
char W[2][1000];
char ANS[1000];
bool ok;

void join(int a, int b)
{
    int len = min(strlen(W[0]), strlen(W[1]));
    for (int i = 0; i < len; ++i)
    {
        if (W[0][i] == W[1][i]) continue;
        ady[W[a][i] - 'a'].push_back(W[b][i] - 'a');
        ID[W[b][i] - 'a']++;
        return;
    }

    if (strlen(W[a]) > strlen(W[b])){
        printf("Impossible\n");
        exit(0);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    string s1, s2; 
    scanf("%s", W[0]);
    for (int i = 1, cur = 1; i < n; ++i, cur ^= 1)
    {
        scanf("%s", W[cur]);
        join(cur ^ 1, cur);
    }
    queue<int> Q;
    for (int i = 0; i < 26; ++i)
    {
        if (ID[i] == 0) Q.push(i);
    }

    int tot = 0;

    while (!Q.empty())
    {
        int cur = Q.front(); Q.pop();
        ANS[tot++] = (char)(cur + 'a');
        for (int i = 0; i < (int)ady[cur].size(); ++i)
        {
            int nx = ady[cur][i];
            ID[nx]--;
            if (ID[nx] == 0) Q.push(nx);
        }
    }

    if (tot == 26) printf("%s\n", ANS);
    else printf("Impossible\n");
}