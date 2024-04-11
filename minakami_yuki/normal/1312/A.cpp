#include<iostream>
#include<cstdio>
using namespace std;
const int N=1000;
int n,m;
int main(){
int t;scanf("%d",&t);
while(t--){
scanf("%d%d",&n,&m);
if(n%m==0) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
return 0;
}