#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
char a[100][100];
int A=100,B=100;
int main()
{
    for(int i=1;i<=8;i++)
        scanf("%s",a[i]+1);
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            if(a[i][j]=='W')
            {
                bool ok=true;
                for(int k=1;k<i;k++)
                    if(a[k][j]!='.') ok=false;
                if(ok) A=min(A,i-1);
            }
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
            if(a[i][j]=='B')
            {
                bool ok=true;
                for(int k=i+1;k<=8;k++)
                    if(a[k][j]!='.') ok=false;
                if(ok) B=min(B,8-i);
            }
    if(A<=B) puts("A");
    else puts("B");
    return 0;
}