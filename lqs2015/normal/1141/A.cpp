#include <iostream>
using namespace std;

int s;

int main(){
    long long n,m;
    cin>>n>>m;   
    if (m%n!=0)
    {
    	cout<<-1<<endl;
    	return 0;
	}
    m/=n;    
    
    if(m==1) {cout<<0<<endl; return 0;}
    
    while(m%2==0){
        s++;
        m/=2;
    }
    
    while(m%3==0){
        s++;
        m/=3;
    }
    if (m!=1) cout<<-1<<endl;
    else cout<<s<<endl;
    return 0;
}