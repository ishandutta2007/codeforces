#include <stdio.h>

typedef long long lld;

lld sx,sy,ex,ey,tx,ty,x[4],y[4],X[4],Y[4];

int main()
{
    int t,i,j;
    lld a,b,c,d,e,f,p,q;
    scanf("%lld%lld%lld%lld%lld%lld",&sx,&sy,&ex,&ey,&tx,&ty);
    if (sx == ex && sy == ey){ puts("YES"); return 0; }
    X[0] = ex-sx, Y[0] = ey-sy;
    X[1] = ex+sx, Y[1] = ey+sy;
    X[2] = ex-sy, Y[2] = ey+sx;
    X[3] = ex+sy, Y[3] = ey-sx;
    for (i=0;i<4;i++) if (!X[i] && !Y[i]){ puts("YES"); return 0; }
    if (!tx && !ty){ puts("NO"); return 0; }
    x[0] = tx, y[0] = ty;
    x[1] = -ty, y[1] = tx;
    x[2] = -tx, y[2] = -ty;
    x[3] = ty, y[3] = -tx;
    for (t=0;t<4;t++){
        for (i=0;i<4;i++){
            j = (i+1)%4;
            a = x[i], b = x[j], c = X[t];
            d = y[i], e = y[j], f = Y[t];
            if (!a){
                if (c%b != 0) continue;
                q = c/b;
                if ((f-e*q)%d != 0) continue;
                p = (f-e*q)/d;
                if (p < 0 || q < 0) continue;
                puts("YES");
                return 0;
            }
            if (!b){
                if (c%a != 0) continue;
                p = c/a;
                if ((f-d*p)%e != 0) continue;
                q = (f-d*p)/e;
                if (p < 0 || q < 0) continue;
                puts("YES");
                return 0;
            }
            if (b*d != a*e){
                if ((c*d-a*f)%(b*d-a*e) != 0) continue;
                q = (c*d-a*f)/(b*d-a*e);
                if ((c-b*q)%a != 0) continue;
                p = (c-b*q)/a;
                if (p < 0 || q < 0) continue;
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
}