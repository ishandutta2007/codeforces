#include <stdio.h>
#include <functional>
#include <algorithm>
#include <set>
using namespace std;

multiset<int> in;
multiset<int, greater<int> > out;

int N,K,A[202];

int main()
{
    scanf ("%d %d",&N,&K);
    for (int i=0;i<N;i++) scanf ("%d",&A[i]);

    int ans = 0x80000000;
    for (int i=0;i<N;i++){
        in.clear(); out.clear();
        for (int j=0;j<N;j++) out.insert(A[j]);
        int s = 0;
        for (int j=i;j<N;j++){
            in.insert(A[j]); s += A[j];
            out.erase(out.find(A[j]));
            int f = min(K,(int)min(in.size(),out.size()));

            if (ans < s)
                ans = s;
            multiset<int>::iterator I = in.begin();
            multiset<int, greater<int> >::iterator J = out.begin();

            int t = s;
            while (f--){
                t -= *I;
                t += *J;
                if (ans < t)
                    ans = t;
                I++; J++;
            }
        }
    }

    printf ("%d\n",ans);

    return 0;
}