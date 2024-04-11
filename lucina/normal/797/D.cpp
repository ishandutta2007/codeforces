#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,a[maxn],l[maxn],r[maxn],p[maxn],root;
set<int> s;
void dfs(int nod,int ma,int mi){
    if(a[nod]>=mi&&a[nod]<=ma){
        s.insert(a[nod]);
    }
    //let's see how BST work
    /*
    pseudo-code
        if (x < t.value)
        return find(t.left, x);
    else
        return find(t.right, x);

    *//*
    some node will be found if and only if
    max(left)<=a[nod] min(right)>=a[nod]
    */
    if(l[nod]>0&&a[l[nod]]){
        dfs(l[nod],min(ma,a[nod]),mi);
    }
    if(r[nod]>0){
        dfs(r[nod],ma,max(mi,a[nod]));
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        scanf("%d%d",&l[i],&r[i]);
        if(l[i]>0)p[l[i]]=i;
        if(r[i]>0)p[r[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(p[i]==0){
            root=i;
        }
    }
    dfs(root,(int)1e9+7,-1);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(s.find(a[i])!=s.end())
            ;
        else ans++;
    }
    printf("%d\n",ans);
}