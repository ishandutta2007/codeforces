#include<bits/stdc++.h>
using namespace std;
int n;
int tot;
void print(int x,int y)
{
    printf("%c%c ",x+'a'-1,y+'0');
    tot++;
}
int main()
{
    scanf("%d",&n);
    if(n<=50)
    {
        n--;
        bool yes=1;
        int nx,ny;
        for(int i=1;i<=7;++i)
        {
            for(int j=1;j<=7;++j)
            {
                if(i&1)print(i,j),nx=i,ny=j;
                else print(i,8-j),nx=i,ny=8-j;
                n--;
                if(n==0)break;
            }
            if(n==0)break;
        }
        if(n==0)print(8,ny),print(8,8);
    }
    else if(n<=56)
    {
        for(int i=1;i<=7;++i)
        {
            for(int j=1;j<=7;++j)
            {
                if(i&1)print(i,j);
                else print(i,8-j);
            }
        }
        print(8,7);
        if(n>=51)print(8,6);
        if(n>=52)print(8,5);
        if(n>=53)print(8,4);
        if(n>=54)print(8,3);
        if(n>=55)print(8,2);
        if(n>=56)print(8,1);
        print(8,8);
    }
    else
    {
        for(int i=1;i<=6;++i)
        {
            for(int j=1;j<=8;++j)
            {
                if(i&1)print(i,j);
                else print(i,9-j);
            }
        }
        for(int j=1;j<=6;++j)print(7,j);
        print(7,8);print(7,7);
        print(8,7);
        if(n>=58)print(8,6);
        if(n>=59)print(8,5);
        if(n>=60)print(8,4);
        if(n>=61)print(8,3);
        if(n>=62)print(8,2);
        if(n>=63)print(8,1);
        print(8,8);
    }
}