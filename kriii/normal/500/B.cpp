#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int p[303][303],c[303];
int N,P[303];

int main()
{
    scanf ("%d",&N);
    for (int i=1;i<=N;i++) scanf ("%d",&P[i]);
    for (int i=1;i<=N;i++) for (int j=1;j<=N;j++) scanf ("%1d",&p[i][j]);
    for (int k=1;k<=N;k++) for (int i=1;i<=N;i++) if (p[i][k]) for (int j=1;j<=N;j++) if (p[k][j]) p[i][j] = 1;

    for (int i=1;i<=N;i++) if (!c[i]){
        vector<int> l,u;
        for (int j=1;j<=N;j++) if (p[i][j]){
            l.push_back(j);
            u.push_back(P[j]);
            c[j] = 1;
        }
        sort(u.begin(),u.end());
        for (int j=0;j<l.size();j++) P[l[j]] = u[j];
    }

    for (int i=1;i<=N;i++) printf ("%d ",P[i]);

    return 0;
}