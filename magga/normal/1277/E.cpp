#include<bits/stdc++.h>
using namespace std;    
void solve(){
    long long int n,m,a,b,d1,d2,d;
    cin>>n>>m>>a>>b;
    a--;b--;
    vector<long long int>arr[n];
    bool flag[n];
    for(long long int i=0;i<n;i++){flag[i]=false;}
    for(long long int i=0;i<m;i++){
        cin>>d1>>d2;
        d1--;
        d2--;
        arr[d2].push_back(d1);
        arr[d1].push_back(d2);
    }
    queue<long long int>q;
    flag[a]=true;
    q.push(b);
    while(q.size()!=0){
        d = q.front();
        q.pop();
        if(!flag[d]){
            flag[d]=true;
            for(long long int i:arr[d]){
                q.push(i);
            }
        }
    }
    //flag[a]=false;
    d1=0;
    for(long long int i=0;i<n;i++){
        if(!flag[i]){
            d1++;
        }
        flag[i]=false;
    }
    flag[b]=true;
    q.push(a);
    while(q.size()!=0){
        d = q.front();
        q.pop();
        if(!flag[d]){
            flag[d]=true;
            for(long long int i:arr[d]){
                q.push(i);
            }
        }
    }
    //flag[b]=false;
    d2=0;
    for(long long int i=0;i<n;i++){
        if(!flag[i]){
            d2++;
        }
        flag[i]=false;
    }
    cout<<d1*d2<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}