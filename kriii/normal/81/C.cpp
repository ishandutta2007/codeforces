#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

struct NUM{
    NUM(int c_, int i_){c = c_; i = i_;}
    int c,i;
};
bool cmp1(const NUM& a, const NUM& b){return a.c == b.c ? a.i < b.i : a.c < b.c;}
bool cmp2(const NUM& a, const NUM& b){return a.c == b.c ? a.i > b.i : a.c < b.c;}

vector<NUM> V;

int N,A,B,C[101001];
int P[101010];

int main()
{
    int i;

    scanf ("%d %d %d",&N,&A,&B);
    for (i=0;i<N;i++) scanf ("%d",&C[i]), V.push_back(NUM(C[i],i));

    if (A == B){
        for (i=0;i<A;i++) P[i] = 1;
        for (i=A;i<N;i++) P[i] = 2;
    }
    else if (A > B){
        sort(V.begin(),V.end(),cmp1);
        for (i=0;i<A;i++) P[V[i].i] = 1;
        for (i=A;i<N;i++) P[V[i].i] = 2;
    }
    else{
        sort(V.begin(),V.end(),cmp2);
        for (i=0;i<B;i++) P[V[i].i] = 2;
        for (i=B;i<N;i++) P[V[i].i] = 1;
    }

    for (i=0;i<N;i++) printf ("%d ",P[i]);

    return 0;
}