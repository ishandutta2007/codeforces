#include <stdio.h>
#include <string>
using namespace std;

int N,V[27];
string com[27];

string ex(int n){ string ret="eax"; ret[1] += n; return ret; }

bool dfs(int max,int n)
{
    int i,j,k;
    if (V[n] > N) return 0;
    if (n == max){
        if (V[n] != N) return 0;
        printf("%d\n",n);
        for (i=1;i<=n;i++) puts(com[i].c_str());
        return 1;
    }
    for (i=0;i<=n;i++) for (k=1;k<9;k<<=1){
        V[n+1] = V[i]*k;
        if (V[n+1] > N || n+1 == max && V[n+1] != N) continue;
        com[n+1] = "lea "+ex(n+1)+", ["+char(k+'0')+"*"+ex(i)+"]";
        if (dfs(max,n+1)) return 1;
    }
    for (i=0;i<=n;i++) for (j=0;j<=n;j++) for (k=1;k<9;k<<=1){
        V[n+1] = V[i]+V[j]*k;
        if (V[n+1] > N || n+1 == max && V[n+1] != N) continue;
        com[n+1] = "lea "+ex(n+1)+", ["+ex(i)+" + "+char(k+'0')+"*"+ex(j)+"]";
        if (dfs(max,n+1)) return 1;
    }
    return 0;
}

int main()
{
    int i;
    scanf("%d",&N);
    V[0] = 1;
    for (i=0;;i++) if (dfs(i,0)) break;
}