#include <bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	int a=0,d=0;
	for(int i=0;i<N;i++){
		char c;
		cin>>c;
		if(c=='A')a++;
		else d++;
	}
	if(a>d)cout<<"Anton\n";
	else if(a<d)cout<<"Danik\n";
	else cout<<"Friendship\n";
}