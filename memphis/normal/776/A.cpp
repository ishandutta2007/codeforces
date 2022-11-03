#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<iostream>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
using namespace std;
const int N=100005;

string a,b,x,y;
int n;

int main(){
    cin>>a>>b;
    cin>>n;
    cout<<a<<" "<<b<<endl;
    while(n--){
        cin>>x>>y;
        if(x==a) a=y;
        else b=y;
        cout<<a<<" "<<b<<endl;
    }
}