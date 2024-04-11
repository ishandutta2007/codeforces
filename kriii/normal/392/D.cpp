#include <stdio.h>
#include <functional>
#include <map>
#include <set>
using namespace std;

map<int, int> chain,A,F,B,C;
set<int, greater<int> > L;
multiset<int> mn;

void push(int x, int y)
{
    map<int, int>::iterator I,J;
    if (chain.count(x)){
        I = chain.find(x);
    }
    else{
        I = chain.lower_bound(x);
    }

    int ly = I->second;
    if (ly >= y) return;
    J = I; J--;
    while (J->second <= y){
        mn.erase(mn.find(J->first+ly));
        ly = J->second;
        chain.erase(J); J = I; J--;
    }
    mn.erase(mn.find(J->first+ly));
    mn.insert(J->first+y);
    if (!chain.count(x)){
        chain[x] = y;
        mn.insert(x+I->second);
    }
    else I->second = y;
}

int main()
{
    chain[0] = 0x0fffffff; chain[0x0fffffff] = 0; mn.insert(0);

    int N; scanf ("%d",&N);
    for (int i=1,x;i<=N;i++){
        scanf ("%d",&x); L.insert(x);
        if (!A.count(x)) A[x] = i, F[-i] = x;
    }
    for (int i=1,x;i<=N;i++){
        scanf ("%d",&x); L.insert(x);
        if (!B.count(x)) B[x] = i;
    }
    for (int i=1,x;i<=N;i++){
        scanf ("%d",&x); L.insert(x);
        if (!C.count(x)) C[x] = i;
    }
    
    for (auto p : L){
        if (!A.count(p)){
            int x = B.count(p) ? B[p] : 0x0ffffffe;
            int y = C.count(p) ? C[p] : 0x0ffffffe;
            push(x,y);
        }
    }

    int ans = 3 * N;
    for (auto u : F){
        int p = u.second;
        if (A.count(p)){
            if (ans > *mn.begin() + A[p])
                ans = *mn.begin() + A[p];
            int x = B.count(p) ? B[p] : 0x0ffffffe;
            int y = C.count(p) ? C[p] : 0x0ffffffe;
            push(x,y);
        }
    }
    if (ans > *mn.begin())
        ans = *mn.begin();

    printf ("%d\n",ans);

    return 0;
}