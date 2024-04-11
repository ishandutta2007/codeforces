#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int main(){
  //  freopen("input.txt","rt",stdin);
  //  freopen("output.txt","wt",stdout);
    int a1,a2,a3,a4;
    cin>>a1>>a2>>a3>>a4;
    if ((a1<a2?a1:a2)<(a3>a4?a3:a4))
    {
        cout<<-1;
        return 0;
    }
    if (a4==a3+1)
    {

        {
            printf("74");
            
            for (int i=0;i<a1-a4;i++)
                printf("4");
            for (int i=0;i<a4-2;i++)
                printf("74");
            for (int i=0;i<a2-a4+1;i++)
                printf("7");
            printf("4");
            return 0;
        }
    }
    else if (a3==a4)
    {
        if (a3>a1 || a3>a2 || (a3==a1 && a3==a2))
        {
            cout<<-1;
            return 0;
        }
        for (int i=0;i<a1-a3;i++)
            printf("4");
        for (int i=0;i<a3-1;i++)
            printf("74");
        if (a1>a3)
            for (int i=0;i<a2-a3+1;i++)
                printf("7");
        else
            printf("7");
        printf("4");
        if (a1<=a3)
            for (int i=0;i<a2-a3;i++)
                printf("7");
        return 0;
    }
    else if (a4==a3-1)
    {
        {
            for (int i=0;i<a1-a3;i++)
                printf("4");
            for (int i=0;i<a3;i++)
                printf("47");
            for (int i=0;i<a2-a3;i++)
                printf("7");
            return 0;
        }
    }
    cout<<-1;
    return 0;
}