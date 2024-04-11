#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,a[maxn],sum;
priority_queue<int> q;
priority_queue<int,vector<int>,greater<int>> p;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
        int ct=0;
    for(int i=1;i<=n;i++){
        if(sum+a[i]<=m){
            sum+=a[i];
            q.push(a[i]);
            printf("%d ",i-(int)q.size());
        }
        else{
            while(sum+a[i]>m&&!q.empty()){
                sum-=q.top();
                p.push(q.top());
                q.pop();
            }
            p.push(a[i]);
            printf("%d ",i-(int)q.size()-1);
            while(!p.empty()){
                if(p.top()+sum<=m){
                    q.push(p.top());
                    sum+=p.top();
                    p.pop();
                }
                else{
                    break;
                }
            }
        }
    }
}
/*
    Good Luck
         -Lucina
*/