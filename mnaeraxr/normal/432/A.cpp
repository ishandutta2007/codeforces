#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int times[2005];

int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    for (int i = 0; i < N; i++)
    {
        scanf("%d",&times[i]);
    }
    sort(times,times + N);
    int counter = 0;
    for (int i = 2; i < N; i+= 3)
    {
        if (times[i] + K <= 5)
        {
            counter++;
        }
    }
    printf("%d\n",counter);
    //system("pause");
}