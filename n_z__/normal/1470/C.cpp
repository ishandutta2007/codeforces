#include<bits/stdc++.h>
using namespace std;
mt19937 mt(time(0));
main(){
    int n,k;
    cin>>n>>k;
    int v=k;
    int lst=0;
    while(v==k)cout<<"? "<<(lst=mt()%n)+1<<endl,cin>>v;
    while(v!=k)cout<<"? "<<(lst=(lst+(v<k?1:n-1))%n)+1<<endl,cin>>v;
    cout<<"! "<<lst+1<<endl;
}