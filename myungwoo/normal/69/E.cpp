#include <stdio.h>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

#define MAXN 100005

int N,K,seq[MAXN],list[MAXN],cnt[MAXN];
map <int,int> num;
priority_queue <int> que;

int main()
{
    int i;
    scanf("%d%d",&N,&K);
    for (i=1;i<=N;i++) scanf("%d",seq+i), list[i] = seq[i];
    sort(list+1,list+N+1);
    for (i=1;i<=N;i++) num[list[i]] = i;
    for (i=1;i<=N;i++) seq[i] = num[seq[i]];
    for (i=1;i<=N;i++){
        cnt[seq[i]]++;
        if (cnt[seq[i]] == 1) que.push(seq[i]);
        if (i < K) continue;
        while (!que.empty() && cnt[que.top()] != 1) que.pop();
        if (que.empty()) puts("Nothing");
        else printf("%d\n",list[que.top()]);
        cnt[seq[i-K+1]]--;
        if (cnt[seq[i-K+1]] == 1) que.push(seq[i-K+1]);
    }
}