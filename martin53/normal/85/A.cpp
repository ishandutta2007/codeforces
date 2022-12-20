#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
int n;
char output[4][nmax];
bool seen[26];
void add(int x,int y)
{
    if(0>x||x>3)return;
    if(0>y||y>n)return;
    if(output[x][y]==0)return;
    seen[output[x][y]-'a']=1;
}
char get_colour(int x1,int y1,int x2,int y2)
{
memset(seen,0,sizeof(seen));
add(x1-1,y1);
add(x1+1,y1);
add(x1,y1+1);
add(x1,y1-1);

add(x2-1,y2);
add(x2+1,y2);
add(x2,y2+1);
add(x2,y2-1);

int p=0;
while(seen[p])p++;
return p+'a';
}
int main()
{
scanf("%i",&n);

if(n==1)
{
    printf("a\na\nb\nb\n");
    return 0;
}

if(n==2)
{
    printf("aa\nbb\ncc\ndd\n");
    return 0;
}

if(n%2==0)
{
    for(int j=1;j<=n;j=j+2)
        output[0][j]=output[0][j+1]=get_colour(0,j,0,j+1);
    output[1][1]=output[2][1]=get_colour(1,1,2,1);

    for(int j=2;j<n;j=j+2)
        output[1][j]=output[1][j+1]=get_colour(1,j,1,j+1);
    output[1][n]=output[2][n]=get_colour(1,n,2,n);

    for(int j=2;j<n;j=j+2)
        output[2][j]=output[2][j+1]=get_colour(2,j,2,j+1);

    for(int j=1;j<=n;j=j+2)
        output[3][j]=output[3][j+1]=get_colour(3,j,3,j+1);
}
else
{
    for(int j=1;j<n;j=j+2)
        output[0][j]=output[0][j+1]=get_colour(0,j,0,j+1);
    output[0][n]=output[1][n]=get_colour(0,n,1,n);
    for(int j=1;j<n;j=j+2)
        output[1][j]=output[1][j+1]=get_colour(1,j,1,j+1);


    for(int j=2;j<n;j=j+2)
        output[2][j]=output[2][j+1]=get_colour(2,j,2,j+1);
    output[2][1]=output[3][1]=get_colour(2,1,3,1);
    for(int j=2;j<n;j=j+2)
        output[3][j]=output[3][j+1]=get_colour(3,j,3,j+1);
}

for(int i=0;i<4;i++)
{
    for(int j=1;j<=n;j++)printf("%c",output[i][j]);
    printf("\n");
}
return 0;
}