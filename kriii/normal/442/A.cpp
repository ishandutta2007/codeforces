#include <stdio.h>

int bc(int x)
{
    int cnt = 0;
    while (x){
        cnt++;
        x -= x & (-x);
    }
    return cnt;
}

bool chk[5][5],rev[5][5];

int main()
{
    char S[5]; int N;

    scanf ("%d",&N); while (N--){
        scanf ("%s",S);
        int p;
        if (S[0] == 'R') p = 0;
        if (S[0] == 'G') p = 1;
        if (S[0] == 'B') p = 2;
        if (S[0] == 'Y') p = 3;
        if (S[0] == 'W') p = 4;
        chk[p][S[1]-'1'] = 1;
    }

    int ans = 10;
    for (int b=0;b<32;b++) for (int c=0;c<32;c++){
        for (int i=0;i<5;i++) for (int j=0;j<5;j++) rev[i][j] = 0;
        int cnt = 0, px, py;
        for (int i=0;i<5;i++) if ((b & (1 << i)) > 0){
            cnt = 0;
            for (int j=0;j<5;j++) if (chk[i][j]){
                cnt++; px = i; py = j;
            }
            if (cnt == 1) rev[px][py] = 1;
        }
        for (int j=0;j<5;j++) if ((c & (1 << j)) > 0){
            cnt = 0;
            for (int i=0;i<5;i++) if (chk[i][j]){
                cnt++; px = i; py = j;
            }
            if (cnt == 1) rev[px][py] = 1;
        }
        cnt = 0;
        for (int i=0;i<5;i++) for (int j=0;j<5;j++) if (chk[i][j]){
            if ((b & (1 << i)) > 0 && (c & (1 << j)) > 0) rev[i][j] = 1;
            if ((b & (1 << i)) == 0 && (c & (1 << j)) == 0) cnt++, px = i, py = j;
        }
        if (cnt == 1) rev[px][py] = 1;

        bool ch = true;
        while (ch){
            ch = false;
            for (int i=0;i<5;i++) if ((b & (1 << i)) > 0){
                cnt = 0;
                for (int j=0;j<5;j++) if (chk[i][j] && !rev[i][j]){
                    cnt++; px = i; py = j;
                }
                if (cnt == 1) rev[px][py] = 1, ch = 1;
            }
            for (int j=0;j<5;j++) if ((c & (1 << j)) > 0){
                cnt = 0;
                for (int i=0;i<5;i++) if (chk[i][j] && !rev[i][j]){
                    cnt++; px = i; py = j;
                }
                if (cnt == 1) rev[px][py] = 1, ch = 1;
            }
        }
        for (int i=0;i<5;i++) for (int j=0;j<5;j++) if (chk[i][j] && !rev[i][j]) ch = true;
        if (!ch){
            int u = bc(b) + bc(c);
            if (ans > u)
                ans = u;
        }
    }

    printf ("%d\n",ans);

    return 0;
}