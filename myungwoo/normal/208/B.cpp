#include <stdio.h>
#include <queue>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))

int N;
char C[53][3];
bool V[53][53][53][53];

struct Q{
    int n,a,b,c;
};
queue <Q> que;

void iq(int n,int a,int b,int c)
{
    if (V[n][a][b][c]) return;
    Q q={n,a,b,c};
    que.push(q);
    V[n][a][b][c] = 1;
}

bool possible(int a,int b)
{
    if (C[a][0] == C[b][0] || C[a][1] == C[b][1]) return 1;
    return 0;
}

int main()
{
    int i;
    Q q;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%s",C[i]);
    iq(N,max(0,N-2),max(0,N-1),N);
    while (!que.empty()){
        q = que.front(); que.pop();
        if (q.n > 3){
            if (possible(q.n-3,q.c)){
                iq(q.n-1,q.c,q.a,q.b);
            }
        }
        if (q.n > 1){
            if (possible(q.b,q.c)){
                iq(q.n-1,max(0,q.n-3),q.a,q.c);
            }
        }
        if (q.n == 1){ puts("YES"); return 0; }
    }
    puts("NO");
}