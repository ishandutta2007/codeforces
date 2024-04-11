#include<bits/stdc++.h>
using namespace std;
long long int n,m,i,j,l,p;
char s[1000010];
long long int hard[6][300000];
long long int a[300000];
int main(){
cin>>n;
scanf("%s",&s);
for(i=0;i<n;i++)
{
cin>>a[i];
}
for(i=0;i<n;i++)
{
if(s[i]=='h')
{
hard[1][i+1]=hard[1][i]+a[i];
}
else
{
hard[1][i+1]=hard[1][i];
}
if(s[i]=='a')
{
hard[2][i+1]=min(hard[2][i]+a[i],hard[1][i+1]);
}
else hard[2][i+1]=hard[2][i];
if(s[i]=='r')
{
hard[3][i+1]=min(hard[3][i]+a[i],hard[2][i+1]);
}
else hard[3][i+1]=hard[3][i];
if(s[i]=='d')
{
hard[4][i+1]=min(hard[4][i]+a[i],hard[3][i+1]);
}
else hard[4][i+1]=hard[4][i];
}
cout<<hard[4][n];
}