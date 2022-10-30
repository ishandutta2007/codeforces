#include <stdio.h>

int X,T,A,B,DA,DB;
bool valid[999];

int main()
{
    int i;
    scanf("%d%d%d%d%d%d",&X,&T,&A,&B,&DA,&DB);
    for (i=0;i<T;i++){
        valid[A-DA*i] = 1;
    }
    valid[0] = 1;
    for (i=0;i<T;i++){
        if (X-(B-DB*i) >= 0 && valid[X-(B-DB*i)]){ puts("YES"); return 0; }
    }
    if (valid[X]){ puts("YES"); return 0; }
    puts("NO");
}