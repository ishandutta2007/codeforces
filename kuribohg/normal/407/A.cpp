#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int a,b,c1,c2,c3,c4,p,q,r,s;
int main()
{
    scanf("%d%d",&a,&b);
    for(int i=1;i<a;i++)
            for(int k=1;k<b;k++)
                {
                    int j=(int)(sqrt(a*a-i*i)+0.5);
                    int l=(int)(sqrt(b*b-k*k)+0.5);
                    if(i*i+j*j==a*a&&k*k+l*l==b*b)
                    {
                        p=i,q=j;
                        r=-k,s=l;
                        if(p*r+q*s==0&&p!=r&&q!=s) c1=p,c2=q,c3=r,c4=s;
                        r=-r,s=-s;
                        if(p*r+q*s==0&&p!=r&&q!=s) c1=p,c2=q,c3=r,c4=s;
                        swap(r,s);
                        if(p*r+q*s==0&&p!=r&&q!=s) c1=p,c2=q,c3=r,c4=s;
                        r=-r,s=-s;
                        if(p*r+q*s==0&&p!=r&&q!=s) c1=p,c2=q,c3=r,c4=s;
                    }
                }
    if(!c1) puts("NO");
    else
    {
        puts("YES");
        puts("0 0");
        printf("%d %d\n",c1,c2);
        printf("%d %d\n",c3,c4);
    }
    return 0;
}