#include<bits/stdc++.h>
using namespace std;
void pre(){}
void solve(){
    long long int a,b,c,d;cin>>a>>b>>c>>d;
    long long int x,y,x1,y1,x2,y2;cin>>x>>y>>x1>>y1>>x2>>y2;
    long long int sx = b-a;
    long long int sy = d-c;
    if(sx>0 && x2-x<sx){
        cout<<"No"<<"\n";
        return;
    }else if(sx<0 && x-x1<-1*sx){
        cout<<"No"<<"\n";
        return;
    }else if(sx==0 && x1==x2 && b!=0){
        cout<<"No"<<"\n";
        return;
    }
    sx=sy;
    x1=y1;
    x2=y2;
    x=y;
    if(sx>0 && x2-x<sx){
        cout<<"No"<<"\n";
        return;
    }else if(sx<0 && x-x1<-1*sx){
        cout<<"No"<<"\n";
        return;
    }else if(sx==0 && x1==x2 && d!=0){
        cout<<"No"<<"\n";
        return;
    }
    cout<<"Yes"<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    long long int num = 1;
    cin>>num;
    for(long long int i=0;i<num;i++){
       	solve();
    }   
}