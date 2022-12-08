#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

map<int, int> R;
map<int, int>::iterator I;
priority_queue<pair<int, int> > Q;
pair<int, int> P[3];
vector<int> A[3];
int N;

int main()
{
    int i,r;

    scanf ("%d",&N);
    for (i=0;i<N;i++){
        scanf ("%d",&r); R[r]++;
    }
    for (I=R.begin();I!=R.end();I++) Q.push(make_pair(I->second,I->first));

    while (Q.size() >= 3){
        for (i=0;i<3;i++){
            P[i] = Q.top(); Q.pop();
            P[i].first--; A[i].push_back(P[i].second);
        }

        for (i=0;i<3;i++){
            if (P[i].first) Q.push(P[i]);
        }
    }

    printf ("%d\n",A[0].size());
    for (i=0;i<A[0].size();i++){
        if (A[0][i] < A[1][i]) swap(A[0][i],A[1][i]);
        if (A[0][i] < A[2][i]) swap(A[0][i],A[2][i]);
        if (A[1][i] < A[2][i]) swap(A[1][i],A[2][i]);
        printf ("%d %d %d\n",A[0][i],A[1][i],A[2][i]);
    }

    return 0;
}