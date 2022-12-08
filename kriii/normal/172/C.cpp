#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

struct stu{int i,x,t;}S[100001];
bool cmp(const stu& a, const stu& b){return a.t < b.t;}
map<int,vector<int> > put;
map<int,vector<int> >::iterator I;
int N,M; long long T,t,ANS[100001];

int main()
{
    int i,j;

    scanf ("%d %d",&N,&M);
    for (i=0;i<N;i++){
        S[i].i = i;
        scanf ("%d %d",&S[i].t,&S[i].x);
    }
    sort(S,S+N,cmp);

    for (i=0;i<N;i+=M){
        put.clear();
        for (j=i;j<N&&j<i+M;j++){
            t = S[j].t;
            put[S[j].x].push_back(S[j].i);
        }
        T = max(T,t);

        t = 0;
        for (I=put.begin();I!=put.end();I++){
            T += I->first - t;
            t = I->first;
            vector<int>& a = I->second;
            for (j=0;j<a.size();j++){
                ANS[a[j]] = T;
            }
            T += 1 + (a.size() / 2);
        }
        T += t;
    }

    for (i=0;i<N;i++) printf ("%I64d ",ANS[i]);

    return 0;
}