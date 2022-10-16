#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    if(min(n,m)==0)
    if(m>n)cout<<"0 1\n0 "<<m<<"\n0 0\n0 "<<m-1<<endl;
    else cout<<"1 0\n"<<n<<" 0\n0 0\n"<<n-1<<" 0"<<endl;
    else if(2*sqrt((min(n,m)-1)*(min(n,m)-1)+max(n,m)*max(n,m))>max(n,m)+sqrt(min(n,m)*min(n,m)+max(n,m)*max(n,m)))
    if(m>n)cout<<"1 0\n"<<n<<" "<<m<<"\n0 0\n"<<n-1<<" "<<m<<endl;
    else cout<<"0 1\n"<<n<<" "<<m<<"\n0 0\n"<<n<<" "<<m-1<<endl;
    else if(m>n) cout<<"0 0\n"<<n<<" "<<m<<endl<<n<<" 0\n0 "<<m<<endl;
    else cout<<"0 0\n"<<n<<" "<<m<<"\n0 "<<m<<endl<<n<<" 0"<<endl;
}