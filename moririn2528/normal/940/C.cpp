#include<iostream>
using namespace std;
char ca[100005];
bool can[30];
int main(){
	int n,m;
	int i,j,k;
	int a,b,c,d;
	cin>>n>>m;
	cin>>ca;
	for(i=0,b=0;i<n;i++){
		a=(int)ca[i]-(int)'a';
		can[a]=true;
		if(a>b)b=a;
	}
	for(i=n-1;i>=0;i--){
		if(n<m){
			b=n;break;
		}
		a=(int)ca[i]-(int)'a';
		if(a==b || i>=m)continue;
		for(j=a+1;j<26;j++){
			if(!can[j])continue;
			ca[i]=(char)((int)'a'+j);
			b=i+1;
			break;
		}
		break;
	}
	for(i=0;i<26;i++){
		if(!can[i])continue;
		for(j=b;j<m;j++){
			ca[j]=(char)((int)'a'+i);
		}
		break;
	}
	ca[m]='\0';
	cout<<ca<<endl;
	return 0;
}