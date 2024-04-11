#include <stdio.h>

int A,B,M,VX,VY,VZ;
double X,Y,Z;

int main()
{
    int i,j,k;
    double xt,yt,zt,t;
    scanf("%d%d%d",&A,&B,&M);
    scanf("%d%d%d",&VX,&VY,&VZ);
    X = A/2., Y = M;
    while (Y>1e-7){
        if (VX > 0) xt = (A-X)/VX;
        else xt = X/-VX;
        yt = -Y/VY;
        if (VZ > 0) zt = (B-Z)/VZ;
        else zt = -Z/VZ;
        t = 1e9;
        if (t > xt) t = xt, k = 1;
        if (t > yt) t = yt, k = 2;
        if (t > zt) t = zt, k = 3;
        X += t*VX;
        Y += t*VY;
        Z += t*VZ;
        if (k == 1){
            VX *= -1;
        }else if (k == 2){
            VY *= -1;
        }else{
            VZ *= -1;
        }
    }
    printf("%.9lf %.9lf",X,Z);
}