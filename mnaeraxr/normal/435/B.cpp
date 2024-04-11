// MOGContest.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <complex>
#include <algorithm>


char r_number[21];
int number[21];

int fix(int pos, int ch, int total)
{
    int max = -1;
    int max_pos = -1;
    for (int i = pos; i < ch + pos + 1 && i < total;  i++)
    {
        if (number[i] > max)
        {
            max = number[i];
            max_pos = i;
        }
    }
    for (int i = max_pos; i > pos; i--)
    {
        number[i] = number[i - 1];
    }
    number[pos] = max;
    return ch - (max_pos - pos);
}

int main()
{
    int ch;
    scanf("%s%d",&r_number,&ch);
    int len = strlen(r_number);

    for (int i = 0; i <len; i++)
        number[i] = (int)(r_number[i] - '0');


    for (int i = 0; i < len && ch > 0; ++i)
        ch = fix(i,ch,len);

    for (int i = 0; i < len; ++i)
        printf("%d",number[i]);
    printf("\n");
    //system("pause");
}