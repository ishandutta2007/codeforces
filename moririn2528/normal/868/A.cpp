#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n;
	int i,j,k;
	char cs[3];
	char ca[3];
	bool word[2][30];
	bool s=false;
	memset(word,false,sizeof(word));
	cin>>cs;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>ca;
		if(strcmp(cs,ca)==0)s=true;
		for(j=0;j<2;j++){
			k=(int)ca[j]-(int)'a';
			word[j][k]=true;
		}
	}
	i=(int)cs[0]-(int)'a';
	j=(int)cs[1]-(int)'a';
	if(word[1][i] && word[0][j])s=true;
	if(s)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}