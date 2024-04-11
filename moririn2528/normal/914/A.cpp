#include<iostream>
#include<cstring>
using namespace std;
bool good[1000006];
const int INF=1<<28;
int main(){
	int n;
	int i,j,k;
	int a,b,c;
	int s=-INF;
	memset(good,true,sizeof(good));
	for(i=0;i<=1000;i++){
		good[i*i]=false;
	}
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a;
		if(s<a && (a<0 || good[a]))s=a;
	}
	cout<<s<<endl;
	return 0;
}