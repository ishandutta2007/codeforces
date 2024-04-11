#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x;string s;scanf("%d",&x);
	for(int i=1;i<=x;i++) cin>>s;
	return x; 
}
int main(){
	while(1){
		cout<<"next 0"<<endl;read();
		cout<<"next 0 1"<<endl;
		if(read()==2) break;
	}
	while(1){
		cout<<"next 0 1 2 3 4 5 6 7 8 9"<<endl;
		if(read()==1) break; 
	}
	cout<<"done"<<endl;
	return 0;
}