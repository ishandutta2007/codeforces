#include<bits/stdc++.h>
using namespace std;
char a[1001][1001];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k=0;
        for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
        cin>>a[x][y],k+=(a[x][y]!='.');
        int num1=0;
        for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
        {
            if((x+y)%3==0&&a[x][y]=='X')num1++;
            if((x+y)%3==1&&a[x][y]=='O')num1++;
        }
        if(num1<=k/3){
            for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++)
            {
                if((x+y)%3==0&&a[x][y]=='X')cout<<'O';
                else if((x+y)%3==1&&a[x][y]=='O')cout<<'X';
                else cout<<a[x][y];
            }cout<<endl;}
            continue;
        }
        int num2=0;
        for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
        {
            if((x+y)%3==1&&a[x][y]=='X')num2++;
            if((x+y)%3==2&&a[x][y]=='O')num2++;
        }
        if(num2<=k/3){
            for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++)
            {
                if((x+y)%3==1&&a[x][y]=='X')cout<<'O';
                else if((x+y)%3==2&&a[x][y]=='O')cout<<'X';
                else cout<<a[x][y];
            }cout<<endl;}
            continue;
        }
        int num3=0;
        for(int x=1;x<=n;x++)
        for(int y=1;y<=n;y++)
        {
            if((x+y)%3==2&&a[x][y]=='X')num3++;
            if((x+y)%3==0&&a[x][y]=='O')num3++;
        }
        if(num3<=k/3){
            for(int x=1;x<=n;x++){
            for(int y=1;y<=n;y++)
            {
                if((x+y)%3==2&&a[x][y]=='X')cout<<'O';
                else if((x+y)%3==0&&a[x][y]=='O')cout<<'X';
                else cout<<a[x][y];
            }cout<<endl;}
            continue;
        }
    }
}