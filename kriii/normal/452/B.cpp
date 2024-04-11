#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int> > U;

double dist(pair<int, int> a, pair<int, int> b){return hypot(a.first-b.first,a.second-b.second);}

int main()
{
    int N,M;

    scanf ("%d %d",&N,&M);
    for (int i=0;i<4;i++){
        int x = (i % 2) * N, y = (i / 2) * M;
        for (int dx=-2;dx<=2;dx++) for (int dy=-2;dy<=2;dy++){
            int px = x + dx;
            int py = y + dy;
            if (px >= 0 && px <= N && py >= 0 && py <= M){
                U.push_back(make_pair(px,py));
            }
        }
    }

    sort(U.begin(),U.end());
    U.erase(unique(U.begin(),U.end()),U.end());
    double ans = 0; int p[4];
    for (int i=0;i<U.size();i++) for (int j=0;j<U.size();j++) if (i != j){
        for (int k=0;k<U.size();k++) if (i != k && j != k){
            for (int l=0;l<U.size();l++) if (i != l && j != l && k != l){
                double s = dist(U[i],U[j]) + dist(U[k],U[j]) + dist(U[k],U[l]);
                if (ans < s){
                    ans = s;
                    p[0] = i; p[1] = j; p[2] = k; p[3] = l; 
                }
            }
        }
    }

    for (int i=0;i<4;i++) printf ("%d %d\n",U[p[i]].first,U[p[i]].second);

    return 0;
}