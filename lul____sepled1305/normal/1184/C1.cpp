#include<stdio.h>
#include<utility>
#define pii pair<int,int>
#include<vector>
using namespace std;
int X[55],Y[55];
main()
{
    int n;
    scanf("%d",&n);
    pii A[4*n+15];
    int xtemp,ytemp,xmax=0,ymax=0;
    for(int i=0;i<4*n+1;i++)
    {
        scanf("%d %d",&xtemp,&ytemp);
        X[xtemp]++;
        Y[ytemp]++;
        if(xtemp > xmax)
            xmax = xtemp;
        if(ytemp > ymax)
            ymax = ytemp;
        A[i] = make_pair(xtemp,ytemp);
    }
    int xleft,ytop,xright,ybot;
    for(int i=0;i<=xmax;i++)
    {
        if(X[i] >= 2)
        {
            xleft = i;
            break;
        }
    }
    for(int i=0;i<=ymax;i++)
    {
        if(Y[i] >= 2)
        {
            ytop = i;
            break;
        }
    }
    for(int i=xmax;i>=0;i--)
    {
        if(X[i] >= 2)
        {
            xright = i;
            break;
        }
    }
    for(int i=ymax;i>=0;i--)
    {
        if(Y[i] >= 2)
        {
            ybot = i;
            break;
        }
    }
    //printf("%d %d %d %d",xleft,xright,ytop,ybot);
    for(int i=0;i<4*n+1;i++)
    {
        xtemp = A[i].first;
        ytemp = A[i].second;
        if(xleft !=xtemp && xright != xtemp && ytemp !=ytop && ytemp !=ybot)
        {
            printf("%d %d",xtemp,ytemp);
            return 0;
        }
        else if((xleft == xtemp||xright == xtemp) && (ytemp <ytop || ytemp > ybot))
        {
            printf("%d %d",xtemp,ytemp);
            return 0;
        }
        else if((ytop == ytemp||ybot == ytemp) && (xtemp < xleft || xtemp > xright))
        {
            printf("%d %d",xtemp,ytemp);
            return 0;
        }
    }
}