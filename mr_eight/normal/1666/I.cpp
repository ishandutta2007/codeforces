//Genshin Impact
//Paimon:There's a treasure chest!
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
#include<ctime>
#include<vector>
#include<set>
using namespace std;
bool get1(int x,int y)
{
    printf("DIG %d %d\n",x,y);
    fflush(stdout);
    int a;
    scanf("%d",&a);
    return a;
}
int get2(int x,int y)
{
    printf("SCAN %d %d\n",x,y);
    fflush(stdout);
    int a;
    scanf("%d",&a);
    return a;
}
int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
        int n,m,i,j;
        scanf("%d%d",&n,&m);
        int a=get2(1,1),b=get2(n,1),c=(n-1)*2+(m-1)*2-b;
    //    printf("## %d ##\n",c);
        int midx=(n-(b-a)/2+1)>>1;
        int midy=(m-(c-a)/2+1)>>1;
        int mid=get2(midx,midy);
        int val=get2(midx,1);
        int y_1=(val-mid)/2+1;
        int x_1=(a-val)/2+1;
        int x_2=(n-(b-a)/2+1)-x_1;
        int y_2=(m-(c-a)/2+1)-y_1;
        if (get1(x_1,y_1))
            get1(x_2,y_2);
        else
            get1(x_2,y_1),get1(x_1,y_2);
    }
}