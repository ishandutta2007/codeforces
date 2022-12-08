#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;

vector<pair<int, int> > ans;
stack<int> S;

int D[1<<16],X[1<<16];

int main()
{
    int N; scanf ("%d",&N);
    for (int i=0;i<N;i++){
        scanf ("%d %d",&D[i],&X[i]);
        if (D[i] == 1) S.push(i);
    }

    while (!S.empty()){
        int x = S.top(); S.pop();
        if (D[x] == 0) continue;
        X[X[x]] ^= x;
        --D[x];
        ans.push_back(make_pair(x,X[x]));
        if (--D[X[x]] == 1){
            S.push(X[x]);
        }
    }

    printf ("%u\n",ans.size());
    for (auto p : ans) printf ("%d %d\n",p.first,p.second);
    return 0;
}