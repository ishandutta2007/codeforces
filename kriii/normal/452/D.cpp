#include <stdio.h>
#include <deque>
using namespace std;

int k,n[3],t[3],time[10001],ans,w[4];
deque<int> q[3];

void resolve()
{
    int min = 0x7fffffff;
    for (int i=0;i<3;i++){
        if (!q[i].empty() && min > q[i][0]) min = q[i][0];
    }
    if (min != 0x7fffffff){
        for (int i=0;i<3;i++){
            while (!q[i].empty() && min == q[i][0]){
                w[i+1]++; q[i].pop_front();
            }
        }
        ans = min;
    }
    for (int i=0;i<3;i++){
        while (w[i] && q[i].size() < n[i]){
            q[i].push_back(ans+t[i]); w[i]--;
        }
    }
}

int main()
{
    scanf ("%d",&k);
    for (int i=0;i<3;i++) scanf ("%d",&n[i]);
    for (int i=0;i<3;i++) scanf ("%d",&t[i]);

    for (int i=0;i<k;i++) w[0]++;
    for (int i=0;i<5*k;i++) resolve();
    printf ("%d\n",ans);

    return 0;
}