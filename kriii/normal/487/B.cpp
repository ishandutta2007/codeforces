#include <stdio.h>
#include <queue>
using namespace std;

const int non = 1000000;
priority_queue<pair<int, int> > mn,mx,dn;
int N,S,L,D[100001];

int main()
{
    scanf ("%d %d %d",&N,&S,&L);
    for (int j=1,i=1,x;i<=N;i++){
        scanf ("%d",&x);
        mn.push(make_pair(-x,i));
        mx.push(make_pair(x,i));

        while (1){
            while (mx.top().second < j) mx.pop();
            while (mn.top().second < j) mn.pop();
            if (mx.top().first + mn.top().first > S) j++;
            else break;
        }
        
        while (!dn.empty() && dn.top().second < j) dn.pop();
        if (i >= L && D[i-L] != non) dn.push(make_pair(-D[i-L],i-L+1));
        if (i - j + 1 < L || dn.empty()) D[i] = non;
        else D[i] = -dn.top().first + 1;
    }

    if (D[N] >= non) D[N] = -1;
    printf ("%d\n",D[N]);

    return 0;
}