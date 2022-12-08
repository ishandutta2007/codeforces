#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

stack<int> ST,SI;
vector<int> P;
char OR[10000],TEMP[10000];
int L,S,C;

int main()
{
    while (scanf ("%s",TEMP) == 1) strcat(OR,TEMP);
    L = strlen(OR);
    for (S=0;S<L;){
        if (OR[S+2] == 'a') ST.push(0), SI.push(C), C = 0, S += 7;
        else if (OR[S+2] == 'r') ST.push(1), S += 4;
        else if (OR[S+2] == 'd') ST.push(2), C++, S += 4;
        else if (OR[S+3] == 'a') P.push_back(C), C = SI.top(), SI.pop(), S += 8;
        else if (OR[S+3] == 'r') ST.pop(), S += 5;
        else if (OR[S+3] == 'd') ST.pop(), S += 5;
    }

    sort(P.begin(),P.end());
    int i; for (i=0;i<P.size();i++) printf ("%d ",P[i]);

    return 0;
}