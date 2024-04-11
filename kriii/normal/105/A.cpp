#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

int N,M,C; char S[100];
map<string, int> CHK;
map<string, int>::iterator I;

int main()
{
    int i,x;
    scanf("%d %d 0.%d",&N,&M,&C);

    for (i=0;i<N;i++){
        scanf ("%s %d",S,&x); x = x * C / 100;
        if (x >= 100) CHK[S] = x;
    }

    for (i=0;i<M;i++){
        scanf ("%s",S);
        CHK[S] += 0;
    }

    cout << CHK.size() << endl;
    for (I=CHK.begin();I!=CHK.end();I++) cout << I->first << " " << I->second << endl;

    return 0;
}