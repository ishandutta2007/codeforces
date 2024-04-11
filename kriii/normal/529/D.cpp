#include <stdio.h>
#include <map>
using namespace std;

multimap<int, int> chk;
int N,M,T,R,A[20002];

int main()
{
    scanf ("%d %d %d",&N,&M,&T);
    bool good = 0;
    for (int i=0;i<N;i++){
        int h,m,s;
        scanf ("%d:%d:%d",&h,&m,&s);
        int p = h * 3600 + m * 60 + s;

        while (!chk.empty() && chk.begin()->first + T <= p) chk.erase(chk.begin());
        if (chk.size() == M){
            int last = chk.end().operator--()->second;
            chk.erase(chk.end().operator--());
            A[i] = last;
            chk.insert(make_pair(p,last));
        }
        else{
            A[i] = ++R;
            chk.insert(make_pair(p,R));
        }

        if (chk.size() == M) good = 1;
    }

    if (good){
        printf ("%d\n",R);
        for (int i=0;i<N;i++) printf ("%d\n",A[i]);
    }
    else puts("No solution");

    return 0;
}