#include <stdio.h>
#include <vector>
using namespace std;

int N,P[100100],C[100100];

int main()
{
    scanf ("%d",&N);
    for (int i=1;i<=N;i++) scanf ("%d",&P[i]);

    for (int i=1;i<=N;i++){
        if (P[i] == i){
            puts("YES");
            for (int j=1;j<=N;j++) if (i != j) printf ("%d %d\n",i,j);
            return 0;
        }
    }

    int a[2] = {-1};
    vector<int> u;
    for (int i=1;i<=N;i++) if (!C[i]){
        if (P[P[i]] == i){
            a[0] = i; a[1] = P[i];
            C[i] = C[P[i]] = 1;
            break;
        }
    }
    if (a[0] == -1){
        puts("NO");
        return 0;
    }
    for (int i=1;i<=N;i++) if (!C[i]){
        int x = i, l = 0;
        while (!C[x]){
            u.push_back(x);
            C[x] = 1; l++; x = P[x];
        }
        if (l % 2){
            puts("NO");
            return 0;
        }
    }

    puts("YES");
    printf ("%d %d\n",a[0],a[1]);
    for (int i=0;i<u.size();i++) printf ("%d %d\n",a[i%2],u[i]);

    return 0;
}