#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 510;
int n, a[N], cnt = 0, f[N], head[N], numE = 0;
struct Edge{
    int next, from, to;
}e[N * N];
void addEdge(int from, int to){
    e[++numE].next = head[from];
    e[numE].to = to;
    e[numE].from = from;
    head[from] = numE;
}
set<PII> s;
priority_queue<PII> q;
queue<int> list;
int main(){
    scanf("%d", &n);
    int last = -1, first = 0, res = 0;
    for(int i = 1; i <= n; i++){
        scanf("%d", a + i);
        if(a[i] >= 2) {
            if(last != -1) addEdge(i, last), addEdge(last, i), res++;
            last = i;
            if(!first) first = i;
            if(a[i] - 2 > 0) q.push(make_pair(a[i] - 2, i));
        }else{
            list.push(i);
        }
    }
    if(list.size()){
        addEdge(list.front(), first);
        addEdge(first, list.front());
        list.pop(); res++;
    }
        
    if(list.size()){
        addEdge(list.front(), last);
        addEdge(last, list.front());
        list.pop(); res++;
    }
        
    while(!list.empty()){
        int u = list.front(); list.pop();
        if(q.empty()) { puts("NO"); return 0; } 
        else{
            PII t = q.top(); q.pop();
            addEdge(u, t.second);
            addEdge(t.second, u);
            if(t.first > 1) q.push(make_pair(t.first - 1, t.second));
        }
    }
    printf("YES %d\n%d\n", res, numE >> 1);
    for(int i = 1; i <= numE; i += 2){
        printf("%d %d\n", e[i].from, e[i].to);
    }
    return 0;
}