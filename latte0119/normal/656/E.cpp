#include<bits/stdc++.h>
using namespace std;

int N;
int dist[111][111];

int in(int i,int j){
    return (i!=N)?(cin>>dist[i][j],in(i+(j==N-1),(j+1)%N)):0;
}
int calc(int k,int i,int j){
    return (k!=N)?((i!=N)?(dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]),calc(k,i+(j==N-1),(j+1)%N)):calc(k+1,0,0)):0;
}

int get(int i,int j){
    return (i!=N)?(max(dist[i][j],get(i+(j==N-1),(j+1)%N))):0;
}

signed main(){
    cin>>N;
    in(0,0);
    calc(0,0,0);
    cout<<get(0,0)<<endl;
    return 0;
}