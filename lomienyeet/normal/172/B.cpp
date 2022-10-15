#include <bits/stdc++.h>
using namespace std;
int A,B,M,R,arr[100005];
int dfs(int x){
    if(arr[(x*A+B)%M]){
        return arr[x]-arr[(x*A+B)%M]+1;
    }
    arr[(x*A+B)%M]=arr[x]+1;
    return dfs((x*A+B)%M);
}
int main(){
    cin>>A>>B>>M>>R;
    arr[R]=1;
    cout<<dfs(R)<<"\n";
    return 0;
}