#include <iostream>

using namespace std;

int main()
{
int n;
cin>>n;
char A[101][101]={0};
for (int i = 0; i < n; i++)
scanf("%s",A[i]);
bool ok = 1;
int dx[]={0,1,1,1,2};
int dy[]={0,-1,0,1,0};
for (int i = 0;i<n-2;i++)
for (int j = 1;j<n-1;j++)
if (A[i][j] == '#')
{
for (int k = 0; k < 5; k++)
{
int nx = i + dx[k];
int ny = j + dy[k];
if (A[nx][ny] != '#')
ok = 0;
else
A[nx][ny] = '.';
}
}
for (int i = 0;i < n; i++)
for (int j = 0;j<n;j++)
if (A[i][j] == '#') ok = 0;
puts(ok?"YES":"NO");
return 0;
}