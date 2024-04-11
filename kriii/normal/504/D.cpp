#include <stdio.h>
#include <algorithm>
using namespace std;

char str[606];
long long tmp[80];
long long mat[2000][32];
int see[2000];

int main()
{
    int M;

    scanf ("%d",&M);
    for (int i=0;i<M;i++){
        scanf ("%s",str);
        int len = 0;
        while(str[len]) len++;
        for (int j=0;j<80;j++) tmp[j] = 0;
        for (int j=0;j<len;j++){
            long long &t = tmp[(len-j-1)/8];
            t = t * 10 + str[j] - '0';
        }
        for (int j=0;j<250;j++){
            long long t = tmp[0] & 255;
            for (int k=0;k<8;k++) if (t & (1 << k)) mat[j*8+k][i/64] |= 1ll << (i%64);
            for (int k=79;k;k--){
                tmp[k-1] += (tmp[k] & 255) * 100000000ll;
                tmp[k] >>= 8;
            }
            tmp[0] >>= 8;
        }
    }

    for (int i=0,j=0;i<2000&&j<M;j++){
        bool seen = false;
        for (int k=i;k<2000;k++){
            if (mat[k][j/64] & (1ll << (j % 64))){
                for (int l=j/64;l<32;l++){
                    swap(mat[i][l],mat[k][l]);
                }
                seen = true;
                break;
            }
        }
        if (!seen){
            int cnt = 0;
            for (int k=0;k<i;k++) if (mat[k][j/64] & (1ll << (j % 64))) cnt++;
            printf ("%d",cnt);
            for (int k=0;k<i;k++) if (mat[k][j/64] & (1ll << (j % 64))) printf (" %d",see[k]); puts("");
            continue;
        }

        see[i] = j;
        printf ("0\n");
        for (int k=0;k<2000;k++) if (k != i && (mat[k][j/64] & (1ll << (j % 64)))){
            for (int l=j/64;l<32;l++) mat[k][l] ^= mat[i][l];
        }
        i++;
    }

    return 0;
}