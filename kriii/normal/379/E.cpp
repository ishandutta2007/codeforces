#include <stdio.h>

int N,K,Y[303][303],S,NS,F;
double px[310],py[310],area;
double nx[310],ny[310];
double vx,vy,ux,uy;
double ans[903];

double abs(double a){
    return a < 0 ? -a : a;
}

bool equ(double a, double b){
    return abs(a-b) < 1e-9;
}

void add(double x, double y)
{
    if (NS > 0){
        if (equ(nx[NS-1],x) && equ(ny[NS-1],y)) return;
    }
    nx[NS] = x;
    ny[NS] = y;
    NS++;
}

int main()
{
    int i,j,k;
    int st,ed;

    scanf ("%d %d",&N,&K);
    for (i=0;i<N;i++) for (j=0;j<=K;j++) scanf ("%d",&Y[i][j]);

    for (j=0;j<K;j++){
        S = 4;
        px[0] = 0; py[0] = 1010;
        px[1] = 0; py[1] = 0;
        px[2] = 1; py[2] = 0;
        px[3] = 1; py[3] = 1010;

        for (i=0;i<N;i++){
            double a = Y[i][j] - Y[i][j+1];
            double b = 1;
            double c = Y[i][j];

            area = 0; F = 0; NS = 0; st = S+1; ed = -1;
            for (k=1;k<S;k++){
                double dx = px[k] - px[k-1];
                double dy = py[k] - py[k-1];
                double p = c - a * px[k-1] - b * py[k-1];
                double q = a * dx + b * dy;
                if (-1e-9 < q && q < 1e-9){
                    if (F == 1) area += px[k-1] * py[k] - py[k-1] * px[k];
                }
                else{
                    double t = p / q;
                    if (1e-9 <= t && t <= 1 + 1e-9){
                        if (st > k){
                            st = k;
                            vx = px[k-1] + dx * t;
                            vy = py[k-1] + dy * t;
                        }
                        if (ed < k){
                            ed = k;
                            ux = px[k-1] + dx * t;
                            uy = py[k-1] + dy * t;
                        }
                    }
                }
            }
            if (ed >= 0){
                for (k=0;k<st;k++) add(px[k],py[k]);
                add(vx,vy);
                if (st < ed){
                    area += ux * vy - uy * vx;
                    area += vx * py[st] - vy * px[st];
                    for (k=st+1;k<ed;k++) area += px[k-1] * py[k] - py[k-1] * px[k];
                    area += px[ed-1] * uy - py[ed-1] * ux;
                }
                add(ux,uy);
                for (k=ed;k<S;k++) add(px[k],py[k]);

                for (k=0;k<NS;k++){
                    px[k] = nx[k];
                    py[k] = ny[k];
                }
                S = NS;
            }

            ans[i] += area / 2;
        }
    }

    for (i=0;i<N;i++) printf ("%.9lf\n",ans[i]);

    return 0;
}