#include<bits/stdc++.h>
using namespace std;
int arr[100000]{0};
long long int ar[3][100000]{0};
int no(int a,int b){
    if(a==0 && b==1){
        return 2;
    }
    if(a==2 && b==1){
        return 0;
    }
    if(a==0 && b==2){
        return 1;
    }
    if(a==1 && b==0){
        return 2;
    }
    if(a==1 && b==2){
        return 0;
    }
    if(a==2 && b==0){
        return 1;
    }
    return -1;
}
long long int calculate(tuple <long long int,long long int,long long int,long long int,long long int> linked[], int a, int b,long long int n){
    long long int ret = 0;
    if(n==0){
        return ret;
    }else if(n==1){
        ret+=(ar[a][get<0>(linked[0])]);
        arr[0]=1;
        return ret;
    }else if(n==2){
        arr[0] = a;
        arr[1] = b;
        ret+=(ar[a][get<0>(linked[0])]);
        ret+=(ar[b][get<0>(linked[1])]);
        return ret;
    }
    arr[0] = a;
    arr[1] = b;
    ret+=(ar[a][get<0>(linked[0])]);
    ret+=(ar[b][get<0>(linked[1])]);
    for(long long int i=2;i<n;i++)
    {
        ret += ar [ no(arr[i-1],arr[i-2])] [get<0>(linked[i])] ;
        arr[i]=no(arr[i-1],arr[i-2]);
    }
    return ret;
}

void solve()
{
    long long int n;cin>>n;
    //long long int arr[3][n];
    vector<long long int>dum;
    vector<long long int>graph[n];
    for(long long int i=0;i<n;i++)  {cin>>ar[0][i];}
    for(long long int i=0;i<n;i++)  {cin>>ar[1][i];}
    for(long long int i=0;i<n;i++)  {cin>>ar[2][i];}
    for(long long int i=0;i<n;i++)  {graph[i]=dum;}
    long long int a,b;
    for(long long int i=0;i<n-1;i++){
        cin>>a>>b;
        a--;b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    long long int start=-1;
    for(long long int i=0;i<n;i++){
        if(graph[i].size()>2){
            cout<<-1<<"\n";
            return;
        }else if(graph[i].size()==1){
            start=i;
        }
    }
    tuple <long long int,long long int,long long int,long long int,long long int> linked[n];
    tuple<long long int,long long int,long long int,long long int,long long int>t;
    long long int next_big_thing = 0;
    for(long long int i=0;i<n;i++){
        if(i==0){
            t = make_tuple(start,ar[0][start],ar[1][start],ar[2][start],start);
            linked[0] = t;
        }
        else{
            for(long long int j:graph[start]){
                if(j != get<0>(linked[i-2])){
                    next_big_thing = j;
                }
                start = next_big_thing;
                t = make_tuple(start,ar[0][start],ar[1][start],ar[2][start],start);
                linked[i] = t;
            }
        }
    }
    int aas[n];int arr2[n];
    long long int max = 1000000000000000;
    long long int answer =calculate(linked,0,1,n);
     if(answer<max){
        max = answer;
        for(long long int i=0;i<n;i++){
        aas[i] = arr[i];
    }
    }
     answer =calculate(linked,0,2,n) ;
     if(answer<max){
        max = answer;
        for(long long int i=0;i<n;i++){
        aas[i] = arr[i];
    }
    }
     answer =calculate(linked,1,2,n) ;
     if(answer<max){
        max = answer;
        for(long long int i=0;i<n;i++){
        aas[i] = arr[i];
    }
    }
     answer =calculate(linked,1,0,n) ;
     if(answer<max){
        max = answer;
        for(long long int i=0;i<n;i++){
        aas[i] = arr[i];
    }
    }
     answer =calculate(linked,2,0,n) ;
     if(max>answer){
        max = answer;
        for(long long int i=0;i<n;i++){
        aas[i] = arr[i];
    }
    }
     answer =calculate(linked,2,1,n) ;
    if(answer<max){
        max = answer;
        for(long long int i=0;i<n;i++){
        aas[i] = arr[i];
    }
    }
    long long int opera[n];
    for(long long int i=0;i<n;i++){
        opera[get<4>(linked[i])]=aas[i];
    }
    cout<<max<<"\n";
    for(long long int i=0;i<n;i++){
        cout<<opera[i]+1<<" ";
    }
    cout<<endl;
    
}



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}