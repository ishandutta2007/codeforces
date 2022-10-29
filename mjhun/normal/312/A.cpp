#include <iostream>
#include <string>
using namespace std;

int main(){
	int n,l,a,b;
	string s;
	cin>>n;
	getline(cin,s);
	while(n--){
		s.clear();
		getline(cin, s);
		l=s.size();
		if(l<5){
			cout<<"OMG>.< I don't know!"<<endl;
			continue;
		}
		a=s.compare(0,5,"miao.");
		b=s.compare(l-5,5,"lala.");
		if((a==0&&b==0)||(a!=0&&b!=0))
			cout<<"OMG>.< I don't know!"<<endl;
		else if(a==0)
			cout<<"Rainbow's"<<endl;
		else
			cout<<"Freda's"<<endl;
	}
	return 0;
}