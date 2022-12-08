#include <stdio.h>

int n,m; char s[101][101];
bool chk[101];

int main()
{
    scanf ("%d %d",&n,&m);
    for (int i=0;i<n;i++) scanf ("%s",s[i]);
    for (int v=0;v<m;v++){
        for (int i=1;i<n;i++){
            for (int j=0;j<m;j++) if (!chk[j]){
                if (s[i-1][j] < s[i][j]) break;
                else if (s[i-1][j] > s[i][j]) chk[j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i=0;i<m;i++) ans += chk[i];
    printf ("%d\n",ans);

    return 0;
}