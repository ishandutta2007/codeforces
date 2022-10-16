// C.cpp : Defines the entry point for the console application.
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

using namespace std;

struct Pos
{
    bool mode;
    int level;
    int pos;

public:
    Pos()
    {
        mode = true;
        level = 0;
        pos = 0;
    }
    
    bool operator<(const Pos other) const
    {
        if (level == other.level)
            return pos < other.pos;
        return level > other.level;
    }
};

Pos myList[1000005];

int main()
{
    int total;
    scanf("%d",&total);
    int v;

    int curLevel = 0;
    bool mode = true;
    int position = 0;

    int sum = 0;
    for (int i = 0; i < total; i++)
    {
        scanf("%d",&v);
        sum += v;

        for (int j = 0; j < v; ++j)
        {
            myList[position].pos = position;
            myList[position].mode = mode;
            myList[position].level = curLevel;
            position++;
            if (mode)
                curLevel++;
            else
                curLevel--;
        }
        if (mode)
            curLevel--;
        else
            curLevel++;
        mode = !mode;
    }

    sort(myList,myList + sum);
    int cur_pos = 0;
    int cur_level = myList[0].level;

    for (int i = 0; i < sum; i++)
    {
        Pos t = myList[i];
        if (t.level < cur_level)
        {
            for (int j = 0; j < sum - cur_pos; ++j)
                printf(" ");
            printf("\n");
            cur_level = t.level;
            cur_pos = 0;
        }

        for (int j = 0; j < t.pos - cur_pos; ++j)
            printf(" ");
        if (t.mode)
            printf("/");
        else
            printf("\\");
        cur_pos = t.pos + 1;
    }
            for (int j = 0; j < sum - cur_pos; ++j)
                printf(" ");
    printf("\n");
    //system("pause");
}