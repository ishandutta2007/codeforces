#include <stdio.h>

long long c1[55],c2[55],con[55][2][2];
int st[55],ed[55];

long long X;
int K,N,M;

int maxi(int L, int s, int e)
{
    int r;
    if (s == 0){
        if (e < 2) L--;
        r = L / 2;
    }
    else{
        L--;
        if (e < 2) L--;
        r = L / 2;
    }

    return r;
}

int isp(int L, int s, int e, int l)
{
    if (L == 2){
        if (s == 0 && e == 2) return l == 1;
    }
    return l <= maxi(L,s,e);
}

void get(int L, int s, int e, int l)
{
    if (L == 1){
        putchar('A'+s);
    }
    else{
        int c = 0;
        L -= 2;
        if (s == 0) c = 1;
        putchar('A'+s);
        while (L--){
            if (l){
                if (c == 0) putchar('A');
                else{
                    putchar('C'); l--;
                }
                c = 1-c;
            }
            else putchar('B');
        }
        putchar('A'+e);
    }

    puts("");
}

int main()
{
    int i,k,m;
    int s1,e1,s2,e2,l1,l2;

    scanf ("%d %lld %d %d",&K,&X,&N,&M);
    c1[1] = 1; c2[2] = 1;
    st[1] = ed[1] = 0;
    st[2] = ed[2] = 1;

    for (i=3;i<=K;i++){
        c1[i] = c1[i-2] + c1[i-1];
        c2[i] = c2[i-2] + c2[i-1];
        con[i][0][0] = con[i-2][0][0] + con[i-1][0][0];
        con[i][0][1] = con[i-2][0][1] + con[i-1][0][1];
        con[i][1][0] = con[i-2][1][0] + con[i-1][1][0];
        con[i][1][1] = con[i-2][1][1] + con[i-1][1][1];
        st[i] = st[i-2];
        ed[i] = ed[i-1];
        con[i][ed[i-2]][st[i-1]]++;
    }

    for (s1=0;s1<3;s1++) for (e1=0;e1<3;e1++){
        if (N == 1 && s1 != e1) continue;
        for (s2=0;s2<3;s2++) for (e2=0;e2<3;e2++){
            if (M == 1 && s2 != e2) continue;

            long long p = 0;
            if (e1 == 0 && s1 == 2) p += con[K][0][0];
            if (e1 == 0 && s2 == 2) p += con[K][0][1];
            if (e2 == 0 && s1 == 2) p += con[K][1][0];
            if (e2 == 0 && s2 == 2) p += con[K][1][1];
            
            m = maxi(N,s1,e1);
            for (k=0;k<=m;k++) if (isp(N,s1,e1,k)){
                long long u = p + c1[K] * k;
                if (u <= X && (X - u) % c2[K] == 0){
                    l1 = k;
                    l2 = (X-u) / c2[K];
                    if (isp(M,s2,e2,l2)){
                        get(N,s1,e1,l1);
                        get(M,s2,e2,l2);
                        return 0;
                    }
                }
            }
        }
    }

    puts("Happy new year!");

    return 0;
}