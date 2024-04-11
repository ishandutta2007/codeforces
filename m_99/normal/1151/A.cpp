#include <bits/stdc++.h>
using namespace std;

int get(char c,char s){
	char c2 = c;
	int x = 0;
	while(true){
		if(c==s)break;
		c++;
		if(c=='Z'+1)c='A';
		x++;
	}
	
	int y = 0;
	c = c2;
	while(true){
		if(c==s)break;
		c--;
		if(c=='A'-1)c='Z';
		y++;
	}
	return min(x,y);
}

int main(){
	int n;
	cin>>n;
	string s;
	cin>>s;
	
	int mini = 99999999;
	
	for(int i=0;i<n-3;i++){
		mini = min(get(s[i],'A')+get(s[i+1],'C')+get(s[i+2],'T')+get(s[i+3],'G'),mini);
	}
	
	cout<<mini<<endl;
	
		
	
	
	
	return 0;
}