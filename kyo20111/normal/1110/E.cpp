#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,c[101010],t[101010];
priority_queue<int> p1,p2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++) scanf("%d",&t[i]);
    if(c[1] != t[1] || c[n] != t[n]) return !printf("No");
    for(int i=1;i<n;i++) p1.push(c[i+1]-c[i]);
    for(int i=1;i<n;i++) p2.push(t[i+1]-t[i]);
    while(!p1.empty()){
        if(p1.top() != p2.top()) return !printf("No");
        p1.pop(),p2.pop();
    }
    printf("Yes");
}