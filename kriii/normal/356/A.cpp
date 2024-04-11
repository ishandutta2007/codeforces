#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

vector<pair<int, int> > U[300001];
multiset<int> S;

int N,M,X[300001],P[300001];

void in(int l, int r, int i)
{
    r++;
    if (l >= r) return;
    
    U[l].push_back(make_pair(1,i));
    U[r].push_back(make_pair(-1,i));
}

int main()
{
    int i,j,l,r,x;

    scanf ("%d %d",&N,&M);
    for (i=0;i<M;i++){
        scanf ("%d %d %d",&l,&r,&x); X[i] = x;
        in(l,x-1,i);
        in(x+1,r,i);
    }

    for (i=1;i<=N;i++){
        for (j=0;j<U[i].size();j++){
            if (U[i][j].first == 1) S.insert(U[i][j].second);
            else S.erase(S.find(U[i][j].second));
        }

        if (!S.empty()) P[i] = X[*S.begin()];
    }

    for (i=1;i<=N;i++) printf ("%d ",P[i]);

    return 0;
}