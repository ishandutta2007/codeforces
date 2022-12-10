#include <stdio.h>

int N,M;
int s,f,t,v;

int main()
{
    scanf ("%d %d",&N,&M);
    while (N--){
        scanf ("%d %d %d",&s,&f,&t); s--; f--;
        if (s == f){printf ("%d\n",t); continue;}
        v = t / (2 * M - 2); t %= 2 * M - 2;
        if (t < M){
            if (t > s){
                s = M * 2 - 2 - s;
                f = M * 2 - 2 - f;
                if (f < s){
                    f = M * 2 - 2 - f;
                    v++;
                }
            }
            else{
                if (f < s){
                    f = M * 2 - 2 - f;
                    if (f < s){
                        f = M * 2 - 2 - f;
                        v++;
                    }
                }
            }
        }
        else{
            f = M * 2 - 2 - f;
            s = M * 2 - 2 - s;
            if (t > s){
                f = M * 2 - 2 - f;
                s = M * 2 - 2 - s;
                v++;
                if (f < s) f = M * 2 - 2 - f;
            }
            else{
                if (f < s) f = M * 2 - 2 - f, v++;
            }
        }

        printf ("%d\n",v*(2*M-2)+f);
    }

    return 0;
}