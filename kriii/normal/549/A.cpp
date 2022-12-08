#include <stdio.h>
#include <algorithm>
using namespace std;

char S[55][55];
int N,M;

int main()
{
    scanf ("%d %d",&N,&M);
    for (int i=0;i<N;i++) scanf ("%s",S[i]);
    int ans = 0;
    for (int i=1;i<N;i++) for (int j=1;j<M;j++){
        char a[4] = {'a','c','e','f'};
        do{
            if (S[i-1][j-1] == a[0] && S[i-1][j] == a[1] && S[i][j-1]  == a[2] && S[i][j] == a[3]){
                ans++;
            }
        }while(next_permutation(a,a+4));
    }
    printf ("%d\n",ans);

    return 0;
}