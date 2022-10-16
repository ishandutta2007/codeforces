#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int home[100005];
int x[100005];
int y[100005];

int main()
{
    int total;
    scanf("%d",&total);
    
    for (int i = 0; i < total; i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        home[x[i]]++;
    }
    
    int amount = 2*total - 2;
    for (int i = 0; i < total; i++)
    {
        int r = total - 1 + home[y[i]];
        printf("%d %d\n",r,amount - r);
    }
    //system("pause");
}