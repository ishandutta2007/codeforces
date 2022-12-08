#include <stdio.h>
#include <queue>
using namespace std;

priority_queue<pair<int, int> > Q;

int N,K,C;

int main()
{
    freopen ("input.txt","r",stdin);
    freopen ("output.txt","w",stdout);
    int i,x;

    scanf ("%d %d",&N,&K);
    for (i=0;i<N;i++){
        scanf ("%d",&x);
        Q.push(make_pair(-x,0));
    }

    while (!Q.empty()){
        pair<int, int> W = Q.top(); Q.pop();
        if (W.second == 3){C -= W.first; continue;}
        if (W.first > -K) C -= W.first;
        else{
            Q.push(make_pair(W.first+K,W.second+1));
        }
    }

    printf ("%d\n",C);

    return 0;
}