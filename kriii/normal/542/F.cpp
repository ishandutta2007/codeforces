#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> G[101];

int main()
{
    int N,T;

    scanf ("%d %d",&N,&T);
    while (N--){
        int t,q; scanf ("%d %d",&t,&q);
        G[t].push_back(q);
    }
    for (int i=1;i<T;i++){
        sort(G[i].rbegin(),G[i].rend());
        if (G[i].size() % 2) G[i].push_back(0);
        for (int j=0;j<G[i].size();j+=2) G[i+1].push_back(G[i][j]+G[i][j+1]);
    }
    sort(G[T].rbegin(),G[T].rend());
    printf ("%d\n",G[T][0]);

    return 0;
}