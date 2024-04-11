// author       : MarX
// copyright    : UH

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

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()using namespace std;
#define DB(x) cerr << __LINE__ << ": " << #x << " = " << x << endl;

char A[110];

int l[4];


int main()
{   
    char *letter = "ABCD";
    int max = 0;
    int min = 1000000;
    int pmax = -1;
    int pmin = -1;
    for (int i = 0; i < 4; ++i)
    {
        scanf("%s",&A);
        l[i] = strlen(A) - 2;   
        if (l[i] < min)
        {
            min  = l[i];
            pmin = i;
        }   
        if (l[i] > max)
        {
            max = l[i];
            pmax = i;
        }

    }
    sort(l, l + 4);
    if (l[3] >= 2*l[2])
    {
        if (2*l[0] <= l[1])
            printf("C\n");
        else
            printf("%c\n",letter[pmax]);
    }
    else
    {
        if (2*l[0] <= l[1])
            printf("%c\n",letter[pmin]);
        else
            printf("C\n");      
    }

    return 0;
}