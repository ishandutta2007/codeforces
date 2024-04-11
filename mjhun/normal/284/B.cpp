#include <iostream>
using namespace std;

int main(){
	char c;
	int na=0,ni=0,m;
	cin>>m;
	while(m--){
		cin>>c;
		switch(c){
			case 'A':
				++na;
				break;
			case 'I':
				++ni;
				break;
		}
	}
	if(ni>1)
		m=0;
	else if(ni==1)
		m=1;
	else
		m=na;
		
	cout<<m<<endl;
	return 0;
}