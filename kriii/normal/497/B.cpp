#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,A[100001],B[100001];

int main()
{
    scanf ("%d",&N);
    for (int i=1;i<=N;i++){
        A[i] = A[i-1];
        B[i] = B[i-1];
        int x; scanf ("%d",&x);
        if (x == 1) A[i]++;
        else B[i]++;
    }

    vector<pair<int, int> > u;
    for (int t=N;t>=1;t--){
        int wa = 0, wb = 0, l;
        for (int i=1;i<=N;i++){
            int a = lower_bound(A+i,A+N+1,A[i-1]+t) - A;
            int b = lower_bound(B+i,B+N+1,B[i-1]+t) - B;
            if (a < b) i = a, wa++, l = 1;
            else i = b, wb++, l = 2;
            if (i == N + 1){
                wa = wb = -1; break;
            }
        }

        if (wa != wb){
            if (wa < wb && l == 1) continue;
            if (wa > wb && l == 2) continue;
            u.push_back(make_pair(max(wa,wb),t));
        }
    }

    printf ("%u\n",u.size());
    sort(u.begin(),u.end());
    for (auto p : u) printf ("%d %d\n",p.first,p.second);

    return 0;
}