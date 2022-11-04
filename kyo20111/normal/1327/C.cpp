#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, k;
queue<char> q;
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=2*k;i++) scanf("%*d %*d");

    for(int i=1;i<n;i++) q.push('U');
    for(int i=1;i<m;i++) q.push('L');
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++) q.push(i%2?'R':'L');
        if(i != n) q.push('D');
    }

    printf("%d\n",q.size());
    while(!q.empty()){
        printf("%c",q.front());
        q.pop();
    }
}