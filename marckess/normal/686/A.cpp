#include<iostream>
using namespace std;

int main(){
	int n;
	long long int x;
	int kid=0;
	char c;
	cin>>n>>x;
	while(n-->0){
		long long int aux;
		cin>>c>>aux;
		if(c=='+')
			x+=aux;
		else{
			if(aux>x)
				kid++;
			else
				x-=aux;	
		}
	} 
	cout<<x<<" "<<kid;
}