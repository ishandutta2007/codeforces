#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int main(){
    cin>>n>>m;
    if(n>m)
        swap(n,m);
    switch(n){
        case 1:x=m/3+(m%3>0);break;
        case 2:x=m/2+1;break;
        case 3:x=m-(m-1)/4;break;
        case 4:x=(m+1)-(m==4||m==7||m==8||m==10);break;
        case 5:x=7*(m==5)+8*(m==6)+9*(m==7)+11*(m==8);break;
        case 6:x=10;break;
    }
    cout<<n*m-x<<"\n";
}