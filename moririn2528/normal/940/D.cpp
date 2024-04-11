#include<iostream>
#include<cmath>
using namespace std;
int ta[100005];
char cb[100005];
bool tb[100005];
const int INF=1000000000;

int main(){
	int n;
	int i,j,k;
	int a,b,c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>ta[i];
	}
	cin>>cb;
	for(i=0;i<n;i++){
		if(cb[i]=='1')tb[i]=true;
	}
	a=-INF,b=INF;
	for(i=0;i<n-4;i++){
		if(tb[i] && tb[i+1] && tb[i+2] && tb[i+3] && !tb[i+4]){
			for(j=i;j<i+5;j++){
				b=min(b,ta[j]-1);
			}
		}
		if(!tb[i] && !tb[i+1] && !tb[i+2] && !tb[i+3] && tb[i+4]){
			for(j=i;j<i+5;j++){
				a=max(a,ta[j]+1);
			}
		}
	}
	cout<<a<<" "<<b<<endl;
}