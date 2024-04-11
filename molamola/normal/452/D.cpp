#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<queue>
using namespace std;

#define X first
#define Y second
typedef long long ll;
typedef pair<int,int> Pi;
int k,a,b,c,x,y,z;
int t[10010];
priority_queue <int,vector<int>,greater<int> >pq;
int main()
{
    scanf("%d%d%d%d%d%d%d",&k,&a,&b,&c,&x,&y,&z);
    int i;
    for(i=0;i<a;i++)pq.push(0);
    for(i=0;i<k;i++){
        int p = pq.top();pq.pop();
        int q = t[i];
        if(p < q)t[i] = q+x, pq.push(q+x);
        else t[i] = p+x, pq.push(p+x);
    }
    for(i=0;i<a;i++)pq.pop();
    for(i=0;i<b;i++)pq.push(0);
    for(i=0;i<k;i++){
        int p = pq.top();pq.pop();
        int q = t[i];
        if(p < q)t[i] = q+y, pq.push(q+y);
        else t[i] = p+y, pq.push(p+y);
    }
    for(i=0;i<b;i++)pq.pop();
    for(i=0;i<c;i++)pq.push(0);
    for(i=0;i<k;i++){
        int p = pq.top();pq.pop();
        int q = t[i];
        if(p < q)t[i] = q+z, pq.push(q+z);
        else t[i] = p+z, pq.push(p+z);
    }
    for(i=0;i<c;i++)pq.pop();
    printf("%d",t[k-1]);
    return 0;
}