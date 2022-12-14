#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<pair<int,int> > q;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,k;
    scanf("%d%d",&n,&k);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d",&x);
        sum += x;
        if (x >= k)
            q.push(make_pair(x,0));
    }
    for (; ! q.empty();) {
        int x = q.top().first,y = q.top().second;
        q.pop();
        sum -= k;
        x -= k;
        y++;
        if (x < k || y >= 3)
            continue;
        q.push(make_pair(x,y));
    }
    printf("%d\n",sum);
    return 0;
}