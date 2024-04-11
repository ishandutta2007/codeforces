#include<iostream>
#include<cstring>
using namespace std;
int check(char ca){
	if(ca=='a' || ca=='e' || ca=='i' || ca=='o' || ca=='u')return 1;
	return 0;
}

int main(){
	char ca[2][1005];
	bool s=true;
	int i,j,k;
	cin>>ca[0]>>ca[1];
	if(strlen(ca[0])!=strlen(ca[1]))s=false;
	for(i=0;i<strlen(ca[0]);i++){
		if(check(ca[0][i])!=check(ca[1][i])){s=false;break;}
	}
	if(s)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}